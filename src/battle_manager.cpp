#include "battle_manager.h"
#include "npc_visitor.h"
#include <cmath>
#include <algorithm>

BattleManager::BattleManager() : running(true), gameOver(false), rng(std::random_device{}()) {
    for (int i = 0; i < 50; ++i) {
        std::uniform_int_distribution<int> distX(0, 99);
        std::uniform_int_distribution<int> distY(0, 99);
        std::uniform_int_distribution<int> distType(0, 2);
        int x = distX(rng);
        int y = distY(rng);
        std::string type;
        switch (distType(rng)) {
            case 0: type = "Orc"; break;
            case 1: type = "Squirrel"; break;
            case 2: type = "Bear"; break;
        }
        std::string name = type + std::to_string(i);
        addNPC(NPCFactory::createNPC(type, name, x, y));
    }
}

void BattleManager::startGame() {
    movementThreadHandle = std::thread(&BattleManager::movementThread, this);
    battleThreadHandle = std::thread(&BattleManager::battleThread, this);
    mainThreadHandle = std::thread(&BattleManager::mainThread, this);
}

void BattleManager::stopGame() {
    running = false;
}

void BattleManager::joinThreads() {
    if (mainThreadHandle.joinable()) {
        mainThreadHandle.join();
    }
    if (movementThreadHandle.joinable()) {
        movementThreadHandle.join();
    }
    if (battleThreadHandle.joinable()) {
        battleThreadHandle.join();
    }
}

void BattleManager::addNPC(std::unique_ptr<NPC> npc) {
    std::lock_guard<std::shared_mutex> lock(npcMutex);
    if (npc->getX() < 0 || npc->getX() > 99 || npc->getY() < 0 || npc->getY() > 99) {
        throw std::out_of_range("NPC coordinates out of range");
    }
    for (const auto& existingNPC : npcs) {
        if (existingNPC->getName() == npc->getName()) {
            throw std::runtime_error("NPC name must be unique");
        }
    }
    npcs.push_back(std::move(npc));
}

void BattleManager::startBattle(int range) {
    ::startBattle(npcs, observers, range);
}

void BattleManager::addObserver(Observer* observer) {
    std::lock_guard<std::shared_mutex> lock(npcMutex);
    observers.push_back(observer);
}

const std::vector<std::unique_ptr<NPC>>& BattleManager::getNPCs() const {
    return npcs;
}

void BattleManager::printNPCs() const {
    std::lock_guard<std::shared_mutex> lock(npcMutex);
    for (const auto& npc : npcs) {
        std::cout << npc->getType() << " " << npc->getName() << " at (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
    }
}

void BattleManager::printMap() const {
    std::lock_guard<std::shared_mutex> lock(npcMutex);
    char map[100][100] = {};
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            map[i][j] = '.';
        }
    }
    for (const auto& npc : npcs) {
        if (npc->isAlive()) {
            map[npc->getX()][npc->getY()] = npc->getType()[0];
        }
    }
    std::lock_guard<std::mutex> coutLock(coutMutex);
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void BattleManager::movementThread() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::shared_lock<std::shared_mutex> lock(npcMutex);
        for (auto& npc : npcs) {
            if (npc->isAlive()) {
                moveNPC(*npc);
                for (auto& other : npcs) {
                    if (npc.get() != other.get() && other->isAlive() && isWithinRange(*npc, *other, npc->getKillRange())) {
                        std::thread battleThread([this, &npc, &other]() {
                            fightNPC(*npc, *other);
                        });
                        battleThread.detach();
                    }
                }
            }
        }
    }
}

void BattleManager::battleThread() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::shared_lock<std::shared_mutex> lock(npcMutex);
        for (auto& npc : npcs) {
            if (npc->isAlive()) {
                for (auto& other : npcs) {
                    if (npc.get() != other.get() && other->isAlive() && isWithinRange(*npc, *other, npc->getKillRange())) {
                        fightNPC(*npc, *other);
                    }
                }
            }
        }
    }
}

void BattleManager::mainThread() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        printMap();
    }
    gameOver = true;
    cv.notify_all();
}

void BattleManager::moveNPC(NPC& npc) {
    std::uniform_int_distribution<int> distX(0, 1);
    std::uniform_int_distribution<int> distY(0, 1);
    int dx = distX(rng) ? 1 : -1;
    int dy = distY(rng) ? 1 : -1;
    int newX = npc.getX() + dx * npc.getMoveRange();
    int newY = npc.getY() + dy * npc.getMoveRange();
    if (newX >= 0 && newX < 100 && newY >= 0 && newY < 100) {
        npc.setPosition(newX, newY);
    }
}

void BattleManager::fightNPC(NPC& npc1, NPC& npc2) {
    if (canKill(npc1, npc2)) {
        npc2.kill();
        std::string message = npc1.getName() + " killed " + npc2.getName();
        notifyObservers(message);
    } else if (canKill(npc2, npc1)) {
        npc1.kill();
        std::string message = npc2.getName() + " killed " + npc1.getName();
        notifyObservers(message);
    }
}

bool BattleManager::isWithinRange(const NPC& npc1, const NPC& npc2, int range) const {
    return std::sqrt(std::pow(npc1.getX() - npc2.getX(), 2) + std::pow(npc1.getY() - npc2.getY(), 2)) <= range;
}

bool BattleManager::canKill(const NPC& attacker, const NPC& defender) {
    std::uniform_int_distribution<int> dice(1, 6);
    int attack = dice(rng);
    int defense = dice(rng);
    return attack > defense;
}

void BattleManager::notifyObservers(const std::string& message) {
    for (auto& observer : observers) {
        observer->notify(message);
    }
}

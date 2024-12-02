#include "game_manager.h"
#include <iostream>
#include <chrono>
#include <random>
#include <coroutine>

GameManager::GameManager(BattleManager& battleManager) : battleManager(battleManager) {
    // Initialize NPCs
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(0, 99);
    std::uniform_int_distribution<> disY(0, 99);

    for (int i = 0; i < 50; ++i) {
        std::string type = (i % 3 == 0) ? "Orc" : (i % 3 == 1) ? "Squirrel" : "Bear";
        std::string name = type + std::to_string(i);
        int x = disX(gen);
        int y = disY(gen);
        battleManager.addNPC(NPCFactory::createNPC(type, name, x, y));
    }
}

void GameManager::startGame() {
    threads.emplace_back(&GameManager::movementThread, this);
    threads.emplace_back(&GameManager::battleThread, this);
    threads.emplace_back(&GameManager::printMapThread, this);

    for (auto& thread : threads) {
        thread.join();
    }
}

void GameManager::movementThread() {
    while (true) {
        std::shared_lock<std::shared_mutex> lock(mutex);
        for (auto& npc : battleManager.getNPCs()) {
            if (npc->isAlive()) {
                moveNPC(*npc);
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void GameManager::battleThread() {
    while (true) {
        std::shared_lock<std::shared_mutex> lock(mutex);
        for (auto& npc1 : battleManager.getNPCs()) {
            for (auto& npc2 : battleManager.getNPCs()) {
                if (npc1.get() != npc2.get() && npc1->isAlive() && npc2->isAlive() && npc1->canFight(*npc2)) {
                    battleNPC(*npc1, *npc2);
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void GameManager::printMapThread() {
    while (true) {
        std::shared_lock<std::shared_mutex> lock(mutex);
        std::lock_guard<std::mutex> coutLock(coutMutex);
        std::cout << "Map:" << std::endl;
        for (const auto& npc : battleManager.getNPCs()) {
            if (npc->isAlive()) {
                std::cout << npc->getName() << " (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void GameManager::moveNPC(NPC& npc) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-1, 1);
    int newX = npc.getX() + dis(gen);
    int newY = npc.getY() + dis(gen);
    if (newX >= 0 && newX <= 99 && newY >= 0 && newY <= 99) {
        npc.setX(newX);
        npc.setY(newY);
    }
}

void GameManager::battleNPC(NPC& npc1, NPC& npc2) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    int attack1 = dis(gen);
    int defense1 = dis(gen);
    int attack2 = dis(gen);
    int defense2 = dis(gen);

    if (attack1 > defense2) {
        npc2.kill();
        std::string message = npc1.getName() + " killed " + npc2.getName();
        for (auto& observer : observers) {
            observer->notify(message);
        }
    } else if (attack2 > defense1) {
        npc1.kill();
        std::string message = npc2.getName() + " killed " + npc1.getName();
        for (auto& observer : observers) {
            observer->notify(message);
        }
    }
}

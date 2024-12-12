#include "battle_manager.h"
#include "npc_visitor.h"
#include <cmath>

void BattleManager::addNPC(std::unique_ptr<NPC> npc) {
    if (npc->getX() < 0 || npc->getX() > 500 || npc->getY() < 0 || npc->getY() > 500) {
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
    observers.push_back(observer);
}

const std::vector<std::unique_ptr<NPC>>& BattleManager::getNPCs() const {
    return npcs;
}

void BattleManager::printNPCs() const {
    for (const auto& npc : npcs) {
        std::cout << npc->getType() << " " << npc->getName() << " at (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
    }
}

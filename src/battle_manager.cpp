#include "battle_manager.h"
#include "npc_visitor.h"
#include <cmath>

void BattleManager::addNPC(std::unique_ptr<NPC> npc) {
    npcs.push_back(std::move(npc));
}

void BattleManager::startBattle(int range) {
    for (auto& npc : npcs) {
        for (auto& other : npcs) {
            if (npc.get() != other.get() && npc->canFight(*other)) {
                double distance = std::sqrt(std::pow(npc->getX() - other->getX(), 2) + std::pow(npc->getY() - other->getY(), 2));
                if (distance <= range) {
                    if (npc->fight(*other)) {
                        std::string message = npc->getName() + " killed " + other->getName();
                        for (auto& observer : observers) {
                            observer->notify(message);
                        }
                        // Remove the defeated NPC
                        other.reset();
                    }
                }
            }
        }
    }
    // Remove defeated NPCs from the list
    npcs.erase(std::remove_if(npcs.begin(), npcs.end(), [](const std::unique_ptr<NPC>& npc) {
        return npc == nullptr;
    }), npcs.end());
}

void BattleManager::addObserver(Observer* observer) {
    observers.push_back(observer);
}

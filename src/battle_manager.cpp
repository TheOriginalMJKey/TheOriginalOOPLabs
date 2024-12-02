#include "battle_manager.h"
#include "npc_visitor.h"
#include <cmath>

void BattleManager::addNPC(std::unique_ptr<NPC> npc) {
    npcs.push_back(std::move(npc));
}

void BattleManager::startBattle(int range) {
    startBattle(npcs, observers, range);
}

void BattleManager::addObserver(Observer* observer) {
    observers.push_back(observer);
}

const std::vector<std::unique_ptr<NPC>>& BattleManager::getNPCs() const {
    return npcs;
}

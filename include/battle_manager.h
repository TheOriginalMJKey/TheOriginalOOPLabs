#ifndef BATTLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "npc.h"
#include "observer.h"
#include <vector>
#include <memory>
#include <mutex>
#include <shared_mutex>

class BattleManager {
public:
    void addNPC(std::unique_ptr<NPC> npc);
    void startBattle(int range);
    void addObserver(Observer* observer);
    const std::vector<std::unique_ptr<NPC>>& getNPCs() const { return npcs; }

private:
    std::vector<std::unique_ptr<NPC>> npcs;
    std::vector<Observer*> observers;
    mutable std::shared_mutex mutex;
};

#endif // BATTLE_MANAGER_H

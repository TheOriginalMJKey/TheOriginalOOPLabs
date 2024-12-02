#ifndef BATTLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "npc.h"
#include "observer.h"
#include <vector>
#include <memory>

class BattleManager {
public:
    void addNPC(std::unique_ptr<NPC> npc);
    void startBattle(int range);
    void addObserver(Observer* observer);

private:
    std::vector<std::unique_ptr<NPC>> npcs;
    std::vector<Observer*> observers;
};

#endif // BATTLE_MANAGER_H

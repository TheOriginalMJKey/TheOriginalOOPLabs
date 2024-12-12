#ifndef BATTLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "npc.h"
#include "observer.h"
#include <vector>
#include <memory>
#include <iostream>

class BattleManager {
public:
    void addNPC(std::unique_ptr<NPC> npc);
    void startBattle(int range);
    void addObserver(Observer* observer);
    const std::vector<std::unique_ptr<NPC>>& getNPCs() const;
    void printNPCs() const;

private:
    std::vector<std::unique_ptr<NPC>> npcs;
    std::vector<Observer*> observers;
};

void startBattle(std::vector<std::unique_ptr<NPC>>& npcs, std::vector<Observer*>& observers, int range);

#endif // BATTLE_MANAGER_H

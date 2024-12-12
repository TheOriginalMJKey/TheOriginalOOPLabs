#include "npc_factory.h"
#include "battle_manager.h"
#include "file_manager.h"
#include "observer.h"
#include <iostream>

int main() {
    BattleManager battleManager;
    FileObserver fileObserver;
    ConsoleObserver consoleObserver;

    battleManager.addObserver(&fileObserver);
    battleManager.addObserver(&consoleObserver);

    battleManager.addNPC(NPCFactory::createNPC("Orc", "Orc1", 100, 100));
    battleManager.addNPC(NPCFactory::createNPC("Squirrel", "Squirrel1", 200, 200));
    battleManager.addNPC(NPCFactory::createNPC("Bear", "Bear1", 300, 300));

    FileManager::saveNPCs(battleManager.getNPCs(), "npcs.txt");

    battleManager.startBattle(150);

    return 0;
}

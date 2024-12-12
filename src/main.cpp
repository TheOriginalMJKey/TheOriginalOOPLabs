#include "battle_manager.h"
#include "npc_factory.h"
#include "file_manager.h"
#include "observer.h"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    BattleManager battleManager;
    FileObserver fileObserver;
    ConsoleObserver consoleObserver;

    battleManager.addObserver(&fileObserver);
    battleManager.addObserver(&consoleObserver);

    battleManager.startGame();

    std::this_thread::sleep_for(std::chrono::seconds(30));
    battleManager.stopGame();
    battleManager.joinThreads();

    battleManager.printNPCs();

    return 0;
}

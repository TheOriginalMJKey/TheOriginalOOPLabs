#include "battle_manager.h"
#include "game_manager.h"
#include "observer.h"
#include <iostream>
#include <thread>

int main() {
    BattleManager battleManager;
    FileObserver fileObserver;
    ConsoleObserver consoleObserver;

    battleManager.addObserver(&fileObserver);
    battleManager.addObserver(&consoleObserver);

    GameManager gameManager(battleManager);
    gameManager.startGame();

    std::this_thread::sleep_for(std::chrono::seconds(30));

    std::lock_guard<std::shared_mutex> lock(gameManager.mutex);
    std::cout << "Survivors:" << std::endl;
    for (const auto& npc : battleManager.getNPCs()) {
        if (npc->isAlive()) {
            std::cout << npc->getName() << " (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
        }
    }

    return 0;
}

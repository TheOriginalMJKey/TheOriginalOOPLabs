#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "battle_manager.h"
#include <thread>
#include <vector>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <coroutine>

class GameManager {
public:
    GameManager(BattleManager& battleManager);
    void startGame();

private:
    void movementThread();
    void battleThread();
    void printMapThread();
    void moveNPC(NPC& npc);
    void battleNPC(NPC& npc1, NPC& npc2);
    std::vector<std::thread> threads;
    BattleManager& battleManager;
    std::shared_mutex mutex;
    std::mutex coutMutex;
    std::vector<std::unique_ptr<NPC>> npcs;
    std::vector<Observer*> observers;
};

#endif // GAME_MANAGER_H

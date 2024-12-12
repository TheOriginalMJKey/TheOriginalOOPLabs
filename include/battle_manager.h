#ifndef BATTLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "npc.h"
#include "observer.h"
#include "npc_factory.h"
#include <vector>
#include <memory>
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>
#include <random>

class BattleManager {
public:
    BattleManager();
    void startGame();
    void addNPC(std::unique_ptr<NPC> npc);
    void startBattle(int range);
    void addObserver(Observer* observer);
    const std::vector<std::unique_ptr<NPC>>& getNPCs() const;
    void printNPCs() const;
    void printMap() const;

    void stopGame();
    void joinThreads();

private:
    void movementThread();
    void battleThread();
    void mainThread();
    void moveNPC(NPC& npc);
    void fightNPC(NPC& npc1, NPC& npc2);
    bool isWithinRange(const NPC& npc1, const NPC& npc2, int range) const;
    bool canKill(const NPC& attacker, const NPC& defender);
    void notifyObservers(const std::string& message);

    std::vector<std::unique_ptr<NPC>> npcs;
    std::vector<Observer*> observers;
    mutable std::shared_mutex npcMutex;
    mutable std::mutex coutMutex;
    std::condition_variable cv;
    std::atomic<bool> running;
    std::atomic<bool> gameOver;
    std::thread movementThreadHandle;
    std::thread battleThreadHandle;
    std::thread mainThreadHandle;
    std::mt19937 rng; // Removed const
};

void startBattle(std::vector<std::unique_ptr<NPC>>& npcs, std::vector<Observer*>& observers, int range);

#endif // BATTLE_MANAGER_H

#ifndef GAME_H
#define GAME_H

#include "npc.h"
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <iostream>

class Game {
public:
    Game(int map_size, int duration);
    void start();

private:
    void movementThread();
    void battleThread();
    void printMapThread();
    void generateNPCLocations();
    void printMap();

    std::vector<NPC> npcs;
    int map_size;
    int duration;
    std::mutex cout_mutex;
    std::condition_variable cv;
    bool stop;
};

#endif // GAME_H

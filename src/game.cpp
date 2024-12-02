#include "game.h"

Game::Game(int map_size, int duration) : map_size(map_size), duration(duration), stop(false) {
    generateNPCLocations();
}

void Game::start() {
    std::thread movement_thread(&Game::movementThread, this);
    std::thread battle_thread(&Game::battleThread, this);
    std::thread print_thread(&Game::printMapThread, this);

    std::this_thread::sleep_for(std::chrono::seconds(duration));
    stop = true;
    cv.notify_all();

    if (movement_thread.joinable()) movement_thread.join();
    if (battle_thread.joinable()) battle_thread.join();
    if (print_thread.joinable()) print_thread.join();

    printMap();
}

void Game::movementThread() {
    while (!stop) {
        std::unique_lock<std::mutex> lock(cv.mutex);
        cv.wait(lock, [this] { return stop; });

        for (auto& npc : npcs) {
            if (npc.isAlive()) {
                npc.move(map_size);
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Game::battleThread() {
    while (!stop) {
        std::unique_lock<std::mutex> lock(cv.mutex);
        cv.wait(lock, [this] { return stop; });

        for (size_t i = 0; i < npcs.size(); ++i) {
            for (size_t j = i + 1; j < npcs.size(); ++j) {
                if (npcs[i].isAlive() && npcs[j].isAlive() && npcs[i].canKill(npcs[j])) {
                    if (npcs[i].fight(npcs[j]) || npcs[j].fight(npcs[i])) {
                        // One of them is dead
                    }
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Game::printMapThread() {
    while (!stop) {
        std::unique_lock<std::mutex> lock(cv.mutex);
        cv.wait(lock, [this] { return stop; });

        printMap();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Game::generateNPCLocations() {
    std::uniform_int_distribution<int> dist(0, map_size);
    npcs.reserve(50);
    for (int i = 0; i < 50; ++i) {
        int x = dist(NPC::rng);
        int y = dist(NPC::rng);
        npcs.emplace_back("NPC" + std::to_string(i), x, y, 10, 5); // Example values
    }
}

void Game::printMap() {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Map state:\n";
    for (const auto& npc : npcs) {
        if (npc.isAlive()) {
            std::cout << npc.getName() << " at (" << npc.getX() << ", " << npc.getY() << ")\n";
        }
    }
    std::cout << "\n";
}

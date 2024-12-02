#ifndef NPC_H
#define NPC_H

#include <string>
#include <mutex>
#include <shared_mutex>
#include <random>
#include <coroutine>

class NPC {
public:
    NPC(const std::string& name, int x, int y, int cold_distance, int kill_distance)
        : name(name), x(x), y(y), cold_distance(cold_distance), kill_distance(kill_distance), alive(true) {}

    std::string getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }
    bool isAlive() const { return alive; }

    void move(int map_size);
    bool canKill(const NPC& other) const;
    bool fight(NPC& other);
    void kill() { alive = false; }

private:
    std::string name;
    int x, y;
    int cold_distance;
    int kill_distance;
    bool alive;

    static std::shared_mutex movement_mutex;
    static std::mt19937 rng;
};

#endif // NPC_H

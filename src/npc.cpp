#include "npc.h"

std::shared_mutex NPC::movement_mutex;
std::mt19937 NPC::rng(std::random_device{}());

void NPC::move(int map_size) {
    std::unique_lock<std::shared_mutex> lock(movement_mutex);
    if (!alive) return;

    std::uniform_int_distribution<int> dist(0, 3); // Move randomly by 0, 1, 2, or 3 units
    int dx = dist(rng) - 1; // -1, 0, 1, or 2
    int dy = dist(rng) - 1; // -1, 0, 1, or 2

    x = std::max(0, std::min(map_size, x + dx));
    y = std::max(0, std::min(map_size, y + dy));
}

bool NPC::canKill(const NPC& other) const {
    int dx = x - other.x;
    int dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy) <= kill_distance;
}

bool NPC::fight(NPC& other) {
    std::uniform_int_distribution<int> dice(1, 6);
    int attack = dice(rng);
    int defense = dice(rng);

    if (attack > defense) {
        other.kill();
        return true;
    }
    return false;
}

#include "npc_visitor.h"
#include "npc.h"
#include "observer.h"
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

class BattleVisitor : public NPCVisitor {
public:
    BattleVisitor(std::vector<std::unique_ptr<NPC>>& npcs, std::vector<Observer*>& observers, int range)
        : npcs(npcs), observers(observers), range(range) {}

    void visit(Orc& orc) override {
        for (auto& other : npcs) {
            if (&orc != other.get() && orc.canFight(*other)) {
                double distance = std::sqrt(std::pow(orc.getX() - other->getX(), 2) + std::pow(orc.getY() - other->getY(), 2));
                if (distance <= range) {
                    if (orc.fight(*other)) {
                        std::string message = orc.getName() + " killed " + other->getName();
                        notifyObservers(message);
                        other.reset();
                    }
                }
            }
        }
    }

    void visit(Squirrel& squirrel) override {
        // Squirrels do not want to fight
    }

    void visit(Bear& bear) override {
        for (auto& other : npcs) {
            if (&bear != other.get() && bear.canFight(*other)) {
                double distance = std::sqrt(std::pow(bear.getX() - other->getX(), 2) + std::pow(bear.getY() - other->getY(), 2));
                if (distance <= range) {
                    if (bear.fight(*other)) {
                        std::string message = bear.getName() + " killed " + other->getName();
                        notifyObservers(message);
                        other.reset();
                    }
                }
            }
        }
    }

private:
    void notifyObservers(const std::string& message) {
        for (auto& observer : observers) {
            observer->notify(message);
        }
    }

    std::vector<std::unique_ptr<NPC>>& npcs;
    std::vector<Observer*>& observers;
    int range;
};

// Define the global startBattle function
void startBattle(std::vector<std::unique_ptr<NPC>>& npcs, std::vector<Observer*>& observers, int range) {
    BattleVisitor visitor(npcs, observers, range);
    for (auto& npc : npcs) {
        npc->accept(visitor);
    }
    // Remove defeated NPCs from the list
    npcs.erase(std::remove_if(npcs.begin(), npcs.end(), [](const std::unique_ptr<NPC>& npc) {
        return npc == nullptr;
    }), npcs.end());
}

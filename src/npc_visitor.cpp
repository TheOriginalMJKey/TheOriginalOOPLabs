#include "npc_visitor.h"
#include "npc.h"

class BattleVisitor : public NPCVisitor {
public:
    void visit(Orc& orc) override {
        // Implement battle logic for Orc
    }

    void visit(Squirrel& squirrel) override {
        // Implement battle logic for Squirrel
    }

    void visit(Bear& bear) override {
        // Implement battle logic for Bear
    }
};

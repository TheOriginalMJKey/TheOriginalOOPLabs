#include "npc.h"
#include "npc_visitor.h"
#include <cmath>

void Orc::accept(NPCVisitor& visitor) {
    visitor.visit(*this);
}

bool Orc::canFight(const NPC& other) const {
    return other.getType() == "Orc" || other.getType() == "Bear";
}

bool Orc::fight(NPC& other) {
    if (other.getType() == "Orc") {
        return true;
    } else if (other.getType() == "Bear") {
        return true;
    }
    return false;
}

void Squirrel::accept(NPCVisitor& visitor) {
    visitor.visit(*this);
}

bool Squirrel::canFight(const NPC& other) const {
    return false;
}

bool Squirrel::fight(NPC& other) {
    return false;
}

void Bear::accept(NPCVisitor& visitor) {
    visitor.visit(*this);
}

bool Bear::canFight(const NPC& other) const {
    return other.getType() == "Squirrel";
}

bool Bear::fight(NPC& other) {
    if (other.getType() == "Squirrel") {
        return true;
    }
    return false;
}

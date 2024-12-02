#include "npc_factory.h"
#include "npc.h"

std::unique_ptr<NPC> NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Orc") {
        return std::make_unique<Orc>(name, x, y);
    } else if (type == "Squirrel") {
        return std::make_unique<Squirrel>(name, x, y);
    } else if (type == "Bear") {
        return std::make_unique<Bear>(name, x, y);
    }
    return nullptr;
}

#include "file_manager.h"
#include "npc_factory.h"
#include <fstream>
#include <sstream>

void FileManager::saveNPCs(const std::vector<std::unique_ptr<NPC>>& npcs, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& npc : npcs) {
            file << npc->getType() << " " << npc->getName() << " " << npc->getX() << " " << npc->getY() << std::endl;
        }
        file.close();
    }
}

std::vector<std::unique_ptr<NPC>> FileManager::loadNPCs(const std::string& filename) {
    std::vector<std::unique_ptr<NPC>> npcs;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type, name;
            int x, y;
            if (iss >> type >> name >> x >> y) {
                npcs.push_back(NPCFactory::createNPC(type, name, x, y));
            }
        }
        file.close();
    }
    return npcs;
}

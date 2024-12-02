#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "npc.h"
#include <vector>
#include <memory>

class FileManager {
public:
    static void saveNPCs(const std::vector<std::unique_ptr<NPC>>& npcs, const std::string& filename);
    static std::vector<std::unique_ptr<NPC>> loadNPCs(const std::string& filename);
};

#endif // FILE_MANAGER_H

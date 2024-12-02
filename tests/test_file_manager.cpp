#include <gtest/gtest.h>
#include "file_manager.h"
#include "npc_factory.h"
#include <fstream>
#include <sstream>

TEST(FileManagerTest, SaveAndLoadNPCs) {
    std::vector<std::unique_ptr<NPC>> npcs;
    npcs.push_back(NPCFactory::createNPC("Orc", "Orc1", 100, 100));
    npcs.push_back(NPCFactory::createNPC("Squirrel", "Squirrel1", 200, 200));
    npcs.push_back(NPCFactory::createNPC("Bear", "Bear1", 300, 300));

    FileManager::saveNPCs(npcs, "test_npcs.txt");

    auto loadedNPCs = FileManager::loadNPCs("test_npcs.txt");
    ASSERT_EQ(loadedNPCs.size(), 3);
    ASSERT_EQ(loadedNPCs[0]->getName(), "Orc1");
    ASSERT_EQ(loadedNPCs[1]->getName(), "Squirrel1");
    ASSERT_EQ(loadedNPCs[2]->getName(), "Bear1");
}

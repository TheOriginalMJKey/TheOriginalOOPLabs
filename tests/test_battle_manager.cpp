#include <gtest/gtest.h>
#include "battle_manager.h"
#include "npc_factory.h"

TEST(BattleManagerTest, AddNPC) {
    BattleManager battleManager;
    battleManager.addNPC(NPCFactory::createNPC("Orc", "Orc1", 100, 100));
    battleManager.addNPC(NPCFactory::createNPC("Squirrel", "Squirrel1", 200, 200));
    battleManager.addNPC(NPCFactory::createNPC("Bear", "Bear1", 300, 300));

    ASSERT_EQ(battleManager.getNPCs().size(), 3);
}

TEST(BattleManagerTest, StartBattle) {
    BattleManager battleManager;
    battleManager.addNPC(NPCFactory::createNPC("Orc", "Orc1", 100, 100));
    battleManager.addNPC(NPCFactory::createNPC("Orc", "Orc2", 150, 150));
    battleManager.addNPC(NPCFactory::createNPC("Bear", "Bear1", 200, 200));

    battleManager.startBattle(100);

    ASSERT_EQ(battleManager.getNPCs().size(), 1);
    ASSERT_EQ(battleManager.getNPCs()[0]->getName(), "Bear1");
}

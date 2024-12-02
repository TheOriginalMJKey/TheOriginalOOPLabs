#include <gtest/gtest.h>
#include "npc.h"
#include "npc_factory.h"

TEST(NPCFactoryTest, CreateOrc) {
    auto orc = NPCFactory::createNPC("Orc", "Orc1", 100, 100);
    ASSERT_EQ(orc->getType(), "Orc");
    ASSERT_EQ(orc->getName(), "Orc1");
    ASSERT_EQ(orc->getX(), 100);
    ASSERT_EQ(orc->getY(), 100);
}

TEST(NPCFactoryTest, CreateSquirrel) {
    auto squirrel = NPCFactory::createNPC("Squirrel", "Squirrel1", 200, 200);
    ASSERT_EQ(squirrel->getType(), "Squirrel");
    ASSERT_EQ(squirrel->getName(), "Squirrel1");
    ASSERT_EQ(squirrel->getX(), 200);
    ASSERT_EQ(squirrel->getY(), 200);
}

TEST(NPCFactoryTest, CreateBear) {
    auto bear = NPCFactory::createNPC("Bear", "Bear1", 300, 300);
    ASSERT_EQ(bear->getType(), "Bear");
    ASSERT_EQ(bear->getName(), "Bear1");
    ASSERT_EQ(bear->getX(), 300);
    ASSERT_EQ(bear->getY(), 300);
}
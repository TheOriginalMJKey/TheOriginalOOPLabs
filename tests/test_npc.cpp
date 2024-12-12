#include <gtest/gtest.h>
#include "npc.h"
#include "npc_visitor.h"

class MockVisitor : public NPCVisitor {
public:
    void visit(Orc& orc) override {
        visitedOrc = true;
    }

    void visit(Squirrel& squirrel) override {
        visitedSquirrel = true;
    }

    void visit(Bear& bear) override {
        visitedBear = true;
    }

    bool visitedOrc = false;
    bool visitedSquirrel = false;
    bool visitedBear = false;
};

TEST(NPCVisitorTest, VisitOrc) {
    MockVisitor visitor;
    Orc orc("Orc1", 100, 100);
    orc.accept(visitor);
    ASSERT_TRUE(visitor.visitedOrc);
    ASSERT_FALSE(visitor.visitedSquirrel);
    ASSERT_FALSE(visitor.visitedBear);
}

TEST(NPCVisitorTest, VisitSquirrel) {
    MockVisitor visitor;
    Squirrel squirrel("Squirrel1", 200, 200);
    squirrel.accept(visitor);
    ASSERT_FALSE(visitor.visitedOrc);
    ASSERT_TRUE(visitor.visitedSquirrel);
    ASSERT_FALSE(visitor.visitedBear);
}

TEST(NPCVisitorTest, VisitBear) {
    MockVisitor visitor;
    Bear bear("Bear1", 300, 300);
    bear.accept(visitor);
    ASSERT_FALSE(visitor.visitedOrc);
    ASSERT_FALSE(visitor.visitedSquirrel);
    ASSERT_TRUE(visitor.visitedBear);
}

#ifndef NPC_VISITOR_H
#define NPC_VISITOR_H

class NPC;
class Orc;
class Squirrel;
class Bear;

class NPCVisitor {
public:
    virtual ~NPCVisitor() = default;
    virtual void visit(Orc& orc) = 0;
    virtual void visit(Squirrel& squirrel) = 0;
    virtual void visit(Bear& bear) = 0;
};

#endif // NPC_VISITOR_H

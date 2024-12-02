#ifndef NPC_H
#define NPC_H

#include <string>

class NPC {
public:
    virtual ~NPC() = default;
    virtual std::string getType() const = 0;
    virtual void accept(class NPCVisitor& visitor) = 0;
    virtual bool canFight(const NPC& other) const = 0;
    virtual bool fight(NPC& other) = 0;
    std::string getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }

protected:
    NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}

private:
    std::string name;
    int x, y;
};

class Orc : public NPC {
public:
    Orc(const std::string& name, int x, int y) : NPC(name, x, y) {}
    std::string getType() const override { return "Orc"; }
    void accept(NPCVisitor& visitor) override;
    bool canFight(const NPC& other) const override;
    bool fight(NPC& other) override;
};

class Squirrel : public NPC {
public:
    Squirrel(const std::string& name, int x, int y) : NPC(name, x, y) {}
    std::string getType() const override { return "Squirrel"; }
    void accept(NPCVisitor& visitor) override;
    bool canFight(const NPC& other) const override;
    bool fight(NPC& other) override;
};

class Bear : public NPC {
public:
    Bear(const std::string& name, int x, int y) : NPC(name, x, y) {}
    std::string getType() const override { return "Bear"; }
    void accept(NPCVisitor& visitor) override;
    bool canFight(const NPC& other) const override;
    bool fight(NPC& other) override;
};

#endif // NPC_H

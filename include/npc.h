#ifndef NPC_H
#define NPC_H

#include <string>
#include <atomic>

class NPC {
public:
    virtual ~NPC() = default;
    virtual std::string getType() const = 0;
    virtual void accept(class NPCVisitor& visitor) = 0;
    virtual bool canFight(const NPC& other) const = 0;
    virtual bool fight(NPC& other) = 0;
    virtual int getMoveRange() const = 0;
    virtual int getKillRange() const = 0;
    std::string getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }
    bool isAlive() const { return alive; }
    void kill() { alive = false; }
    void setPosition(int x, int y) { this->x = x; this->y = y; }

protected:
    NPC(const std::string& name, int x, int y, int moveRange, int killRange)
        : name(name), x(x), y(y), moveRange(moveRange), killRange(killRange), alive(true) {}

private:
    std::string name;
    int x, y;
    int moveRange;
    int killRange;
    std::atomic<bool> alive;
};

class Orc : public NPC {
public:
    Orc(const std::string& name, int x, int y) : NPC(name, x, y, 20, 10) {}
    std::string getType() const override { return "Orc"; }
    void accept(NPCVisitor& visitor) override;
    bool canFight(const NPC& other) const override;
    bool fight(NPC& other) override;
    int getMoveRange() const override { return 20; }
    int getKillRange() const override { return 10; }
};

class Squirrel : public NPC {
public:
    Squirrel(const std::string& name, int x, int y) : NPC(name, x, y, 5, 5) {}
    std::string getType() const override { return "Squirrel"; }
    void accept(NPCVisitor& visitor) override;
    bool canFight(const NPC& other) const override;
    bool fight(NPC& other) override;
    int getMoveRange() const override { return 5; }
    int getKillRange() const override { return 5; }
};

class Bear : public NPC {
public:
    Bear(const std::string& name, int x, int y) : NPC(name, x, y, 10, 10) {}
    std::string getType() const override { return "Bear"; }
    void accept(NPCVisitor& visitor) override;
    bool canFight(const NPC& other) const override;
    bool fight(NPC& other) override;
    int getMoveRange() const override { return 10; }
    int getKillRange() const override { return 10; }
};

#endif // NPC_H

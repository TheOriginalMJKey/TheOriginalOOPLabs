#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void notify(const std::string& message) = 0;
};

class FileObserver : public Observer {
public:
    void notify(const std::string& message) override;
};

class ConsoleObserver : public Observer {
public:
    void notify(const std::string& message) override;
};

#endif // OBSERVER_H

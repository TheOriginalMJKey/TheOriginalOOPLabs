#include "observer.h"
#include <iostream>
#include <fstream>

void FileObserver::notify(const std::string& message) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
    }
}

void ConsoleObserver::notify(const std::string& message) {
    std::cout << message << std::endl;
}

#include <gtest/gtest.h>
#include "observer.h"
#include <fstream>
#include <sstream>

TEST(ObserverTest, FileObserver) {
    FileObserver observer;
    observer.notify("Test message");

    std::ifstream file("log.txt");
    ASSERT_TRUE(file.is_open());

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    file.close();

    ASSERT_TRUE(content.find("Test message") != std::string::npos);
}

TEST(ObserverTest, ConsoleObserver) {
    testing::internal::CaptureStdout();
    ConsoleObserver observer;
    observer.notify("Test message");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Test message\n");
}

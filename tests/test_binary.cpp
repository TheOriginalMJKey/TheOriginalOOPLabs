#include <gtest/gtest.h>
#include "../src/binary.h"

// Тест конструктора
TEST(BinaryTest, Constructor) {
    Binary b1(8, 1);
    Binary b2(8, 0);
    EXPECT_NO_THROW(Binary b3(8, 1));
    EXPECT_THROW(Binary b4(0, 1), std::invalid_argument);
}

// Тест операции сложения
TEST(BinaryTest, Addition) {
    Binary b1(8, 1);
    Binary b2(8, 0);
    Binary b3 = b1 + b2;
    EXPECT_EQ(b3, Binary({1, 1, 1, 1, 1, 1, 1, 1}));
}

// Тест операции вычитания
TEST(BinaryTest, Subtraction) {
    Binary b1(8, 1);
    Binary b2(8, 0);
    Binary b3 = b1 - b2;
    EXPECT_EQ(b3, Binary({1, 1, 1, 1, 1, 1, 1, 1}));
}

// Тест операций сравнения
TEST(BinaryTest, Comparison) {
    Binary b1(8, 1);
    Binary b2(8, 0);
    EXPECT_TRUE(b1 > b2);
    EXPECT_FALSE(b1 < b2);
    EXPECT_TRUE(b1 == b1);
    EXPECT_FALSE(b1 != b1);
}

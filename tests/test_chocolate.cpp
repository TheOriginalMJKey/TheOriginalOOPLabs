#include <gtest/gtest.h>
#include "../src/chocolate.h"

TEST(ChocolateTest, ValidDimensions) {
    EXPECT_EQ(splitChocolate(2, 1), 1);
    EXPECT_EQ(splitChocolate(3, 1), 2);
    EXPECT_EQ(splitChocolate(4, 4), 15);
}

TEST(ChocolateTest, InvalidDimensions) {
    EXPECT_EQ(splitChocolate(0, 0), 0);
    EXPECT_EQ(splitChocolate(-1, 1), 0);
    EXPECT_EQ(splitChocolate(1, -1), 0);
}

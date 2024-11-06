#include <gtest/gtest.h>
#include "../include/fixed_block_memory_resource.h"
#include "../include/custom_container.h"

TEST(MemoryResourceTest, AllocateDeallocate) {
    FixedBlockMemoryResource memoryResource(1024);
    CustomContainer<int> container(&memoryResource);

    container.push_back(1);
    container.push_back(2);
    container.push_back(3);

    EXPECT_EQ(container.size(), 3);

    container.pop_back();
    EXPECT_EQ(container.size(), 2);
}

TEST(MemoryResourceTest, ComplexType) {
    FixedBlockMemoryResource memoryResource(1024);
    CustomContainer<ComplexType> container(&memoryResource);

    container.push_back({1, 2.0});
    container.push_back({2, 3.0});
    container.push_back({3, 4.0});

    EXPECT_EQ(container.size(), 3);

    container.pop_back();
    EXPECT_EQ(container.size(), 2);
}

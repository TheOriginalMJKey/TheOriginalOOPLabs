#include "fixed_block_memory_resource.h"
#include <cstdlib>
#include <iostream>

FixedBlockMemoryResource::FixedBlockMemoryResource(std::size_t blockSize) : blockSize(blockSize) {}

FixedBlockMemoryResource::~FixedBlockMemoryResource() {
    for (void* block : allocatedBlocks) {
        std::free(block);
    }
}

void* FixedBlockMemoryResource::do_allocate(std::size_t bytes, std::size_t alignment) {
    if (bytes > blockSize) {
        throw std::bad_alloc();
    }

    if (!freeBlocks.empty()) {
        void* block = freeBlocks.front();
        freeBlocks.pop_front();
        allocatedBlocks.push_back(block);
        return block;
    }

    void* block = std::malloc(blockSize);
    if (!block) {
        throw std::bad_alloc();
    }
    allocatedBlocks.push_back(block);
    return block;
}

void FixedBlockMemoryResource::do_deallocate(void* p, std::size_t bytes, std::size_t alignment) {
    allocatedBlocks.remove(p);
    freeBlocks.push_back(p);
}

bool FixedBlockMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}

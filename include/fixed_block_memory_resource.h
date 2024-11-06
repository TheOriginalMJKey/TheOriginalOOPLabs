#ifndef FIXED_BLOCK_MEMORY_RESOURCE_H
#define FIXED_BLOCK_MEMORY_RESOURCE_H

#include <memory_resource>
#include <list>
#include <cstddef>
#include <stdexcept>

class FixedBlockMemoryResource : public std::pmr::memory_resource {
public:
    FixedBlockMemoryResource(std::size_t blockSize);
    ~FixedBlockMemoryResource() override;

    void* do_allocate(std::size_t bytes, std::size_t alignment) override;
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

private:
    std::size_t blockSize;
    std::list<void*> freeBlocks;
    std::list<void*> allocatedBlocks;
};

#endif // FIXED_BLOCK_MEMORY_RESOURCE_H

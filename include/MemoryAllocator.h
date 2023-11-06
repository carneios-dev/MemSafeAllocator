#pragma once
#include "AllocationStrategy.h"

class MemoryAllocator {
public:
    explicit MemoryAllocator(AllocationStrategy* strategy);
    ~MemoryAllocator();

    void* Allocate(size_t size);
    void Deallocate(void* pointer);
    void SetStrategy(AllocationStrategy* newStrategy);

private:
    AllocationStrategy* strategy; // Pointer to the current allocation strategy
};

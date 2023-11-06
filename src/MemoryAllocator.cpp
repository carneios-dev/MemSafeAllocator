#include "pch.h"
#include "MemoryAllocator.h"

MemoryAllocator::MemoryAllocator(AllocationStrategy* strategy) : strategy(strategy) {}

MemoryAllocator::~MemoryAllocator() {
    delete strategy;
}

void* MemoryAllocator::Allocate(size_t size) {
    return strategy->Allocate(size);
}

void MemoryAllocator::Deallocate(void* pointer) {
    strategy->Deallocate(pointer);
}

void MemoryAllocator::SetStrategy(AllocationStrategy* newStrategy) {
    if (strategy != newStrategy) {
        delete strategy;
        strategy = newStrategy;
    }
}

#include "pch.h"
#include "FirstFitStrategy.h"
#include <iostream>
#include <stdexcept>
#include <new> // Required for placement new.

FirstFitStrategy::FirstFitStrategy(size_t poolSize) {
    // Ensure the pool size is large enough to hold at least one MemoryBlock plus some space.
    if (poolSize <= sizeof(MemoryBlock)) {
        throw std::invalid_argument("Pool size must be larger than the size of MemoryBlock metadata.");
    }

    // Allocate the entire pool.
    memoryPool = ::operator new(poolSize);

    // Construct the initial MemoryBlock at the start of the pool with the correct size.
    head = new(memoryPool) MemoryBlock{ poolSize - sizeof(MemoryBlock), true, nullptr };
}

FirstFitStrategy::~FirstFitStrategy() {
    ::operator delete(memoryPool);
}

void* FirstFitStrategy::Allocate(size_t size) {
    MemoryBlock* block = FindFit(size);
    if (!block)
        return nullptr;

    if (block->size > size + sizeof(MemoryBlock)) {
        auto* newBlock = reinterpret_cast<MemoryBlock*>(reinterpret_cast<char*>(block) + sizeof(MemoryBlock) + size);
        newBlock->size = block->size - size - sizeof(MemoryBlock);
        newBlock->free = true;
        newBlock->next = block->next;

        block->size = size;
        block->next = newBlock;
    }

    block->free = false;

    return reinterpret_cast<char*>(block) + sizeof(MemoryBlock);
}

void FirstFitStrategy::Deallocate(void* pointer) {
    auto* block = reinterpret_cast<MemoryBlock*>(reinterpret_cast<char*>(pointer) - sizeof(MemoryBlock));
    block->free = true;
    Coalesce();
}

void FirstFitStrategy::DebugPrint() {
    for (MemoryBlock* current = head; current != nullptr; current = current->next) {
        std::cout << "Size: " << current->size << " bytes, Free: " << current->free << std::endl;
    }
}

FirstFitStrategy::MemoryBlock* FirstFitStrategy::FindFit(size_t size) {
    for (MemoryBlock* current = head; current != nullptr; current = current->next) {
        if (current->free && current->size >= size) {
            return current;
        }
    }

    return nullptr;
}

void FirstFitStrategy::Coalesce() {
    for (MemoryBlock* current = head; current && current->next; ) {
        if (current->free && current->next->free) {
            current->size += current->next->size + sizeof(MemoryBlock);
            current->next = current->next->next;
        }
        else {
            current = current->next;
        }
    }
}

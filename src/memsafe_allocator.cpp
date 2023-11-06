#include "pch.h"
#include "memsafe_allocator.h"

void* MemSafeAllocator::Allocate(size_t size) {
    // TODO: Implement the allocation logic
    return nullptr;  // Placeholder return
}

void MemSafeAllocator::Deallocate(void* pointer) {
    // TODO: Implement the deallocation logic
}

void* operator new(size_t size) {
    return MemSafeAllocator::Allocate(size);
}

void operator delete(void* pointer) noexcept {
    MemSafeAllocator::Deallocate(pointer);
}

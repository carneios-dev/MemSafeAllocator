#pragma once

#include <cstddef>

class MemSafeAllocator {
public:
    static void* Allocate(size_t size);
    static void Deallocate(void* pointer);
    // Additional utility functions as needed
};

// For convenience, you may also define the global new and delete overloads here
void* operator new(size_t size);
void operator delete(void* pointer) noexcept;

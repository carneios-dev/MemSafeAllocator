#include "pch.h"
#include "FirstFitStrategy.h"
#include <stdexcept>

void* FirstFitStrategy::Allocate(size_t size) {
    // Placeholder implementation using new
    void* block = malloc(size);
    if (!block) throw std::bad_alloc();
    return block;
}

void FirstFitStrategy::Deallocate(void* pointer) {
    // Placeholder implementation using delete
    free(pointer);
}

#pragma once
#include "AllocationStrategy.h"

class FirstFitStrategy : public AllocationStrategy {
public:
    void* Allocate(size_t size) override;
    void Deallocate(void* pointer) override;
    // Implement the first-fit memory allocation logic
};

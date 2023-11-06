#pragma once

class AllocationStrategy {
public:
    virtual ~AllocationStrategy() = default;
    virtual void* Allocate(size_t size) = 0;
    virtual void Deallocate(void* pointer) = 0;
};

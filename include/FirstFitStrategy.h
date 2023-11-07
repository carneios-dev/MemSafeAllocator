/**
 * @file FirstFitStrategy.h
 * @brief Defines the FirstFitStrategy class which implements memory allocation using the first-fit method.
 *
 * This file provides the definition of the FirstFitStrategy class, which is a concrete class that inherits
 * from the AllocationStrategy interface. The FirstFitStrategy class uses the first-fit algorithm to manage
 * a memory pool, providing functionalities to allocate and deallocate memory blocks within that pool.
 *
 * @author Scott Swanson
 * @date November 7, 2023
 * @version 1.0
 * @see AllocationStrategy.h
 */

#pragma once

#include "AllocationStrategy.h"
#include <cstddef>

 /**
  * @class FirstFitStrategy
  * @brief Implements the first-fit allocation strategy for memory management.
  *
  * The FirstFitStrategy class provides an implementation of a memory allocation strategy using the
  * first-fit approach. It maintains a pool of memory and allows allocation and deallocation requests
  * to be serviced in a way that the first free block of sufficient size is used for allocation.
  */
class FirstFitStrategy : public AllocationStrategy {
public:
    /**
     * @brief Default constructor for FirstFitStrategy.
     *
     * Initializes a new instance of the FirstFitStrategy class with default parameters.
     */
    FirstFitStrategy(size_t poolSize);

    /**
     * @brief Destructor for FirstFitStrategy.
     *
     * Cleans up any resources or pointers held by the instance.
     */
    virtual ~FirstFitStrategy();

    /**
     * @brief Allocates a block of memory of at least the requested size using the first-fit method.
     *
     * Attempts to find a free block that is large enough to fulfill an allocation request, and if
     * successful, it carves out the required size from that block, potentially splitting it into
     * two blocks if there's enough remaining space. If no suitable block is found, returns nullptr.
     *
     * @param size The size of the memory block to allocate.
     * @return A pointer to the allocated memory block or nullptr if allocation fails.
     */
    void* Allocate(size_t size) override;

    /**
     * @brief Deallocates a previously allocated block of memory.
     *
     * Marks the block of memory pointed to by the provided pointer as free and merges it with
     * adjacent free blocks to reduce fragmentation in the memory pool.
     *
     * @param pointer The pointer to the memory block to be deallocated.
     */
    void Deallocate(void* pointer) override;

    /**
     * @brief Prints the current state of the memory pool for debugging purposes.
     *
     * Outputs information about each memory block in the pool, including its size and whether
     * it is free or allocated. This method is useful for debugging and visualizing the state of
     * the memory pool after a series of allocation and deallocation operations.
     */
    void DebugPrint();

private:
    /**
     * @struct MemoryBlock
     * @brief Represents a block of memory within the memory pool.
     *
     * This structure is used internally by the FirstFitStrategy to keep track of memory block size,
     * allocation status, and to link all blocks in a singly linked list for memory management.
     */
    struct MemoryBlock {
        size_t size;
        bool free;
        MemoryBlock* next;
    };

    MemoryBlock* head; /**< Pointer to the first block in the memory pool. */
    void* memoryPool; /**< Pointer to the start of the pre-allocated memory pool. */

    /**
     * @brief Locates a free block of memory of at least the requested size.
     *
     * This method implements the first-fit search algorithm to find a free memory block that is
     * large enough to satisfy a memory allocation request. If no suitable block is found, it returns
     * nullptr indicating that the allocation cannot be satisfied with the current free blocks.
     *
     * @param size The minimum size of the free memory block to locate.
     * @return A pointer to a MemoryBlock structure representing the free block, or nullptr if no
     *         suitable block is found.
     */
    MemoryBlock* FindFit(size_t size);

    /**
     * @brief Coalesces adjacent free blocks into larger blocks.
     *
     * This method merges adjacent free memory blocks into a single larger block to prevent
     * fragmentation within the memory pool. It should be called after a block is deallocated
     * to ensure that the memory pool remains as contiguous as possible, which can improve the
     * efficiency of future allocation requests.
     */
    void Coalesce();
};

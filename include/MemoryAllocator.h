/**
 * @file MemoryAllocator.h
 * @brief This header file contains the definition for the MemoryAllocator class.
 *
 * TODO: <description>
 *
 * @author Scott Swanson
 * @date November 7, 2023
 * @version 1.0
 */

#pragma once

#include "AllocationStrategy.h"

/**
* @brief The MemoryAllocator class.
*
* TODO: <description>
*/
class MemoryAllocator {
public:
    /**
     * @brief Default constructor for MemoryAllocator.
     *
     * Initializes a new instance of the MemoryAllocator class with default parameters.
     */
    explicit MemoryAllocator(AllocationStrategy* strategy);

    /**
     * @brief Destructor for MemoryAllocator.
     *
     * Cleans up any resources or pointers held by the instance.
     */
    ~MemoryAllocator();

    /**
     * @brief TODO: <short_description>
     *
     * TODO: <description>
     *
     * @param size The size of the memory block to allocate.
     * @return Returns a pointer to the start of the memory block.
     */
    void* Allocate(size_t size);

    /**
     * @brief TODO: <short_description>
     *
     * TODO: <description>
     *
     * @param pointer The pointer to the start of the memory block.
     */
    void Deallocate(void* pointer);

    /**
     * @brief TODO: <short_description>
     *
     * TODO: <description>
     *
     * @param newStrategy The allocation strategy to use for the memory allocator.
     */
    void SetStrategy(AllocationStrategy* newStrategy);

private:
    AllocationStrategy* strategy; /**< Pointer to the current allocation strategy. */
};

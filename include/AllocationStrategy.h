/**
 * @file AllocationStrategy.h
 * @brief This header file contains the abstract class, AllocationStrategy.
 *
 * TODO: <description>
 *
 * @author Scott Swanson
 * @date November 7, 2023
 * @version 1.0
 */

#pragma once

/**
* @brief The AllocationStrategy abstract class.
*
* TODO: <description>
*/
class AllocationStrategy {
public:
    /**
     * @brief Virtual destructor definition for AllocationStrategy.
     */
    virtual ~AllocationStrategy() = default;

    /**
     * @brief Pure virtual definition to allocate a memory block.
     *
     * @param size The size of the memory block to allocate.
     * @return Returns a pointer to the start of the memory block.
     */
    virtual void* Allocate(size_t size) = 0;

    /**
     * @brief Pure virtual definition to deallocate the memory block
     *
     * @param pointer The pointer to the start of the memory block.
     */
    virtual void Deallocate(void* pointer) = 0;
};

/**
 * @file FirstFitStrategy.h
 * @brief This header file contains the definition for the FirstFitStrategy class.
 *
 * TODO: <description>
 *
 * @author Scott Swanson
 * @date November 7, 2023
 * @version 1.0
 * @see AllocationStrategy.h
 */

#pragma once
#include "AllocationStrategy.h"

/**
* @brief The FirstFitStrategy class, which implements the AllocationStrategy abstract class.
*
* TODO: <description>
*/
class FirstFitStrategy : public AllocationStrategy {
public:
    /**
     * @brief TODO: <short_description>
     *
     * TODO: <description>
     *
     * @param size The size of the memory block to allocate.
     * @return Returns a pointer to the start of the memory block.
     */
    void* Allocate(size_t size) override;

    /**
     * @brief TODO: <short_description>
     *
     * TODO: <description>
     *
     * @param pointer The pointer to the start of the memory block.
     */
    void Deallocate(void* pointer) override;
    // Implement the first-fit memory allocation logic
};

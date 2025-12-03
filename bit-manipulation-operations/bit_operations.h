#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

#include <stdint.h>
#include <stdio.h>

/**
 * @brief Set a specific bit in a number
 * 
 * @param num Pointer to the number to modify
 * @param bit_position Bit position to set (0-based)
 * @return int 0 on success, -1 on error
 */
int set_bit(uint32_t *num, uint8_t bit_position);

/**
 * @brief Clear a specific bit in a number
 * 
 * @param num Pointer to the number to modify
 * @param bit_position Bit position to clear (0-based)
 * @return int 0 on success, -1 on error
 */
int clear_bit(uint32_t *num, uint8_t bit_position);

/**
 * @brief Toggle a specific bit in a number
 * 
 * @param num Pointer to the number to modify
 * @param bit_position Bit position to toggle (0-based)
 * @return int 0 on success, -1 on error
 */
int toggle_bit(uint32_t *num, uint8_t bit_position);

/**
 * @brief Check if a specific bit is set
 * 
 * @param num The number to check
 * @param bit_position Bit position to check (0-based)
 * @return int 1 if bit is set, 0 if not, -1 on error
 */
int is_bit_set(uint32_t num, uint8_t bit_position);

/**
 * @brief Print binary representation of a number
 * 
 * @param num The number to print in binary
 */
void print_binary(uint32_t num);

#endif /* BIT_OPERATIONS_H */

#include "bit_operations.h"
#include <stdio.h>

#define MAX_BIT_POSITION 31

int set_bit(uint32_t *num, uint8_t bit_position) {
    if (!num || bit_position > MAX_BIT_POSITION) {
        fprintf(stderr, "Error: Invalid input\n");
        return -1;
    }
    
    *num |= (1U << bit_position);
    return 0;
}

int clear_bit(uint32_t *num, uint8_t bit_position) {
    if (!num || bit_position > MAX_BIT_POSITION) {
        fprintf(stderr, "Error: Invalid input\n");
        return -1;
    }
    
    *num &= ~(1U << bit_position);
    return 0;
}

int toggle_bit(uint32_t *num, uint8_t bit_position) {
    if (!num || bit_position > MAX_BIT_POSITION) {
        fprintf(stderr, "Error: Invalid input\n");
        return -1;
    }
    
    *num ^= (1U << bit_position);
    return 0;
}

int is_bit_set(uint32_t num, uint8_t bit_position) {
    if (bit_position > MAX_BIT_POSITION) {
        fprintf(stderr, "Error: Invalid bit position\n");
        return -1;
    }
    
    return (num >> bit_position) & 1U;
}

void print_binary(uint32_t num) {
    printf("Binary: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0 && i != 0) printf(" ");
    }
    printf("\n");
}

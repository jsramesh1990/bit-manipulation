#include <stdio.h>
#include "bit_operations.h"

void run_tests() {
    printf("Running bit operations tests...\n\n");
    
    uint32_t num = 0;
    
    // Test 1: Set bits
    printf("Test 1: Setting bits\n");
    set_bit(&num, 0);
    set_bit(&num, 3);
    set_bit(&num, 7);
    printf("Number after setting bits 0, 3, 7: %u\n", num);
    print_binary(num);
    printf("\n");
    
    // Test 2: Clear bit
    printf("Test 2: Clearing bit 3\n");
    clear_bit(&num, 3);
    printf("Number after clearing bit 3: %u\n", num);
    print_binary(num);
    printf("\n");
    
    // Test 3: Toggle bits
    printf("Test 3: Toggling bits\n");
    toggle_bit(&num, 0);
    toggle_bit(&num, 1);
    printf("Number after toggling bits 0 and 1: %u\n", num);
    print_binary(num);
    printf("\n");
    
    // Test 4: Check bits
    printf("Test 4: Checking bits\n");
    for (int i = 0; i < 8; i++) {
        int result = is_bit_set(num, i);
        if (result >= 0) {
            printf("Bit %d: %s\n", i, result ? "SET" : "CLEAR");
        }
    }
    printf("\n");
    
    // Test 5: Edge cases
    printf("Test 5: Edge cases\n");
    num = 0xFFFFFFFF;
    printf("Starting with all bits set: %u\n", num);
    clear_bit(&num, 31);
    printf("After clearing bit 31: %u\n", num);
    print_binary(num);
    
    printf("\nAll tests completed!\n");
}

int main() {
    run_tests();
    return 0;
}

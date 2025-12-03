#include <stdio.h>
#include <stdlib.h>
#include "bit_operations.h"

void display_menu() {
    printf("\n=== Bit Manipulator ===\n");
    printf("1. Set a bit\n");
    printf("2. Clear a bit\n");
    printf("3. Toggle a bit\n");
    printf("4. Check if bit is set\n");
    printf("5. Display current number\n");
    printf("6. Enter new number\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

int main() {
    uint32_t num = 0;
    uint8_t bit_pos;
    int choice;
    char input[100];
    
    printf("Bit Manipulator Program\n");
    printf("=======================\n");
    
    while (1) {
        display_menu();
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        
        switch (choice) {
            case 0:
                printf("Exiting program.\n");
                return 0;
                
            case 1:
                printf("Enter bit position (0-31) to set: ");
                if (scanf("%hhu", &bit_pos) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                if (set_bit(&num, bit_pos) == 0) {
                    printf("Bit %d set successfully.\n", bit_pos);
                } else {
                    printf("Failed to set bit.\n");
                }
                break;
                
            case 2:
                printf("Enter bit position (0-31) to clear: ");
                if (scanf("%hhu", &bit_pos) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n');
                    break;
                }
                if (clear_bit(&num, bit_pos) == 0) {
                    printf("Bit %d cleared successfully.\n", bit_pos);
                } else {
                    printf("Failed to clear bit.\n");
                }
                break;
                
            case 3:
                printf("Enter bit position (0-31) to toggle: ");
                if (scanf("%hhu", &bit_pos) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n');
                    break;
                }
                if (toggle_bit(&num, bit_pos) == 0) {
                    printf("Bit %d toggled successfully.\n", bit_pos);
                } else {
                    printf("Failed to toggle bit.\n");
                }
                break;
                
            case 4:
                printf("Enter bit position (0-31) to check: ");
                if (scanf("%hhu", &bit_pos) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n');
                    break;
                }
                int result = is_bit_set(num, bit_pos);
                if (result >= 0) {
                    printf("Bit %d is %s\n", bit_pos, result ? "SET" : "CLEAR");
                } else {
                    printf("Failed to check bit.\n");
                }
                break;
                
            case 5:
                printf("\nCurrent number: %u (0x%08X)\n", num, num);
                print_binary(num);
                break;
                
            case 6:
                printf("Enter new number (0 to 4294967295): ");
                if (fgets(input, sizeof(input), stdin) == NULL) break;
                uint32_t new_num;
                if (sscanf(input, "%u", &new_num) == 1) {
                    num = new_num;
                    printf("Number updated to: %u\n", num);
                } else {
                    printf("Invalid number!\n");
                }
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        // Clear the input buffer
        while (getchar() != '\n');
    }
    
    return 0;
}

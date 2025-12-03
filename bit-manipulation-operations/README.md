# Bit Manipulator

A C program that demonstrates bit manipulation operations with a user-friendly interface.

## Features
- **Set Bit**: Set a specific bit to 1
- **Clear Bit**: Set a specific bit to 0
- **Toggle Bit**: Flip a specific bit (1 → 0, 0 → 1)
- **Check Bit**: Check if a specific bit is set or clear
- **Binary Display**: View numbers in binary format
- **Interactive Menu**: Easy-to-use command-line interface

## Operations
1. `set_bit(num, position)`: Sets the bit at given position to 1
2. `clear_bit(num, position)`: Sets the bit at given position to 0
3. `toggle_bit(num, position)`: Flips the bit at given position
4. `is_bit_set(num, position)`: Checks if bit at position is set (1)

## Building and Running

### Prerequisites
- GCC compiler
- Make (optional)

### Using Makefile
```bash
# Build the main program
make

# Run the program
make run

# Run tests
make test

# Clean build files
make clean

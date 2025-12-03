# Project Flow Explanation

## Overall Architecture
```
┌─────────────────────────────────────────────┐
│            MAIN PROGRAM (main.c)            │
│   User Interface & Menu-Driven System       │
└───────────────┬─────────────────────────────┘
                │
                ▼
┌─────────────────────────────────────────────┐
│    BIT OPERATIONS LIBRARY (bit_operations)  │
│  Core Logic for Bit Manipulation Functions  │
└───────────────┬─────────────────────────────┘
                │
                ▼
┌─────────────────────────────────────────────┐
│             TEST PROGRAM (test_*.c)         │
│    Automated Testing of Core Functions      │
└─────────────────────────────────────────────┘
```

## Detailed Flow Breakdown

### 1. **Program Initialization**
```c
// main.c - Starting point
int main() {
    uint32_t num = 0;        // Default starting number
    uint8_t bit_pos;         // Bit position variable
    int choice;              // User menu choice
    char input[100];         // Input buffer
    
    // Display welcome message
    // Enter main loop
}
```

### 2. **Main Loop Flow**
```
┌─────────────────────────────────────────┐
│          DISPLAY MENU OPTIONS           │
├─────────────────────────────────────────┤
│  1. Set a bit                           │
│  2. Clear a bit                         │
│  3. Toggle a bit                        │
│  4. Check if bit is set                 │
│  5. Display current number              │
│  6. Enter new number                    │
│  0. Exit                                │
└─────────────────┬───────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────┐
│     GET USER INPUT & VALIDATE           │
└─────────────────┬───────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────┐
│   SWITCH BASED ON USER CHOICE           │
│  (Routes to appropriate functionality)  │
└─────────────────┬───────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────┐
│   CALL BIT OPERATION FUNCTIONS          │
│  (Passes control to library functions)  │
└─────────────────┬───────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────┐
│      DISPLAY RESULTS TO USER            │
└─────────────────┬───────────────────────┘
                  │
                  ▼
          ┌───────────────┐
          │   LOOP BACK   │
          └───────────────┘
```

### 3. **Bit Operation Library Flow**

#### **Function Call Chain:**
```
User selects operation
    ↓
Main program calls library function
    ↓
Library validates input parameters
    ↓
Library performs bitwise operation
    ↓
Library returns result/error code
    ↓
Main program displays result to user
```

#### **Example: Setting a Bit (Option 1)**
```c
// User selects "1. Set a bit"
// Main program flow:
1. Prompt user for bit position (0-31)
2. Read input → bit_pos
3. Call: set_bit(&num, bit_pos)
   ↓
   // Inside set_bit() function:
   1. Validate: if (!num || bit_position > 31) return -1
   2. Perform: *num |= (1U << bit_position)
   3. Return: 0 (success)
   ↓
4. Check return value
5. Display success/failure message
6. Show updated number in decimal/hex/binary
```

#### **Bit Manipulation Mechanics:**
- **Set bit**: `*num |= (1U << pos)`
  - OR operation sets bit to 1
  - Example: num=5(0101), set bit 1 → num=7(0111)
  
- **Clear bit**: `*num &= ~(1U << pos)`
  - AND with NOT clears bit to 0
  - Example: num=7(0111), clear bit 1 → num=5(0101)
  
- **Toggle bit**: `*num ^= (1U << pos)`
  - XOR flips the bit
  - Example: num=5(0101), toggle bit 1 → num=7(0111)

### 4. **Error Handling Flow**
```
┌─────────────────────────────┐
│      User Input Phase       │
├─────────────────────────────┤
│ 1. Validate numeric input   │
│ 2. Check range (0-31)       │
│ 3. Handle invalid input     │
└───────────────┬─────────────┘
                ▼
┌─────────────────────────────┐
│  Library Function Phase     │
├─────────────────────────────┤
│ 1. Check NULL pointers      │
│ 2. Validate bit position    │
│ 3. Return error codes       │
└───────────────┬─────────────┘
                ▼
┌─────────────────────────────┐
│  Main Program Response      │
├─────────────────────────────┤
│ 1. Check return values      │
│ 2. Display error messages   │
│ 3. Clear input buffer       │
└─────────────────────────────┘
```

### 5. **Binary Display Flow**
When user selects "5. Display current number":
```
┌─────────────────────────────┐
│  print_binary(num) called   │
├─────────────────────────────┤
│ Loop from bit 31 to bit 0:  │
│ 1. Extract each bit:        │
│    (num >> i) & 1           │
│ 2. Print bit value          │
│ 3. Add space every 8 bits   │
└─────────────────────────────┘
```
Example output: `Binary: 00000000 00000000 00000000 00000101`

### 6. **Test Program Flow**
```
┌─────────────────────────────┐
│     run_tests() called      │
├─────────────────────────────┤
│ 1. Test set_bit()           │
│ 2. Test clear_bit()         │
│ 3. Test toggle_bit()        │
│ 4. Test is_bit_set()        │
│ 5. Test edge cases          │
│ 6. Print results for each   │
└─────────────────────────────┘
```

### 7. **Makefile Build Flow**
```makefile
# Dependency tree
bit_manipulator (executable)
    ├── main.o
    │   └── main.c + bit_operations.h
    └── bit_operations.o
        └── bit_operations.c + bit_operations.h

test_bit_ops (test executable)
    ├── test_bit_operations.o
    │   └── test_bit_operations.c + bit_operations.h
    └── bit_operations.o
```

**Compilation Steps:**
1. `make` → Compiles all source files → Links → Creates executable
2. `make run` → Builds (if needed) → Runs main program
3. `make test` → Builds test program → Runs tests
4. `make clean` → Removes object files and executables

## Data Flow Examples

### Example 1: Setting Bit 5
```
User Input: Menu option 1 → Bit position 5
    ↓
Main: set_bit(&num, 5)
    ↓
Library: *num |= (1 << 5)
    Original: 0000 0000 0000 0000 (0)
    Operation: OR with 0010 0000 (1<<5)
    Result:    0010 0000 (32)
    ↓
Main: Display "Bit 5 set successfully"
Main: Display "Number: 32, Binary: 0000 0000 0010 0000"
```

### Example 2: Toggling Bit 0 and 1
```
Current: 0010 0000 (32)
User: Toggle bits 0 and 1
    ↓
toggle_bit(&num, 0): 0010 0000 ^ 0000 0001 = 0010 0001 (33)
toggle_bit(&num, 1): 0010 0001 ^ 0000 0010 = 0010 0011 (35)
    ↓
Result: 0010 0011 (35)
```

## Key Design Patterns

### 1. **Separation of Concerns**
- **main.c**: User interface and input handling
- **bit_operations.c**: Core business logic
- **test_bit_operations.c**: Verification and testing

### 2. **Error Propagation**
- Functions return error codes (-1)
- Main program checks returns
- Clear error messages for users

### 3. **Memory Safety**
- Pointer validation before dereferencing
- Range checking for bit positions
- Input buffer clearing

### 4. **User Experience**
- Menu-driven interface
- Multiple number formats (decimal, hex, binary)
- Clear feedback for all operations

## Program States

```
┌─────────────┐
│  INITIALIZE │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│  SHOW MENU  │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ GET CHOICE  │
└──────┬──────┘
       │
       ▼
┌─────────────────┐
│ EXECUTE OPTION  │◄─┐
└──────┬──────────┘  │
       │             │
       ▼             │
┌─────────────┐      │
│  DISPLAY    │      │
│   RESULT    │      │
└──────┬──────┘      │
       │             │
       ▼             │
┌─────────────┐      │
│  LOOP BACK  │──────┘
└─────────────┘

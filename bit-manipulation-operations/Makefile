CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = bit_manipulator
TEST_TARGET = test_bit_ops

all: $(TARGET)

$(TARGET): main.o bit_operations.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o bit_operations.o

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): test_bit_operations.o bit_operations.o
	$(CC) $(CFLAGS) -o $(TEST_TARGET) test_bit_operations.o bit_operations.o

main.o: main.c bit_operations.h
	$(CC) $(CFLAGS) -c main.c

bit_operations.o: bit_operations.c bit_operations.h
	$(CC) $(CFLAGS) -c bit_operations.c

test_bit_operations.o: test_bit_operations.c bit_operations.h
	$(CC) $(CFLAGS) -c test_bit_operations.c

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean test run

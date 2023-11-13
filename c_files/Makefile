# Makefile for test.c

# Source
OBJ = test.c

# Executable
EXEC = test

# Compiler
CC = gcc

# Compiler Flags
FLAGS = -Wall -Werror

# Compilation Process
make: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
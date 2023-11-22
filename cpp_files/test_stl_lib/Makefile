# Makefile for test_lib.cpp

# Source
OBJ = test_lib.cpp

# Executable
EXEC = test_lib

# Compiler 
CC = g++

# Compiler Options
FLAGS = -Wall -Werror

# Compilation Process
make: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
# Makefile for Project: My Stack

# Target Files
OBJ1 = my_stack.cpp

# Unlinked Files
UNL1 = my_stack.o 

# Executable File
EXEC = my_stack

# Compiler
CC = g++

# Compile Options
FLAGS = -Wall -Werror

# Compilation Process
make: $(OBJ1)
	$(CC) -c $(OBJ1)
	$(CC) -o $(EXEC) $(UNL1)

run: $(OBJ1) $(EXEC)
	./$(EXEC)

valgrind: $(OBJ1) $(EXEC)
	valgrind ./$(EXEC)

# Makefile for Project: My Stack

# Target Files
OBJ1 = my_stack.cpp
OBJ2 = my_stack_funcs.cpp

# Unlinked Files
UNL1 = my_stack.o 
UNL2 = my_stack_funcs.o

# Executable File
EXEC = my_stack

# Compiler
CC = g++

# Compile Options
FLAGS = -Wall -Werror

# Compilation Process
make: $(OBJ1)
	$(CC) -c $(OBJ1)
	$(CC) -c $(OBJ2)
	$(CC) -o $(EXEC) $(UNL1) $(UNL2)

run: $(OBJ1) $(OBJ2) $(EXEC) 
	./$(EXEC)

valgrind: $(OBJ1) $(OBJ2) $(EXEC)
	valgrind ./$(EXEC)

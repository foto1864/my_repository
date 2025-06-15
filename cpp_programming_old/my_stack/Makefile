# Makefile for Project: My Stack

# Target Files
OBJ1 = my_stack.cpp

# Unlinked Files
UNL1 = my_stack.o 

# Executable File
EXEC = my_stack

# Compiler
CC = g++

# Include Files
INCLUDE = ../my_stack

# Compile Options
FLAGS = -Wall -Werror

# Compilation Process
make: $(OBJ1) 
	$(CC) -o $(EXEC) $(OBJ1) $(FLAGS) 

run: $(OBJ1) $(EXEC) 
	./$(EXEC)

valgrind: $(OBJ1)$(EXEC)
	valgrind ./$(EXEC)

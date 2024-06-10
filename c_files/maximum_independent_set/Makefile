# Makefile for max_independent_set.c

# Compiler
CC = gcc

# Object file (source)
OBJ = max_independent_set.c

# Executable
EXEC = max_independent_set

# Compiler options
FLAGS = -Wall -Werror

make: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(FLAGS)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
# Makefile for max_independent_set.c

# Compiler
CC = gcc

# Object files (source)
OBJ1 = max_independent_set.c
OBJ2 = functions.c

# Unlinked files
UNL1 = max_independent_set.o
UNL2 = functions.o

# Executable
EXEC = max_independent_set

# Compiler options
FLAGS = -Wall -Werror

make: $(OBJ1) $(OBJ2)
	$(CC) -c $(OBJ1) $(FLAGS)
	$(CC) -c $(OBJ2) $(FLAGS)
	$(CC) -o $(EXEC) $(UNL1) $(UNL2) $(FLAGS)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
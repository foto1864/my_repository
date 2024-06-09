# Makefile for palindrome.c

# Compiler
CC = gcc

# Object file (source)
OBJ = palindrome.c

# Executable
EXEC = palindrome

# Compiler options
FLAGS = -Wall -Werror

make: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(FLAGS)

run: $(EXEC)
	./$(EXEC)
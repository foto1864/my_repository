# Makefile for General Testing

OBJ = test.c
EXEC = test
FLAGS = -Wall -Werror
CC = gcc

make: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(FLAGS)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
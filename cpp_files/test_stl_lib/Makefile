# Makefile for test_lib.cpp

# Source
OBJ1 = test_lib.cpp
OBJ2 = functions.cpp

# Executable
EXEC = test_lib

# Compiler 
CC = g++

# Compiler Options
FLAGS = -Wall -Werror

# Compilation Process
make: $(OBJ1) $(OBJ2)
	$(CC) -c $(OBJ1) $(FLAGS)
	$(CC) -c $(OBJ2) $(FLAGS)
	$(CC) -o $(EXEC) test_lib.o functions.o

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
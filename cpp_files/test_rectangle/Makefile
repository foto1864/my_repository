# Makefile test for test.cpp

# source
OBJ = test.cpp

# exec
EXEC = test

# compiler
CC = g++

# compiler options
FLAGS = -Wall -Werror

# make
make: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(FLAGS)

# run
run: $(EXEC)
	./$(EXEC)

# run with valgrind
valgrind: $(EXEC)
	valgrind ./$(EXEC)
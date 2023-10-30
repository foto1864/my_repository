# Makefile test for test.cpp

# source
OBJ = test.cpp

# exec
EXEC = test

# compiler
CC = g++

# make
make: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

# run
run: $(EXEC)
	./$(EXEC)

# run with valgrind
valgrind: $(EXEC)
	valgrind ./$(EXEC)
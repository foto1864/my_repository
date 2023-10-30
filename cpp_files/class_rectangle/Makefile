# Makefile test for test.cpp

# source
OBJ = class_rectangle.cpp

# exec
EXEC = class_rectangle

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
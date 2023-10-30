# Makefile test for class_triangle.cpp

# source
OBJ = class_triangle.cpp

# exec
EXEC = class_triangle

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
# Makefile for class_rectangle_dynamic.cpp

# targets
OBJ = class_rectangle_dynamic.cpp

# exec
EXEC = class_rectangle_dynamic

# compiler
CC = g++

make: $(OBJ) 
	$(CC) -o $(EXEC) $(OBJ)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
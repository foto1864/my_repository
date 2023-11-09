# Makefile for class_rectangle_dp.cpp

# targets
OBJ1 = class_rectangle_dp.cpp
OBJ2 = class_rectangle_dp_funcs.cpp

# unlinked 
UNL1 = class_rectangle_dp.o 
UNL2 = class_rectangle_dp_funcs.o 

# exec
EXEC = class_rectangle_dp

# compiler
CC = g++

# include files
INCLUDE = class_rectangle_dp.h

make: $(OBJ1) $(OBJ2)
	$(CC) -c $(OBJ1)
	$(CC) -c $(OBJ2)
	$(CC) -o $(EXEC) $(UNL1) $(UNL2) -I$(INCLUDE)

run: $(EXEC)
	./$(EXEC)

valgrind: $(OBJ1) $(OBJ2) $(EXEC)
	valgrind ./$(EXEC)
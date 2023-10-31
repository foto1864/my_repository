# Makefile test for class_pet.cpp

# source
OBJ = class_pet.cpp

# exec
EXEC = class_pet

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
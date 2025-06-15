# Makefile test for farenheit_to_celcius.cpp

# source
OBJ = farenheit_to_celcius.cpp

# exec
EXEC = farenheit_to_celcius

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
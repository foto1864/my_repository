# source files
OBJ_1 = test_acutest_test.c
OBJ_2 = test_acutest.c

# unliked files
UNL_1 = test_acutest.o
UNL_2 = test_acutest_test.o

# executable
EXEC = test_acutest

# compiler
CC = gcc

# include files
INCLUDE = ../include

make: $(OBJ1), $(OBJ2)
	$(CC) -c $(OBJ1) 
	$(CC) -c $(OBJ2)
	$(CC) -o $(UNL_1) $(UNL_2) $(EXEC) -I$(INCLUDE)

run: $(EXEC)
	./$(EXEC)
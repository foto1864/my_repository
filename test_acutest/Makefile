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

make: $(OBJ_1) $(OBJ_2)
	$(CC) -c $(OBJ_1) 
	$(CC) -c $(OBJ_2)
	$(CC) -o $(EXEC) $(UNL_1) $(UNL_2) 
	./$(EXEC)

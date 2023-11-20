# Makefile for test.c

# Unliked Files
UNL1 = ADTSet.o 
UNL2 = ADTMap.o 
UNL3 = test.o  

# Executable
EXEC = test

# Compiler Flags
FLAGS = -Wall -Werror

# Compiler
CC = gcc

# Compilation Process
make: test.c
	$(CC) -c test.c $(FLAGS)
	$(CC) -o $(EXEC) ADT_Set/$(UNL1) ADT_Map/$(UNL2) $(UNL3) $(FLAGS)

run: test.c $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
# Makefile for test.c

# Libraries
INCLUDE = include

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
make:
	$(CC) -c test.c -I$(INCLUDE) $(FLAGS)
	$(CC) -o $(EXEC) ADT_Set/$(UNL1) ADT_Map/$(UNL2) $(UNL3) -I$(INCLUDE) $(FLAGS)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
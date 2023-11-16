# Makefile for test.c

# Paths
SET = ADT_SET
MAP = ADT_MAP

# Libraries
INCLUDE = include

# Source Files
OBJ1 = ADTSet.c
OBJ2 = ADTMap.c
OBJ3 = test.c 

# Unliked Files
UNL1 = ADTSet.o 
UNL2 = ADTMap.o 
UNL3 = test.o  

# Executable
EXEC = bd_notifs

# Compiler Flags
FLAGS = -Wall -Werror

# Compiler
CC = gcc

# Compilation Process
make: $(OBJ1) $(OBJ2) $(OBJ3)
	$(CC) -c ADT_SET/ADTSet.c -I$(INCLUDE) $(FLAGS)
	$(CC) -c ADT_MAP/ADTMap.c -I$(INCLUDE) $(FLAGS)
	$(CC) -c $(OBJ3)
	$(CC) -o $(EXEC) $(UNL1) $(UNL2) $(UNL3) -I$(INCLUDE) $(FLAGS)

run: $(EXEC)
	./$(EXEC)
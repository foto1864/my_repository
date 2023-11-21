# Makefile for birthday_notifications.c

# Unliked Files
UNL1 = ADTSet.o 
UNL2 = ADTMap.o 
UNL3 = birthday_notifications.o  

# Executable
EXEC = birthday_notifications

# Compiler Flags
FLAGS = -Wall -Werror

# Compiler
CC = gcc

# Compilation Process
make: birthday_notifications.c
	$(CC) -c birthday_notifications.c $(FLAGS)
	$(CC) -o $(EXEC) ADT_Set/$(UNL1) ADT_Map/$(UNL2) $(UNL3) $(FLAGS)

run: birthday_notifications.c $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
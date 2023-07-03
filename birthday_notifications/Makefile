# Makefile for birthday_notifications.c

# Source Files
OBJS = birthday_notifications.c ../ADTMap/ADTMap.c

# Executable
EXEC = birthday_notifications 

# Libraries
INCLUDE = ../ADTMap/ADTMap.h

# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Werror

make: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(CFLAGS) -I$(INCLUDE)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
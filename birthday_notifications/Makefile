# Makefile for birthday_notifications.c

# Source Files
OBJS = birthday_notifications.c

# Executable
EXEC = birthday_notifications

# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Werror

make: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(CFLAGS) 

run: $(EXEC)
	./$(EXEC)
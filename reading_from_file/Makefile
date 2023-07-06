# Makefile for reading_from_file.c

# Objects
OBJS = reading_from_file.o

# Executable
EXEC = reading_from_file

# Compiler Options
CFLAGS = -Wall -Werror

# Compiler
CC = gcc

make: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

run: $(EXEC)
	./$(EXEC)

valgrind: $(OBJS) $(EXEC)
	valgrind ./$(EXEC)
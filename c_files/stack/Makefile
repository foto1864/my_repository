# Makefile for the stack module

# Compiler
CC = gcc

# Compile options
CFLAGS = -Wall -Werror

# Programs
stack: stack.c 
	$(CC) -c stack.c $(CFLAGS)

main: main.o 
	$(CC) -c main.c $(CFLAGS)

exec: main.o stack.o
	$(CC) -o main stack.o main.o $(CFLAGS)

# Clean
clean: 
	- rm stack main

# Execute
run: 
	./main

# Execute with memory check
valgrind:
	valgrind ./main
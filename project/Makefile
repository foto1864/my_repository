# Makefile for project.cpp

# Compiler
CC = g++

# Flags
FLAGS = -Wall -Werror

project: project.o
	$(CC) -o project project.o $(FLAGS) 

clean:
	rm project
	rm project.o

run: project
	./project

valgrind: project
	valgrind ./project

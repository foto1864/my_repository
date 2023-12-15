# Makefile for project.cpp

# Compiler
CC = g++

# Flags
FLAGS = -Wall -Werror

project: project.cpp
	$(CC) -o project project.cpp $(FLAGS) 

clean:
	rm project
	rm project.o

run: project
	./project

valgrind: project
	valgrind ./project

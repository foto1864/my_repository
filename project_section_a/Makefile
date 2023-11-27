# Makefile for project_section_a.cpp

# Compiler
CC = g++

# Flags
FLAGS = -Wall -Werror

project: project_section_a.o
	$(CC) -o project project_section_a.o $(FLAGS) 

clean:
	rm project
	rm project_section_a.o

run: project
	./project

valgrind: project
	valgrind ./project

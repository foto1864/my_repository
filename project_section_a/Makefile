# Makefile for project_section_a.cpp

# Source
OBJ = project_section_a.cpp

# Executable
EXEC = project_section_a

# Compiler
CC = g++

# Compiler Options
FLAGS = -Wall -Werror

# Compilation Process
make: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(FLAGS)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)

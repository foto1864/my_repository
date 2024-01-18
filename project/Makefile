# Makefile for project.cpp

# Compiler
CC = g++

# Source Files
OBJ1 = course.cpp
OBJ2 = person.cpp
OBJ3 = professor.cpp
OBJ4 = student.cpp
OBJ5 = secretary.cpp
OBJ6 = utilities.cpp
MAIN = main.cpp

# Unlinked Files
UNL1 = course.o
UNL2 = person.o
UNL3 = professor.o
UNL4 = student.o
UNL5 = secretary.o
UNL6 = utilities.o
UNLM = main.o 

# Executable
EXEC = university

# Compiler Options
FLAGS = -Wall -Werror

make: $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(MAIN) 
	$(CC) -c $(OBJ1) $(FLAGS)
	$(CC) -c $(OBJ2) $(FLAGS)
	$(CC) -c $(OBJ3) $(FLAGS)
	$(CC) -c $(OBJ4) $(FLAGS)
	$(CC) -c $(OBJ5) $(FLAGS)
	$(CC) -c $(OBJ6) $(FLAGS)
	$(CC) -c $(MAIN) $(FLAGS)
	@$(CC) -o $(EXEC) $(UNL1) $(UNL2) $(UNL3) $(UNL4) $(UNL5) $(UNL6) $(UNLM) $(FLAGS)
	@echo g++ -o university unlinked.o -Wall -Werror

clean: $(EXEC)
	@echo Removed .o files and executable 
	@rm $(EXEC)
	@rm *.o

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
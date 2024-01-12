# Makefile for project.cpp

# Compiler
CC = g++

# Source Files
OBJ1 = class_course_functions.cpp
OBJ2 = class_person_functions.cpp
OBJ3 = class_professor_functions.cpp
OBJ4 = class_student_functions.cpp
OBJ5 = class_secretary_functions.cpp
MAIN = main.cpp

# Unlinked Files
UNL1 = class_course_functions.o
UNL2 = class_person_functions.o
UNL3 = class_professor_functions.o
UNL4 = class_student_functions.o
UNL5 = class_secretary_functions.o
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
	$(CC) -c $(MAIN) $(FLAGS)
	@$(CC) -o $(EXEC) $(UNL1) $(UNL2) $(UNL3) $(UNL4) $(UNL5) $(UNLM) $(FLAGS)
	@echo g++ -o university unlinked.o -Wall -Werror

clean:
	@echo Removed .o files and executable 
	@rm $(EXEC)
	@rm $(UNL1) $(UNL2) $(UNL3) $(UNL4) $(UNL5) $(UNLM)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
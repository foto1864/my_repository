#Makefile for minmax.c

OBJ1 = minmax.c
OBJ2 = minmax_funcs.c 
NOBJ1 = minmax.o 
NOBJ2 = minmax_funcs.o 
EXEC = minmax

make : $(OBJ1) $(OBJ2)
	gcc -c $(OBJ1)
	gcc -c $(OBJ2)
	gcc -o $(EXEC) $(NOBJ1) $(NOBJ2)
run : $(EXEC) 
	./$(EXEC)
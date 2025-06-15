OBJS = linked_list.c main.c

EXEC = linked_list

UNL = linked_list.o main.o

CC = gcc

FLAGS = -Wall -Werror

make: $(OBJS)
	$(CC) -c $(OBJS) $(FLAGS)
	$(CC) -o $(EXEC) $(UNL) $(FLAGS)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)

clean: 
	rm $(UNL) $(EXEC)
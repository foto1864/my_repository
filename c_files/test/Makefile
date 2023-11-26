# Using a different makefile style

CFLAGS = -Wall -Werror

exec: main.o functions.o
	gcc -o exec main.o functions.o $(CFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

functions.o: functions.c
	gcc -c functions.c $(CFLAGS)

clean:
	rm functions.o main.o exec

all: exec

run: exec
	./exec

valgrind: exec
	valgrind ./exec
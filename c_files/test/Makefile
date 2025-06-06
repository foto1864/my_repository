# Using a different makefile style

CFLAGS = -Wall -Werror

exec: string_to_text.o
	gcc -o exec string_to_text.o $(CFLAGS)

string_to_text.o: string_to_text.c
	gcc -c string_to_text.c $(CFLAGS)

# functions.o: functions.c
# 	gcc -c functions.c $(CFLAGS)

clean:
	- rm *.o memo exec

all: exec

run: exec
	./exec

valgrind: exec
	valgrind ./exec
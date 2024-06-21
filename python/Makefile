target = hello_world.c

executable = identity_matrix

compiler = gcc

flags = -Wall -Werror

make: $(target)
	$(compiler) -o $(executable) $(target) $(flags)

run: $(executable)
	./$(executable) 
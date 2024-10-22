

make:
	gcc -c src/hash_map.c -I lib
	gcc -c src/miris.c -I lib
	gcc -c src/display_menu.c -I lib
	gcc -o miris display_menu.o hash_map.o miris.o -I lib
	./miris

valgrind:
	gcc -o gpt_graph gpt_graph.c
	valgrind ./gpt_graph
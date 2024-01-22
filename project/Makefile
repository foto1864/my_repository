CC = g++
CFLAGS = -Wall -Werror
EXECUTABLE = university

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: build run

build: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

run:
	./$(EXECUTABLE)

valgrind:
	valgrind ./$(EXECUTABLE)

time:
	time ./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) *.o *.txt
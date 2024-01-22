CC = g++
CFLAGS = -Wall -Werror
EXECUTABLE = project

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

clean:
	rm -f $(EXECUTABLE) $(OBJ_DIR)/*.o

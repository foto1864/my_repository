# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -O2

# Directories
SRCDIR = src
OBJDIR = obj

# Source files
SRC = $(wildcard $(SRCDIR)/*.c)

# Object files
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Executable
EXEC = program

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the executable
run: $(EXEC)
	./$(EXEC)

# Clean the build directory
clean:
	rm -rf $(OBJDIR) $(EXEC)

# Phony targets
.PHONY: all clean run

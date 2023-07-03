# Makefile for birthday_notifications.c

# Paths
MODULES = ../modules
MOD_MAP = UsingADTMap_BirthdayNotifications
MOD_HASH = UsingHashTable_ADTMap

# Libraries
INCLUDE = ../include

# Source Files
OBJS = $(MODULES)/$(MOD_MAP)/bd_notifs.c $(MODULES)/$(MOD_HASH)/ADTMap.c $(MODULES)/$(MOD_MAP)/bd_notifs_utils.c

# Executable
EXEC = birthday_notifications 

# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Werror

make: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(CFLAGS) -I$(INCLUDE)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
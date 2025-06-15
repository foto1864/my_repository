# Makefile for birthday_notifications.c

# Paths
MODULES = ../modules
MOD_MAP = UsingADTMap_BirthdayNotifications
MOD_SET = UsingADTSet_ADTMap
MOD_AVL = UsingAVL_ADTSet

# Libraries
INCLUDE = ../include

# Executable
EXEC = birthday_notifications 

# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Werror

make:
	$(CC) -c $(MODULES)/$(MOD_AVL)/ADTSet.c -I$(INCLUDE) $(CFLAGS)
	$(CC) -c $(MODULES)/$(MOD_SET)/ADTMap.c -I$(INCLUDE) $(CFLAGS)
	$(CC) -c $(MODULES)/$(MOD_MAP)/bd_notifs.c -I$(INCLUDE) $(CFLAGS)
	$(CC) -c $(MODULES)/$(MOD_MAP)/bd_notifs_load_bds.c -I$(INCLUDE) $(CFLAGS)
	$(CC) -c $(MODULES)/$(MOD_MAP)/bd_notifs_date_info.c -I$(INCLUDE) $(CFLAGS)
	$(CC) -o $(EXEC) bd_notifs.o ADTMap.o ADTSet.o bd_notifs_load_bds.o bd_notifs_date_info.o $(CFLAGS) -I$(INCLUDE)

run: 
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)

clean:
	rm ADTMap.o ADTSet.o bd_notifs.o birthday_notifications bd_notifs_date_info.o bd_notifs_load_bds.o
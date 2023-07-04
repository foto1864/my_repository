// Library File for birthday_notifications.c

#include "ADTMap.h"
#include "ADTSet.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Holds the information of the current date
typedef struct {
    int date;           // Date 
    int month;          // Month
    int year;           // Year
    int hours;          // Hours
    int minutes;        // Minutes
} date_info;

// Pointer to the struct date_info
typedef date_info * DateInfo;

// Gets the information of the current date
DateInfo get_date_info(void);

// Prints the information of the current date
void print_date_info(DateInfo info);

// Compare Function that arranges dates in chronological order
int compare_dates(DateInfo info_1, DateInfo info_2);

// Loads the birthdays of the year when the program starts
Map load_birthdays(void);
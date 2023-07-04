#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../../include/ADTMap.h"

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

// Holds the information of the people who have a birthday today
typedef struct { 
} birthday_info;

// Pointer to the struct birthday_info
typedef birthday_info * BirthdayInfo;

// Gets the information of the current date
DateInfo get_date_info(void) {

    time_t t = time(NULL);
    struct tm day = *localtime(&t);
    
    DateInfo info = malloc(sizeof(*info));
    info->date = day.tm_mday;                 // Get the date
    info->month = day.tm_mon + 1;             // Get the month [0-11]
    info->year = day.tm_year - 100;           // Get the year [Year-1900]
    info->hours = day.tm_hour;                // Get the hours
    info->minutes = day.tm_min;               // Get the minutes
    
    return info;
}

// Prints the information of the current date
void print_date_info(DateInfo info) {
    // Print The Current Date
    printf("Current date is %02d/%02d/%02d\n", info->date, info->month, info->year);
    // Print The Current Time
    printf("Current time is %02d:%02d\n", info->hours, info->minutes);
    return;
}


BirthdayInfo get_birthday_info(DateInfo info) {
    BirthdayInfo bd_info = malloc(sizeof(*bd_info));
    return bd_info;
}

void print_birthday_info(BirthdayInfo bd_info) {
    return;
}

int main(void) {

    // Get and print the information of current day
    DateInfo date_info = get_date_info();
    print_date_info(date_info);
    free(date_info);

    // Test
    Map birthdays = load_birthdays();
    map_destroy(birthdays);    

    return 0;
}
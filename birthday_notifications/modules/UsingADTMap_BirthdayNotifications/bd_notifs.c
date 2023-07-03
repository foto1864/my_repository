#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ADTMap.h"

// Holds the information of the current date
typedef struct {
    int date;           // Date `
    int month;          // Month
    int year;           // Year
    int hours;          // Hours
    int minutes;        // Minutes
} date_info;

// Pointer to the struct date_info
typedef date_info * DateInfo;

int compare_dates(DateInfo info_1, DateInfo info_2){
    // If the month of the first date is greater than the month of
    // the second date, then that means that the first date comes 
    // after the second. Same thing happens the other way around. 

    if (info_1->month > info_2->month) 
        return 1;
    else if (info_1->month < info_2->month)
        return -1;

    // If the control flow reaches this point, it means that both dates
    // are of the same month. This means that it depends on the day itself
    // to figure out what date between info_1, info_2 comes first.

    if (info_1->date > info_2->date)
        return 1;
    else if (info_1->date < info_2->date)
        return -1;
    else 
        return 0;    
}

Map load_birthdays(void) {
    Map birthdays = map_create((CompareFunc) compare_dates, free, free);

    DateInfo info_JK = malloc(sizeof(*info_JK));
    info_JK->date = 13;
    info_JK->month = 3;
    info_JK->year = 2004;
    map_insert(birthdays, info_JK, "Jim Kontopidis");

    DateInfo info_AS = malloc(sizeof(*info_AS));
    info_AS->date = 25;
    info_AS->month = 2;
    info_AS->year = 2004;
    map_insert(birthdays, info_AS, "Anastasia Spaidioti");

    DateInfo info_GF = malloc(sizeof(*info_GF));
    info_GF->date = 6;
    info_GF->month = 1;
    info_GF->year = 2004;
    map_insert(birthdays, info_GF, "Giannis Foteinakis");

    DateInfo info_DF = malloc(sizeof(*info_DF));
    info_DF->date = 19;
    info_DF->month = 4;
    info_DF->year = 2005;
    map_insert(birthdays, info_DF, "Dimitris Foteinakis");

    DateInfo info_AF = malloc(sizeof(*info_AF));
    info_AF->date = 24;
    info_AF->month = 10;
    info_AF->year = 1966;
    map_insert(birthdays, info_AF, "Andreas Foteinakis");

    DateInfo info_ET = malloc(sizeof(*info_ET));
    info_ET->date = 23;
    info_ET->month = 10;
    info_ET->year = 1968;
    map_insert(birthdays, info_ET, "Eva Tasiou");

    DateInfo info_test = malloc(sizeof(*info_test));
    info_test->date = 4;
    info_test->month = 7;
    info_test->year = 2023;
    map_insert(birthdays, info_test, "TEST_DATE");

    printf("I love her");
    return birthdays;
}

void unload_birthdays(Map birthdays) {
    map_destroy(birthdays);
}

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
    unload_birthdays(birthdays);
    free(birthdays);

    //BirthdayInfo bd_info = get_birthday_info(date_info);
    //print_birthday_info(bd_info);
    //free(bd_info);

    


    return 0;
}
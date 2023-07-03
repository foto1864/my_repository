#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tm DayInfo;

int main() {

    time_t t = time(NULL);
    DayInfo day = *localtime(&t);

    // Date is the current date, numbering goes from 1-31
    int date = day.tm_mday;
    // Month has to be month+1 because numbering goes from 0-11
    int month = day.tm_mon + 1;
    // Year has to be year-100 because counting starts from 1900
    int year = day.tm_year - 100;

    int hours = day.tm_hour;
    int minutes = day.tm_min;

    printf("Today's date is %02d/%02d/%02d\n", date, month, year);
    printf("Current time is %d:%d\n", hours, minutes);

    return 0;
}
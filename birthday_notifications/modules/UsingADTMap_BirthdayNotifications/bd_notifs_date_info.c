#include "../../include/Birthday_Notifications.h"

// Gets the information of the current date
DateInfo get_date_info(void) {

    time_t t = time(NULL);
    struct tm day = *localtime(&t);
    
    DateInfo info = malloc(sizeof(*info));
    info->date = day.tm_mday;                  // Get the date
    info->month = day.tm_mon + 1;              // Get the month [Counting is 0 to 11]
    info->year = day.tm_year + 1900;           // Get the year [Years since 1900]
    info->hours = day.tm_hour;                 // Get the hours
    info->minutes = day.tm_min;                // Get the minutes
    
    return info;
}

// Prints the information of the current date
void print_date_info(DateInfo info) {
    // Print The Current Date
    printf("Current date is %02d/%02d/%d\n", info->date, info->month, info->year);
    // Print The Current Time
    printf("Current time is %02d:%02d\n", info->hours, info->minutes);
    return;
}
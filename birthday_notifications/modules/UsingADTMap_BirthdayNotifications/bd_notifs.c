#include "../../include/Birthday_Notifications.h"

int main(void) {

    // Get and print the information of current day
    DateInfo date_info = get_date_info();
    print_date_info(date_info);

    // Load the information of the birthdays
    Map birthdays = load_birthdays();

    // Create a dummy date that will represent the current one
    DateInfo today = malloc(sizeof(*today));
    today->date = date_info->date;
    today->month = date_info->month;
    today->year = date_info->year;

    // Search for the birthdays of current day
    Pointer found = map_find(birthdays, today);

    // Print the found birthday
    printf("Todays is %d's birthday", *(int*)found);

    // Free memory that was allocated dynamically
    free(date_info);
    map_destroy(birthdays); 
    
    return 0;
}
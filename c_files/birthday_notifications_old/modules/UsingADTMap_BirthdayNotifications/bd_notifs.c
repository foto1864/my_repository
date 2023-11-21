#include "../../include/Birthday_Notifications.h"

int main(void) {

    // Get and print the information of current day.
    DateInfo date_info = get_date_info();
    print_date_info(date_info);
    
    // Load the information of the birthdays.
    Map birthdays = load_birthdays();

    // Create a dummy date that will represent the current one.
    DateInfo today = malloc(sizeof(*today));
    today->date = date_info->date;
    today->month = date_info->month;
    today->year = date_info->year;
   
    // Search for, and print the birthdays of current day.
    Pointer found = map_find(birthdays, today);
    if (found != NULL)
        printf("Todays is %s's birthday!\n", (char*) found);    
    else {
        printf("No Birthdays Today!\n");
        // Insert a dummy node, so that we can search for the next. 
        map_insert(birthdays, today, "Dummy");
    }

    // Get the info of the upcoming birthday.
    MapNode next = map_next(birthdays, map_find_node(birthdays, today));
    DateInfo birthday = NULL;

    // If we're looking at the last birthday of the calendar year, the next birthday will be
    // at the start of the map, since the compare function takes into account only 1 calendar year.
    if (next == MAP_EOF) {
        printf("Next birthday coming up is %s ", (char*)map_node_value(birthdays, map_first(birthdays)));
        birthday = map_node_key(birthdays, map_first(birthdays));
    }     
    else { 
        printf("Next birthday coming up is %s ", (char*)map_node_value(birthdays, next));
        birthday = map_node_key(birthdays, next);
    }

    // Finally assign the values and print the info.
    int date = birthday->date;
    int month = birthday->month;
    int year = birthday->year;
    printf("on %02d/%02d (%d years old)\n", date, month, date_info->year - year);

    // After being done with the work, remove the dummy node inserted earlier.
    map_remove(birthdays, today);

    // Get the intentions of the user.
    printf("Do you want to see all upcoming birthdays? (Y/n)  ");
    int ch = getchar();

    // If the answer is YES. (Meaning that the character is 'y' or 'Y').
    if (ch == 89 || ch == 121) {
        printf("\nHere are all the birthdays of the year:\n\n");
        for(MapNode node = map_first(birthdays); 
            node != MAP_EOF; 
            node = map_next(birthdays, node)) {

            DateInfo info = map_node_key(birthdays, node);
            int date = info->date;
            int month = info->month;
            int year = info->year;
            printf("%02d/%02d %s ", date, month, (char*)map_node_value(birthdays, node));    
            printf("(%d years old)\n", date_info->year - year);
        }
        printf("\n");
        printf("You have the birthday information of %d people in total.\n", map_size(birthdays));
    }
    // If the answer is NO. (Meaning that the character is 'n' or 'N').
    else if (ch == 110 || ch == 78) {
        printf("Thank you, Have a nice day!\n");
    }
    // If the character entered is invalid.
    else { 
        fprintf(stderr, "Invalid Character Entered\n");
        exit(1);
    }    

    // Free memory that was allocated dynamically.
    free(date_info);
    map_destroy(birthdays); 
    
    return 0;
}
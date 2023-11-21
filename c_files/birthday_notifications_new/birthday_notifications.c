#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "include/ADTMap.h"
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int date;     // Date 
    int month;    // Month
    int year;     // Year
    int hours;    // Hours
    int minutes;  // Minutes
} info;
typedef info* Info;

int compare_dates(Info, Info);
Info get_date_info(void);
Map load_bday_information(FILE*);
void print_date_info(Info);
void print_todays_birthday(Info, Info);
void print_next_birthday(Map, Info);
void print_all_birthdays(Map, Info);

int main(void) {
    
    Info today = get_date_info();
    print_date_info(today);

    FILE *file; 
    file = fopen("birthdays.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file!");
        return -1;
    }

    Map birthdays = load_bday_information(file);

    Info found = (Info) map_find(birthdays, today);
    if (found == NULL) {
        printf("No Birthdays today!\n");
        print_next_birthday(birthdays, today);
    }
    else {
        print_todays_birthday(found, today);
    }

    printf("Do you want to see all upcoming birthdays? (Y/n)  ");
    int ch = getchar();

    switch (ch) {
    // If the answer is Yes we print the birthdays.
    case 'Y':
        print_all_birthdays(birthdays, today);
        break;
    case 'y':
        print_all_birthdays(birthdays, today);
        break;
    // If the answer is No we print a goodbye message.
    case 'N':
        printf("Thank you for using our program! Have a nice day!\n");
        break;
    case 'n':
        printf("Thank you for using our program! Have a nice day!\n");
        break;
    // In any other case, the user has entered an invalid character.
    default:
        fprintf(stderr, "Invalid Character Entered\n");
        exit(1);
    }

    fclose(file);
    map_destroy(birthdays);
    free(today);

    return 0;
}

// Expected User Input is DD MM YYYY Name Name\n in each line.
Map load_bday_information(FILE *read_file) {

    int num_of_people;
    fscanf(read_file, "%d", &num_of_people);

    Map map = map_create((CompareFunc) compare_dates, free, NULL);

    for (int i=0; i<num_of_people; i++) {
        Info info = malloc(sizeof(*info));
        fscanf(read_file, "%d", &info->date);       // Get the day
        fscanf(read_file, "%d", &info->month);      // Get the month
        fscanf(read_file, "%d", &info->year);       // Get the year

        // Error of Input Checking
        if (info->date > 31 || info->date < 1) {
            fprintf(stderr, "Invalid date entered.\n");
            exit(1);
        }
        if (info->month > 12 || info->month < 1) {
            fprintf(stderr, "Invalid month entered\n");
            exit(1);
        }

        // Will not be needed but good to have been initialized.
        info->hours = 0;        
        info->minutes = 0;      

        // Get the name:     
        getc(read_file);
        int ch;
        int i=0;
        ch = getc(read_file);
        while (ch != '\n' && ch != EOF) {
            info->name[i++] = ch;
            ch = getc(read_file);
        }
        info->name[i] = '\0';
        map_insert(map, info, info->name);
    }

    return map;
}


void print_todays_birthday(Info info, Info today) {
    printf("Today is %s's birthday!", info->name);
    printf(" He/She just turned %d years old!\n", today->year-info->year);
}

// Prints the next upcoming birthday.
void print_next_birthday(Map map, Info today) {
    
    Map birthdays = map;
    Info todays_copy = malloc(sizeof(*todays_copy));
    todays_copy->date = today->date;
    todays_copy->month = today->month;
    todays_copy->year = today->year;

    map_insert(birthdays, todays_copy, "UNKNOWN");
    MapNode next = map_next(birthdays, map_find_node(birthdays, todays_copy));
    if (next == NULL) {
        next = map_first(birthdays);
    }
    Info next_bday = (Info) map_node_value(birthdays, next);
    printf("The next birthday coming up is %s's on %02d/%02d.", next_bday->name, next_bday->date, next_bday->month);
    printf(" He/She will turn %d years old!\n", todays_copy->year-next_bday->year);
    
    map_remove(birthdays, todays_copy);
}

// Prints all the birthdays of the calendar year that are saved.
void print_all_birthdays(Map birthdays, Info today) {
        printf("\nHere are all the birthdays of the year:\n\n");
        for(MapNode node = map_first(birthdays); 
            node != MAP_EOF; 
            node = map_next(birthdays, node))
        {
            Info info = map_node_key(birthdays, node);
            int date = info->date;
            int month = info->month;
            int year = info->year;
            printf("%02d/%02d %s ", date, month, (char*)map_node_value(birthdays, node));    
            printf("(%d years old)\n", today->year - year);
        }
        printf("\n");
        printf("You have the birthday information of %d people in total.\n", map_size(birthdays));
}

// Gets the information of the current date
Info get_date_info(void) {
    time_t t = time(NULL);
    struct tm day = *localtime(&t);
    Info info = malloc(sizeof(*info));

    info->date = day.tm_mday;                  // Get the date
    info->month = day.tm_mon + 1;              // Get the month [Counting is 0 to 11]
    info->year = day.tm_year + 1900;           // Get the year [Years since 1900]
    info->hours = day.tm_hour;                 // Get the hours
    info->minutes = day.tm_min;                // Get the minutes
    
    return info;
}

// Prints the information of the current date
void print_date_info(Info info) {
    printf("Current date is %02d/%02d/%d\n", info->date, info->month, info->year);
    printf("Current time is %02d:%02d\n", info->hours, info->minutes);
    return;
}

// Compare Function that arranges dates in chronological order
int compare_dates(Info info_1, Info info_2){

    Info info_01 = info_1;
    Info info_02 = info_2;

    ///////////////////////////////// TO DO //////////////////////////////////////////
    // Update that needs to be made : What happends if two people share a birthday ///
    //////////////////////////////////////////////////////////////////////////////////

    // If the month of the first date is greater than the month of
    // the second date, then that means that the first date comes 
    // after the second. Same thing happens the other way around. 

    if (info_01->month > info_02->month) 
        return 1;
    else if (info_01->month < info_02->month)
        return -1;

    // If the control flow reaches this point, it means that both dates
    // are of the same month. This means that it depends on the day itself
    // to figure out what date between info_1, info_2 comes first.

    if (info_01->date > info_02->date)
        return 1;
    else if (info_01->date < info_02->date)
        return -1;
    else 
        return 0;    
}
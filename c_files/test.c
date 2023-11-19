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
void print_date_info(Info);
Info get_bday_information(FILE*);
void print_bday_information(Info);

int main(void) {
    
    Info today = get_date_info();
    print_date_info(today);

    FILE *file; 
    file = fopen("birthdays.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file!");
        return -1;
    }

    Map birthdays = map_create((CompareFunc) compare_dates, NULL, NULL);


    int num_of_people = getc(file)-48;
    //Info *info_array = malloc(num_of_people * sizeof(Info)); 
    printf("Number of people is %d\n", num_of_people);

    for (int i=0; i<num_of_people+1; i++) {
        map_insert(birthdays, get_bday_information(file), get_bday_information(file)->name);
        printf("it ran\n");
    }

    Info found = (Info) map_find(birthdays, today);
    if (found == NULL) {
        printf("No Birthdays today!\n");
    }
    else {
        printf("Todays is %s's birthday!\n", found->name);
    }

    printf("The size of the map is %d\n", map_size(birthdays));



    return 0;
}

// Expected User Input is DD MM YYYY Name Name\n in each line.
Info get_bday_information(FILE *read_file) {

    Info info = malloc(sizeof(*info));
    fscanf(read_file, "%d", &info->date);       // Get the day
    fscanf(read_file, "%d", &info->month);      // Get the month
    fscanf(read_file, "%d", &info->year);       // Get the year
    
    // Will not be needed but good to have been initialized.
    info->hours = 0;        
    info->minutes = 0;      

    // Get the name:
    // We first store the name in a temporary buffer because we are
    // going to be making changes to the string before we store it as name.
    char temp_buff[MAX_NAME_LENGTH];
    fgets(temp_buff, MAX_NAME_LENGTH, read_file);
    
    // What this algorithm does is it removes all the spaces from the start
    // and all the line-feeds at the end of the string, so what remains is
    // just the name of the person, so then it can safely be stored as name.
    int length = strlen(temp_buff);
    int start = 0;
    int end = length-1;
    while (start < length && temp_buff[start] == 32)
        start++;
    while (end > 0 && temp_buff[end] == 10)
        end--;
    strncpy(info->name, temp_buff+start, end - start + 1);
    
    return info;
}

void print_bday_information(Info info) {
    printf("The name of the peasant is %s ", info->name);
    printf("and his birthday is on: %02d/%02d/%d.\n", info->date, info->month, info->year);
    return;
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
    // Print The Current Date
    printf("Current date is %02d/%02d/%d\n", info->date, info->month, info->year);
    // Print The Current Time
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
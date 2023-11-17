#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
    int num_of_people = getc(file)-48;
    Info *info_array = malloc(num_of_people * sizeof(Info));
    for (int i=0; i<num_of_people; i++) {
        info_array[i] = get_bday_information(file);
    }
    for (int i=0; i<num_of_people; i++) {
        print_bday_information(info_array[i]);
    }

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
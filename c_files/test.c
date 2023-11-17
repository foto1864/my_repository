#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int date;   // Date 
    int month;  // Month
    int year;   // Year
} info;

typedef info* Info;

Info get_information(void);
void print_information(Info info);

int main(void) {

    int num_of_people;
    scanf("%d", &num_of_people);
    Info *info_array = malloc(num_of_people * sizeof(Info));

    for (int i=0; i<num_of_people; i++) {
        info_array[i] = get_information();
    }
    for (int i=0; i<num_of_people; i++) {
        print_information(info_array[i]);
    }

    return 0;
}

// Expected User Input is DD MM YYYY Name Name\n

Info get_information(void) {

    Info info = malloc(sizeof(*info));
    scanf("%d", &info->date);       // Get the day
    scanf("%d", &info->month);      // Get the month
    scanf("%d", &info->year);       // Get the year

    // Get the name:
    // We first store the name in a temporary buffer because we are
    // going to be making changes to the string before we store it as name.
    char temp_buff[MAX_NAME_LENGTH];
    fgets(temp_buff, MAX_NAME_LENGTH, stdin);
    
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

void print_information(Info info) {
    printf("The name of the peasant is %s ", info->name);
    printf("and his birthday is on: %d/%d/%d.\n", info->date, info->month, info->year);
    return;
}
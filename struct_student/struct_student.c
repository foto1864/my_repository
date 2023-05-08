#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* String;

struct student {
    String first_name;
    String last_name;
    int AM;
};

typedef struct student* Student;

Student student_create(String first_name, String last_name, int AM) {
    Student pointer = malloc(sizeof(struct student));
    pointer->first_name = strdup(first_name);
    pointer->last_name = strdup(last_name);
    pointer->AM = AM;
    return pointer;
}

int main() {
    
    Student student_01 = student_create("Giannis", "Foteinakis", 2200207);
    Student student_02 = student_create("Giorgos", "Dalaras", 2200208);

    printf("The names of the students are: \n");
    printf("%s %s\n", student_01->first_name, student_01->last_name);
    printf("%s %s\n", student_02->first_name, student_02->last_name);

    printf("Their ID's are: \n");
    printf("%d\n", student_01->AM);
    printf("%d\n", student_02->AM);

    free(student_01);
    free(student_02);

    return 0;
}
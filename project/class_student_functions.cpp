#include "include/class_student.h"

int Student::student_count = 0;

uint Student::get_years_joined(void) {
        return years_joined_university;
}
void Student::set_years_joined(uint years) {
        years_joined_university = years;
}

void Student::student_join_course(Course &new_course) {
        // Check if student can join the course
        // Has to be in current semester or earlier
        if (new_course.course_get_semester() >= years_joined_university) {
                int size = courses.size();
                courses[size] = new_course;
        }
        else {
                cout << "You can't join a course in a later semester than the one you're already on." << endl;
        }
}
void Student::student_print_courses(void) {
        for (uint i=0; i < courses.size(); i++) {
                cout << courses[i];
        }
}


Student::Student() { student_count++; }
Student::Student(string n,uint id) : Person(n, id) { student_count++; }
Student::Student(string n, string email, string number, uint year, uint id) : Person(n,email,number,year,id) { student_count++; }
Student::Student(string n, string email, string number, uint year, uint id, uint years_joined) 
        :Person(n,email,number,year,id), years_joined_university(years_joined) { student_count++; }
Student::~Student() { student_count--; }
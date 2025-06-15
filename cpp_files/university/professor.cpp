#include "include/professor.h"
#include "include/course.h"

int Professor::professor_count = 0;

uint Professor::get_years_experience(void) {
        return years_of_experience;
}
void Professor::set_years_of_experience(uint years) {
        years_of_experience = years;
}
void Professor::professor_set_course(Course *new_course) {
        professor_courses[new_course->course_get_name()] = new_course;
}

void Professor::professor_print_courses(void) {
        map<string, Course*>::const_iterator map_iterator;
        cout << "Currently the professor you selected is teaching the following courses:" << endl;
        for (map_iterator = professor_courses.begin(); map_iterator != professor_courses.end(); map_iterator++) {
                cout << *(map_iterator->second) << endl;
        }
}

Course *Professor::professor_find_course(string course_name) {
        map<string, Course*>::iterator map_iterator;
        map_iterator = professor_courses.find(course_name);
        return (map_iterator == professor_courses.end()) ? COURSE_DOES_NOT_EXIST : map_iterator->second;
}


Professor::Professor() { 
        professor_count++; 
}
Professor::Professor(string n,uint id) : Person(n, id) { 
        professor_count++; 
}
Professor::Professor(string n, string email, string number, uint year, uint id) : Person(n,email,number,year,id) { 
        professor_count++; 
}
Professor::Professor(string n, string email, string number, uint year, uint id, uint years_exp) 
        :Person(n,email,number,year,id), years_of_experience(years_exp) { 
        professor_count++; 
}
Professor::~Professor() { 
        professor_count--; 
}
#include "include/student.h"

int Student::student_count = 0;

uint Student::get_years_joined(void) {
        return years_joined_university;
}
void Student::set_years_joined(uint years) {
        years_joined_university = years;
}

Student* Student::student_has_joined_course(string course_name) {
        map<string, Course*>::const_iterator map_iterator;
        map_iterator = student_courses.find(course_name);
        return (map_iterator == student_courses.end()) ? STUDENT_DOES_NOT_EXIST : this;
}

bool Student::student_has_passed_course(string course_name) {
        map<string, Course*>::const_iterator map_iterator;
        map_iterator = student_courses.find(course_name);
        if (map_iterator->second->course_get_grade() > PASSING_MARK) 
                return true;
        return false;
}

uint Student::student_get_course_grade(string course_name) {
        map<string, Course*>::const_iterator map_iterator;
        map_iterator = student_courses.find(course_name);
        return (map_iterator->second->course_get_grade());
}

bool Student::student_join_course(Course *new_course) {
        // Check if student can join the course
        // Has to be in current semester or earlier
        if (new_course->course_get_semester() <= years_joined_university + 1) {
                student_courses[new_course->course_get_name()] = new_course;
                return true;
        }
        else {
                cout << "You can't join a course in a later semester than the one you're already on." << endl;
                return false;
        }
}
void Student::student_print_courses(void) {
        map<string, Course*>::const_iterator map_iterator;
        for (map_iterator = student_courses.begin(); map_iterator != student_courses.end(); map_iterator++) {
                cout << map_iterator->second;
        }
}
void Student::assign_grade_to_course(string course_name, uint grade) {
        map<string, Course*>::iterator map_iterator;
        map_iterator = student_courses.find(course_name);
        map_iterator->second->course_set_grade(grade);
}

void Student::student_print_semester_stats(void) {
        cout << "The statistics of student '" << this->get_name() << "' in the current semester are the following:" << endl; 
        double average_score = 0;
        uint total_courses = 0;
        map<string, Course*>::const_iterator map_iterator;
        for (map_iterator = student_courses.begin(); map_iterator != student_courses.end(); map_iterator++) {
                Course *course = map_iterator->second;
                cout << *course << " Grade:" << course->course_get_grade() << endl;
                average_score += course->course_get_grade();
                total_courses++;
        }
        cout << "Average score: " << average_score/total_courses << endl;
}

void Student::student_print_all_stats(void) {
        cout << "The statistics of student '" << this->get_name() << "' in all semesters are the following:" << endl;
        double average_score = 0;
        uint total_courses = 0;
        map<string, Course*>::const_iterator map_iterator;
        for (map_iterator = student_courses.begin(); map_iterator != student_courses.end(); map_iterator++) {
                Course *course = map_iterator->second;
                if (course->course_get_semester() < years_joined_university + 2) {
                        cout << *course << " Grade: " << course->course_get_grade() << endl;
                        average_score += course->course_get_grade();
                        total_courses++;
                }
        }
        cout << "Average score: " << average_score/total_courses << endl;
}

// In order to graduate, student has to have passed all mandatory classes, plus a certain number of 
// optional classes. The number of optional classes he has to have passed in order to graduate is one 
// such that the total number of ECT points (ECTs) adds up to the value of 98. The value of 98 essentially
// means that the student has passed all of the mandatory classes and at least half of the optional ones.
// The value 98 is defined in the general.h library and is represented as GRADUATION_MINIMUM_SCORE
// The number of total mandatory classes in the university is 8 and is defined in the general.h library with 
// the name TOTAL_MANDATORY_COURSES. So in order to graduate, a student must have passed all TOTAL_MANDATORY_COURSES
// and have a total score greater than or equal to the GRADUATION_MINIMUM_SCORE

bool Student::student_can_graduate(void) {
        map<string, Course*>::const_iterator map_iterator;
        uint total_ECTs = 0;
        uint total_mandatory_courses_passed = 0;
        for (map_iterator = student_courses.begin(); map_iterator != student_courses.end(); map_iterator++) {
                Course *course = map_iterator->second;
                if (student_has_passed_course(course->course_get_name())) {
                        total_ECTs += course->course_get_ECTS();
                        if (course->course_is_mandatory())
                                total_mandatory_courses_passed++;
                }
        }
        if (total_ECTs >= GRADUATION_MINIMUM_SCORE && total_mandatory_courses_passed == TOTAL_MANDATORY_COURSES)
                return true;
        return false;        
}

Student::Student() { 
        student_count++; 
}
Student::Student(string n,uint id) : Person(n, id) { 
        student_count++; 
}
Student::Student(string n, string email, string number, uint year, uint id) : Person(n,email,number,year,id) { 
        student_count++; 
}
Student::Student(string n, string email, string number, uint year, uint id, uint years_joined) 
        :Person(n,email,number,year,id), years_joined_university(years_joined) { 
        student_count++; 
}
Student::~Student() { 
        student_count--; 
}
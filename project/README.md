# OBJECT ORIENTED PROGRAMMING - PROJECT #
# Simulating a University # 

# CONTENTS #

B1. A class "Student" that inherits from the class "Person"
B2. A class "Professor" that inherits from the class "Person"
B3. A class "Course" that takes into account the fact that courses are divided into semesters
B4. Options for the secretary to set the professor of a specific course and for the professor 
to set the grade for a student in that said course.


There exists a menu that is shown to the user, from which he can select what option he wants to use.
Options contain: 
1. Add - Edit - Remove Professor
2. Add - Edit - Remoce Student
3. Add - Edit - Remove Course
4. Set the professor to a course
5. Register to a course (for students)
6. Print a list of the students that have passed a specific course in the current semester
7. Print a professor's statistics for all classes in the current semester
8. Print the average score of a student
9. Print a list of all students that are eligible to graduate from the university
10. Assign a grade to a course (for professors)
11. Exit menu

The menu is such, that the user enters the number of the option he wants to select on the keyboard.
The menu is shown to the user each time that he finishes a process he has already selected. For example, if
the user selects option 4 (Set the professor to a course), when he's done with that option he is again shown the
menu and can exit it by entering the number 11 on the keyboard, meaning he selects option 11 (Exit Menu.)

# PROGRAM FORMAT #

Due to the size of the program, it would not be suitable for it to be in one file, thus it is split into many 
smaller ones. There exists a folder called "database", inside which lie the input files (students.txt, courses.txt,
professors.txt), and also a folder called "include", which contains all of the .h files needed for the program. 
All of the .cpp files are in the main folder, along with the Makefile and the README.md you are reading now.

# BUILD #

In order to run the program, all you have to do is be in the project's repository in terminal and type in the 
command "make". If you want to remove the .o files and the executable at the end you can type "make clean".

# NOTES #

In contrast to what is written in the project's instructions, I have not made a main function that showcases the 
use of the first 4 bullet-points (class student, set professor to course..etc). The reason is simply because of the 
fact the all of the program's utilities are shown and used in the menu that is shown to the user. 

In order to graduate, student has to have passed all mandatory classes, plus a certain number of 
optional classes. The number of optional classes he has to have passed in order to graduate is one 
such that the total number of ECT points (ECTs) adds up to the value of 98. The value of 98 essentially
means that the student has passed all of the mandatory classes and at least half of the optional ones.
The value 98 is defined in the general.h library and is represented as GRADUATION_MINIMUM_SCORE
The number of total mandatory classes in the university is 8 and is defined in the general.h library with 
the name TOTAL_MANDATORY_COURSES. So in order to graduate, a student must have passed all TOTAL_MANDATORY_COURSES
and have a total score greater than or equal to the GRADUATION_MINIMUM_SCORE.
#include "include/class_professor.h"
#include "include/class_person.h"

int Professor::professor_count = 0;

uint Professor::get_years_experience(void) {
        return years_of_experience;
}
void Professor::set_years_of_experience(uint years) {
        years_of_experience = years;
}
Professor::Professor() { professor_count++; }
Professor::Professor(string n,uint id) : Person(n, id) { professor_count++; }
Professor::Professor(string n, string email, string number, uint year, uint id) : Person(n,email,number,year,id) { professor_count++; }
Professor::Professor(string n, string email, string number, uint year, uint id, uint years_exp) 
        :Person(n,email,number,year,id), years_of_experience(years_exp) { professor_count++; }
Professor::~Professor() { professor_count--; }
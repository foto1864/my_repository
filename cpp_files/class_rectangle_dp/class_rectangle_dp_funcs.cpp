#include "class_rectangle_dp.h"

///////////////////////////// Functions Of Class Rectangle //////////////////////////////
double Rectangle::getHeight(void) {
    return height;
}
double Rectangle::getWidth(void) {
    return width;
}
double Rectangle::getArea(void) {
    return width*height;
}
void Rectangle::printDimensions(void) {
    cout << width << " by " << height << "." << endl;
}
// Default Constructor
Rectangle::Rectangle() {
    count++;
}
// Constructor Initializer List
Rectangle::Rectangle(double w, double h): width(w), height(h) {
    count++;
}
// Destructor 
Rectangle::~Rectangle() {
    count--;
}
Rectangle* Rectangle::operator+(const Rectangle &r2) {
    Rectangle* newRect = new Rectangle;
    newRect->height = this->height + r2.height;
    newRect->width = this->width + r2.width;
    return newRect;
}

// Friend Function Of Class Rectangle (TEST)
Rectangle* addRectangle(const Rectangle &r1, const Rectangle &r2) {
    Rectangle *newRect = new Rectangle;
    newRect->height = r1.height+r2.height;
    newRect->width = r1.width+r2.width;
    return newRect;
}
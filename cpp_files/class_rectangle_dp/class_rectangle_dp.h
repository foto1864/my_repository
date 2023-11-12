// Header file for class_rectangle_dp.cpp
#include <iostream>
using namespace std;

class Rectangle {
    private:
        double width;
        double height;
    public:
        static int count;
        double getHeight(void);
        double getWidth(void);
        double getArea(void);
        Rectangle* operator+(const Rectangle &r2);
        friend Rectangle* addRectangle(const Rectangle &r1, const Rectangle &r2);
        void printDimensions(void);
        // Default Constructor
        Rectangle();
        // Constructor Initializer List
        Rectangle(double w, double h);
        // Destructor
        ~Rectangle();
};
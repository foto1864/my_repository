#include <iostream>
using namespace std;

class Rectangle {
    private:
        double width;
        double height;
    public:
        static int count;
        double getHeight(void) {
            return height;
        }
        double getWidth(void) {
            return width;
        }
        double getArea(void) {
            return width*height;
        }
        friend Rectangle* addRectangle(const Rectangle &r1, const Rectangle &r2);
        void printDimensions(void) {
            cout << width << " by " << height << "." << endl;
        }
        // Default Constructor
        Rectangle() {
            cout << "Rec Created." << endl;
            count++;
        }
        // Constructor Initializer List
        Rectangle(double w, double h): width(w), height(h) {
            cout << "Rec Created. " << endl;
            count++;
        }
        // Destructor 
        ~Rectangle() {
            cout << "Rec Destroyed. " << endl;
            count--;
        }
};

Rectangle* addRectangle(const Rectangle &r1, const Rectangle &r2) {
    Rectangle *newRect = new Rectangle;
    newRect->height = r1.height+r2.height;
    newRect->width = r2.width+r2.width;
    return newRect;
}

int Rectangle::count = 0;

int main(void) {

    Rectangle *r1 = new Rectangle;
    Rectangle *r2 = new Rectangle;

    *r1 = Rectangle(4, 5);
    *r2 = Rectangle(5, 6);

    r1->printDimensions();
    r2->printDimensions();


    Rectangle *r3 = addRectangle(*r1, *r2);

    double width = r3->getHeight();
    double height = r3->getWidth();


    double areaR3 = r3->getArea();
    cout << "According to my calculations area of r3 should be: 99m2." << endl;
    cout << "The area of the last rectangle (r3) is " << areaR3 << "m2." << endl;


    return 0;
}
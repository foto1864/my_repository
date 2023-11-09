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
        friend Rectangle* addRectangle(const Rectangle &r1, const Rectangle &r2);
        void printDimensions(void);
        Rectangle();
        Rectangle(double w, double h);
        ~Rectangle();
};

int Rectangle::count = 0;

int main(void) {

    Rectangle *r1 = new Rectangle;
    Rectangle *r2 = new Rectangle;

    *r1 = Rectangle(4, 5);
    *r2 = Rectangle(5, 6);

    r1->printDimensions();
    r2->printDimensions();


    Rectangle *r3 = addRectangle(*r1, *r2);
    r3->printDimensions();

    double width = r3->getHeight();
    double height = r3->getWidth();


    double areaR3 = r3->getArea();
    cout << "According to my calculations area of r3 should be: 99m2." << endl;
    cout << "The area of the last rectangle (r3) is " << areaR3 << "m2." << endl;


    // Free-up previously allocated memory
    delete r1;
    delete r2;
    delete r3;

    return 0;
}
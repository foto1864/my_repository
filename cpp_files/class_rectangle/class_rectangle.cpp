#include <iostream>
#include <cstdlib>
using namespace std;

// Definition of class rectangle
class Rectangle {
    private:
        double width;
        double height;
    public:
        void setWidth(double w) {
            if (w < 0) {
                cout << "Width of a rectangle can't have a negative value. ";
                cout << "Task Terminated." << endl;
                exit(-1);
            }
            else width = w;
        }
        void setHeight(double h) {
            if (h < 0) {
                cout << "Height of a rectangle can't have a negative value. ";
                cout << "Task Terminated." << endl;
                exit(-1);
            }
            else height = h;
        }
        double getWidth(void) { return width; }
        double getHeight(void) { return height; }
        double getArea(void) { return width*height; }
        double getPerimeter(void) { return 2*(width+height); }

        // Constructor Default
        Rectangle() {
            width = 0;
            height = 0;
        }
        // Constructor
        Rectangle(double w, double h) {
            if (w*h <= 0) {
                cout << "Width and height can only be positive. ";
                cout << "Task terminated." << endl;
                exit(1); 
            }
            width = w;
            height = h;
        }
        // Destructor
        ~Rectangle() {
            cout << "Destructor has been executed." << endl;
        }
};

int main(void) {

    Rectangle rec_01(5,6);
    Rectangle rec_02(3,4);

    cout << "Area of rec_01 is " << rec_01.getArea() << endl;
    cout << "Perimeter of rec_01 is " << rec_01.getPerimeter() << endl;
    cout << "Area of rec_02 is " << rec_02.getArea() << endl;
    cout << "Perimeter of rec_02 is " << rec_02.getPerimeter() << endl;

    return 0;
}
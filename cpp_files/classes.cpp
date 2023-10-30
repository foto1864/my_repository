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
                cout << "Task Terminated" << endl;
                exit(-1);
            }
            else width = w;
        }
        void setHeight(double h) {
            if (h < 0) {
                cout << "Height of a rectangle can't have a negative value. ";
                cout << "Task Terminated" << endl;
                exit(-1);
            }
            else height = h;
        }
        double getWidth(void) { return width; }
        double getHeight(void) { return height; }
        double getArea(void) { return width*height; }
        double getPerimeter(void) { return 2*(width+height); }
};

int main(void) {
    Rectangle rec;
    double width, height;

    cout << "Enter the width and height of the rectangle: " << endl;
    cout << "Height: ";
    cin >> height;
    cout << "Width: ";
    cin >> width;

    rec.setHeight(height);
    rec.setWidth(width);

    cout << "Area of rectangle is " << rec.getArea() << endl;
    cout << "Perimeter of rectangle is " << rec.getPerimeter() << endl;
    return 0;
}
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

    Rectangle *recArray = new Rectangle[3];
    
    Rectangle *rec_01 = new Rectangle;
    rec_01->setHeight(5);
    rec_01->setWidth(7);
    
    Rectangle *rec_02 = new Rectangle;
    rec_02->setHeight(6);
    rec_02->setWidth(8);

    recArray[0] = *rec_01;
    recArray[1] = *rec_02;

    for (int i=0; i<2; i++) {
        cout << "Area of rectangle " << i << " is " << recArray[i].getArea() << endl;
        cout << "Perimeter of rectangle " << i << " is " << recArray[i].getPerimeter() << endl;
    }

    return 0;
}
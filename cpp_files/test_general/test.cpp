#include <iostream>
using namespace std;

class Rectangle {
    private:
        double width;
        double height;
    public:
        static int count;
        void printDimensions(void);
        friend Rectangle addRectangle(const Rectangle &r1, const Rectangle &r2);
        Rectangle operator+(const Rectangle &r2);
        Rectangle();
        Rectangle(double w, double h);
        ~Rectangle();
};

// Default Constructor
Rectangle::Rectangle() {
    cout << "Rec Created." << endl;
    count++;
}
// Constructor Initializer List
Rectangle::Rectangle(double w, double h): width(w), height(h) {
    cout << "Rec Created. " << endl;
    count++;
}
// Destructor 
Rectangle::~Rectangle() {
    cout << "Rec Destroyed. " << endl;
    count--;
}
Rectangle Rectangle::operator+(const Rectangle &r2) {
    Rectangle r;
    r.height = this->height + r2.height;
    r.width = this->width + r2.width;
    return r;
}
Rectangle addRectangle(const Rectangle &r1, const Rectangle &r2) {
    Rectangle newRect;
    newRect.height = r1.height+r2.height;
    newRect.width = r2.width+r2.width;
    return newRect;
}
void Rectangle::printDimensions(void) {
    cout << "(" << width << "," << height << ")" << endl;
}

int Rectangle::count = 0;

int main(void) {
    
    Rectangle r1 = Rectangle(3, 4);
    Rectangle r2 = Rectangle(5, 6);
    Rectangle r4 = r1+r2;
    cout << "Dimensions of r4 are ";
    r4.printDimensions(); 
    cout << "In total there are " << Rectangle::count << " rectangles." << endl;
    Rectangle r3 = addRectangle(r1,r2);
    cout << "In total there are " << Rectangle::count << " rectangles." << endl;

    return 0;
}
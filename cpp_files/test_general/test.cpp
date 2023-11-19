#include <iostream>
using namespace std;

class Rectangle {
    private:
        double width;
        double height;
    public:
        static int count;
        void printDimensions(void) const;
        double getArea(void) const;
        friend Rectangle addRectangle(const Rectangle &r1, const Rectangle &r2);
        Rectangle operator+(const Rectangle &r2);
        bool operator>(const Rectangle &r2);
        bool operator<(const Rectangle &r2);
        Rectangle();
        Rectangle(double w, double h);
        ~Rectangle();
};

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
double Rectangle::getArea(void) const{
    return width*height;
}
bool Rectangle::operator>(const Rectangle &r2) {
    if(this->getArea() > r2.getArea())
        return true;
    return false;
}
bool Rectangle::operator<(const Rectangle &r2) {
    if (this->getArea() < r2.getArea())
        return true;
    return false;
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
    newRect.width = r1.width+r2.width;
    return newRect;
}
void Rectangle::printDimensions(void) const{
    cout << "(" << width << "," << height << ")" << endl;
}

int Rectangle::count = 0;

int main(void) {
    
    Rectangle r1 = Rectangle(3, 4);     // Area is 12
    Rectangle r2 = Rectangle(5, 6);     // Area is 30
    
    // Check if operator> works
    if (r1>r2) 
        cout << "R1 has greater area than R2" << endl;
    else if (r2>r1) 
        cout << "R2 has greater area than R1" << endl;
    else 
        cout << "R1 and R2 have the same area" << endl;
    
    Rectangle r4 = r1+r2;   // Dimensions 8*10 area is 80
    cout << "In total there are " << Rectangle::count << " rectangles." << endl;
    cout << "Dimensions of r4 are ";
    r4.printDimensions(); 
    
    double arear4 = r4.getArea();
    cout << "Area of r4 is " << arear4 << endl;
    
    Rectangle r3 = addRectangle(r1,r2); // Area is 80
    cout << "In total there are " << Rectangle::count << " rectangles." << endl;
    cout << "Dimensions of r3 are ";
    r3.printDimensions();
    
    double arear3 = r3.getArea();
    cout << "Area of r3 is " << arear3 << endl;

    // Check if operator< works
    if (r3<r4) 
        cout << "R4 has greater area than R3" << endl;
    else if (r4<r3) 
        cout << "R3 has greater area than R4" << endl;
    else 
        cout << "R3 and R4 have the same area" << endl;
    

    return 0;
}
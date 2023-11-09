#include <iostream>
using namespace std;

class Rectangle {
    private:
        double width;
        double height;
    public:
        static int count;
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
        friend Rectangle addRectangle(const Rectangle &r1, const Rectangle &r2);
};

Rectangle addRectangle(const Rectangle &r1, const Rectangle &r2) {
    Rectangle newRect;
    newRect.height = r1.height+r2.height;
    newRect.width = r2.width+r2.width;
    return newRect;
}

int Rectangle::count = 0;

int main(void) {
    
    Rectangle r1 = Rectangle(3, 4);
    Rectangle r2 = Rectangle(5, 6);
    cout << "In total there are " << Rectangle::count << " rectangles." << endl;
    Rectangle r3 = addRectangle(r1,r2);
    cout << "In total there are " << Rectangle::count << " rectangles." << endl;

    return 0;
}
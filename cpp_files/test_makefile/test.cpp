#include <iostream>
using namespace std;

class Rectangle {
    private:
        double width;
        double height;
    public:
        static int count;
        int getCount() {
            return count;
        }
        Rectangle(double w, double h): width(w), height(h) {
            cout << "Rec Created. " << endl;
            count++;
        }
        ~Rectangle() {
            cout << "Rec Destroyed. " << endl;
            count--;
        }
};

int Rectangle::count = 0;

int main(void) {
    
    Rectangle r1 = Rectangle(3, 4);
    Rectangle r2 = Rectangle(5, 6);

    cout << "In total there are " << Rectangle::count << " rectangles." << endl;

    return 0;
}
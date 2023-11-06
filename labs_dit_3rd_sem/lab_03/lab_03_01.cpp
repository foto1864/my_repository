#include <iostream>
using namespace std;

class Point {
    private:
        float x; // x-coordinate
        float y; // y-coordinate
        void printInfo(void);
    public:
        void set(const float &px, const float &py);
        void print(void);
};

class Triangle {
    private:
        Point a; // Point 1
        Point b; // Point 2
        Point c; // Point 3
    public:
        void set(const Point &pa, const Point &pb, const Point &pc);
        void print(void);
};

////////////////////////// Functions of class Point //////////////////////////

void Point::printInfo(void) {
    cout << "(" << x << "," << y << ")" << endl;
    return;
}

void Point::print(void) {
    printInfo();
    return;
}

void Point::set(const float &px, const float &py) {
    x = px; // Set x-coordinate
    y = py; // Set y-coordinate
    return;
}

////////////////////////// Functions of class Triangle //////////////////////////

void Triangle::set(const Point &pa, const Point &pb, const Point &pc) {
    a = pa; // Set coordinates for Point A.
    b = pb; // Set coordinates for Point B.
    c = pc; // Set coordinates for Point C.
    return;
}

void Triangle::print(void) {
    cout << "The triangle is made out of the following three points: " << endl;
    a.print();
    b.print();
    c.print();
    return;
}


int main(void) {

    Point a, b, c;
    a.set(2, 3);
    b.set(3, 6);
    c.set(4, 9);

    Triangle tr_01;
    tr_01.set(a, b, c);

    cout << endl;
    tr_01.print();

    return 0;
}
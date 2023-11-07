#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Point {
    private:
        double x; // x-coordinate
        double y; // y-coordinate
        void printInfo(void) const;
    public:
        void set(const double &px, const double &py);
        void print(void) const;
        double dist(const Point &p) const;
        bool equal(const Point &p) const;
};

class Triangle {
    private:
        Point a; // Point 1
        Point b; // Point 2
        Point c; // Point 3
    public:
        void set(const Point &pa, const Point &pb, const Point &pc);
        void print(void) const;
        double area(void) const;
        Point get(int index) const;
        bool equal(const Triangle &tr) const;
        bool isTheSame(const Triangle &tr) const;
};


////////////////////////// Functions of class Point //////////////////////////
void Point::printInfo(void) const{
    cout << "(" << x << "," << y << ")" << endl;
    return;
}
void Point::print(void) const{
    printInfo();
    return;
}
void Point::set(const double &px, const double &py) {
    x = px; // Set x-coordinate
    y = py; // Set y-coordinate
    return;
}
double Point::dist(const Point &p) const{
    return sqrt((this->x-p.x)*(this->x-p.x) + (this->y-p.y)*(this->y-p.y));
}
bool Point::equal(const Point &p) const{
    if (this->x == p.x && this->y == p.y)
        return true;
    return false;
}


////////////////////////// Functions of class Triangle //////////////////////////
void Triangle::set(const Point &pa, const Point &pb, const Point &pc) {
    a = pa; // Set coordinates for Point A.
    b = pb; // Set coordinates for Point B.
    c = pc; // Set coordinates for Point C.
    return;
}
void Triangle::print(void) const{
    cout << "The triangle is made out of the following three points: " << endl;
    a.print();
    b.print();
    c.print();
    return;
}
Point Triangle::get(int index) const{
    if (index == 1) 
        return a;
    else if (index == 2)
        return b;
    else if (index == 3)
        return c;
    else {
        cout << "Wrong Usage! Please enter a valid index (1,2,3)." << endl;
        exit(-1);
    }
}
bool Triangle::equal(const Triangle &tr) const{
    if (this->area() == tr.area())
        return true;
    return false;
}
double Triangle::area(void) const{
    double sideA = b.dist(c);
    double sideB = c.dist(a);
    double sideC = a.dist(b);
    double s = (sideA + sideB + sideC)/2; // Semiperimeter
    return sqrt(s*(s-sideA)*(s-sideB)*(s-sideC)); // Heron's Formula
}
bool Triangle::isTheSame(const Triangle &tr) const{
    if (this->a.equal(tr.a) && this->b.equal(tr.b) && this->c.equal(tr.c))
        return true;
    return false;
}


int main(void) {

    Point a, b, c;
    a.set(2, 1);
    b.set(3, 5);
    c.set(4, 6);

    double distAB = a.dist(b);
    cout << "Dist AB is " << distAB << endl; 

    Triangle tr_01;
    tr_01.set(a, b, c);
    double area = tr_01.area();
    cout << "Area of the given triangle is " << area << endl;

    cout << endl;
    tr_01.print();

    return 0;
}
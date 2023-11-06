#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Point {
    private:
        float x; // x-coordinate
        float y; // y-coordinate
        void printInfo(void) const;
    public:
        void set(const float &px, const float &py);
        void print(void) const;
        float dist(const Point &p) const;
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
        float area(void) const;
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
void Point::set(const float &px, const float &py) {
    x = px; // Set x-coordinate
    y = py; // Set y-coordinate
    return;
}
float Point::dist(const Point &p) const{
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
float Triangle::area(void) const{
    float sideA = b.dist(c);
    float sideB = c.dist(a);
    float sideC = a.dist(b);
    float s = (sideA + sideB + sideC)/2; // Semiperimeter
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

    float distAB = a.dist(b);
    cout << "Dist AB is " << distAB << endl; 

    Triangle tr_01;
    tr_01.set(a, b, c);
    float area = tr_01.area();
    cout << "Area of the given triangle is " << area << endl;

    cout << endl;
    tr_01.print();

    return 0;
}
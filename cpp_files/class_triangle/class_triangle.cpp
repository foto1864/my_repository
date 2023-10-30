#include <iostream>
#include <cmath>
using namespace std;

// Class representing a Point in 2D space
class Point {
    private:
        float x;
        float y;
    public:
        void setCoorX(float cx) { x = cx; }
        void setCoorY(float cy) { y = cy; }
        float getCoorX() { return x; }
        float getCoorY() { return y; }
        // Constructor Default 
        Point() {
            x = y = 0;
        }
        // Constructor
        Point(float a, float b) {
            x = a;
            y = b;
        }
};

// Class representing a line in 2D space
class Line {
    private:
        Point a;
        Point b;
    public:
        void setPointA(Point pa) { a = pa; }
        void setPointB(Point pb) { b = pb; }
        float getLength() {
            float base = b.getCoorX() - a.getCoorX();
            float height = b.getCoorY() - a.getCoorY();
            return sqrt(base*base + height*height);
        }
        // Constructor Default
        Line() {
            Point pZero(0,0);
            a = b = pZero;
        }
        // Constructor
        Line(Point pa, Point pb) {
            a = pa;
            b = pb;
        }
};

// Class representing a triangle in 2D space
class Triangle {
    private:
        Point a;
        Point b;
        Point c;
    public:
        void setPointA(Point pa) { a = pa; }
        void setPointB(Point pb) { b = pb; }
        void setPointC(Point pc) { c = pc; }
        float getPerimeter() {
            Line side1(a, b);
            Line side2(a, c);
            Line side3(b, c);
            return side1.getLength() + side2.getLength() + side3.getLength();
        }
        float getArea() {
            Line side1(a, b);
            Line side2(a, c);
            Line side3(b, c);
            float s = Triangle::getPerimeter() / 2.0;
            return sqrt(s*(s-side1.getLength())*(s-side2.getLength())*(s-side3.getLength()));
        }
        // Constructor Default
        Triangle() {
            Point pZero(0,0);
            a = b = c = pZero;
        }
        // Constructor 
        Triangle(Point pa, Point pb, Point pc) {
            a = pa;
            b = pb;
            c = pc;
        }
};

int main(void) {

    cout << "Enter the coordinates of 3 points in 2D space, so that they for a triangle:" << endl;
    cout << "The format is you enter xA, yA then press enter, then xB and yB .." << endl;

    float coorArray[6];
    for (int i=0; i<6; i++) {
        cin >> coorArray[i];
    }
    Point a(coorArray[0], coorArray[1]);
    Point b(coorArray[2], coorArray[3]);
    Point c(coorArray[4], coorArray[5]);

    Triangle triangle_01(a, b, c);
    float perimeter = triangle_01.getPerimeter();
    float area = triangle_01.getArea();

    cout << "Perimeter of constructed triangle is " << perimeter << endl;
    cout << "Area of constructed triangle is " << area << endl;

    return 0;
}
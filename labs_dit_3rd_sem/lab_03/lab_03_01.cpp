#include <iostream>
using namespace std;


class Point {
    private:
        float x;
        float y;
    public:
        void set(float px, float py) {
            x = px;
            y = py;
        }
};

class Triangle {
    private:
        Point a;
        Point b;
        Point c;
    public:
        void set(Point &pa, Point &pb, Point &pc) {
            a = pa;
            b = pb;
            c = pc;
        }
};

int main(void) {

}
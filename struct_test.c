#include <stdio.h>
#include <stdlib.h>

struct {
    int x;
    int y;
} typedef Point;

typedef Point* Point_ptr;

Point_ptr function(int value) {

    Point C;
    Point_ptr C_ptr = &C;
    C.x = value;
    C.y = value;

    return C_ptr;
}

int main() {
 
   Point A;
   Point B;

   A.x = 3;
   A.y = 4;

   B.x = 6;
   B.y = 7;

   printf("Coordinates of Point A are (%d,%d)\n", A.x, A.y);
   printf("Coordinates of Point B are (%d,%d)\n", B.x, B.y);

   Point_ptr function_pointer = function(5);

   int a = function_pointer->x;
   int b = function_pointer->y;

   printf("Coordinates of Point C are (%d,%d)\n", a, b);

   return 0;
}
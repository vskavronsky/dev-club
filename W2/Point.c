#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

void pointPrint(Point a) {
    printf("(%g, %g)", a.x, a.y);
}

int pointEqual(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

double pointDistance(Point a, Point b) {
    return hypot(b.x-a.x, b.y-a.y);
}

int main() {
    Point point1 = {1, 3};
    Point point2 = {8, 3};
    
    pointPrint(point1);
    pointPrint(point2);
    
    printf("%g\n", pointDistance(point1, point2));
    
    if ( pointEqual(point1, point2) ) {
        pointPrint(point1);
        printf(" is equal to " );
        pointPrint(point2);
        printf("\n");
    } else {
        pointPrint(point1);
        printf(" is not equal to " );
        pointPrint(point2);
        printf("\n");
    }
    
    return 0;
}

#include "Point.h"

using namespace std;

int main() {
    Point x(2, 7);
    Point y(3, 8);
    Point z;
    
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;
    
    z.setX(14.85);
    z.setY(23.67);
    
    cout << "z: " << z << endl;
    
    if ( x == y ) {
        cout << x << " is equal to " << y << endl;
    } else {
        cout << x << " is not equal to " << y << endl;
    }
    
    cout << "Distance: " << x.distance(y) << endl; 
    
    return 0;
}

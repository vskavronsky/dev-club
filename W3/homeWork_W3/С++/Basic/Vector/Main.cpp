#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    Vector AB(2, 7);
    Vector CD(3, 8);
    Vector EF;
    
    cout << "AB: " << AB << endl;
    cout << "CD: " << CD << endl;
    cout << "EF: " << EF << endl;
    
    if ( AB == CD ) {
        cout << AB << " is equal to " << CD << endl;
    } else {
        cout << AB << " is not equal to " << CD << endl;
    }
    
    EF.setX(12.34);
    EF.setY(56.789);
    cout << "new EF: " << EF << endl;
    
    Vector sum = AB + CD;
    cout << "sum of AB and CD: " << sum << endl;
     
    Vector diff = AB - CD;
    cout << "diff of AB and CD: " << diff << endl;
    
    AB += CD;
    cout << "new AB: " << AB << endl;
    
    CD -= AB;
    cout << "new CD: " << CD << endl;
     
    cout << "Length of vector AB: " << AB.len() << endl; 
    cout << "Length of vector CD: " << CD.len() << endl;
    cout << "Length of vector EF: " << EF.len() << endl; 
    
    return 0;
}

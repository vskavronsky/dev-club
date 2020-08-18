#include "List.h"

using namespace std;

int main() {
    try {
        List a(10, 2);
        // List b;
        
        for ( int i = 0; i < 10; i++ ) {
            a.push_back(i);
        }
        // for ( int j = 1; j < 11; j++ ) {
            // b.push_back(j);
        // }
        cout << a << endl;
        cout << a.max_size() << endl;
        a.insert(765, 4);
        cout << a << endl;
        cout << a.max_size() << endl;
        // cout << b << endl;
        // cout << b.size() << endl;
        // int notEqual = a!=b;
        // int equal = a==b;
        // cout << "notEqual - " << notEqual << endl;
        // cout << "equal - " << equal << endl;
        // cout << "index - " << a[2] << endl;
    }
    catch (const OutOfMemoryException& exception) {
        cout << "Not enough memory!" << endl;
    }
    catch (const ZeroLenException& exception) {
        cout << "Current size of the array is equal to zero! Please, fill the array by integer numbers." << endl;
    }
    
    return 0;
}

#include "MyVector.h"

using namespace std;

int main() {
    try {
        MyVector<int> *a = new MyVector<int>(10, 2);
        MyVector<double> *b = new MyVector<double>(10, 3);
        
        for ( int i = 0; i < 10; i++ ) {
            a->push_back(i);
        }
        
        for ( double j = 1.38; j < 11; j += 1.1 ) {
            b->push_back(j);
        }
        
        cout << *a << endl;
        cout << a->max_size() << endl;
        a->insert(765, 4);
        cout << *a << endl;
        cout << a->max_size() << endl;
        
        cout << *b << endl;
        cout << b->max_size() << endl;
        
        delete a;
        delete b;
    }
    catch (const OutOfMemoryException& exception) {
        cout << "Not enough memory!" << endl;
    }
    catch (const ZeroLenException& exception) {
        cout << "Current size of the array is equal to zero! Please, fill the array by integer numbers." << endl;
    }
    
    return 0;
}

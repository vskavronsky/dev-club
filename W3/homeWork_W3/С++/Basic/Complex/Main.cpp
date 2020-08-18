#include "Complex.h"

using namespace std;

int main() {
    Complex num1(2, 7);
    Complex num2(3, -8);
    Complex num3;
    
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "num3: " << num3 << endl;
    
    if ( num1 == num2 ) {
        cout << num1 << " is equal to " << num2 << endl;
    } else {
        cout << num1 << " is not equal to " << num2 << endl;
    }
    
    Complex sum = num1 + num2;
    cout << "sum of num1 and num2: " << sum << endl;
     
    Complex diff = num1 - num2;
    cout << "diff of num1 and num2: " << diff << endl;
    
    Complex product = num1 * num2;
    cout << "product of num1 and num2: " << product << endl;
    
    num1 += num2;
    cout << "new num1: " << num1 << endl;
    
    num2 -= num1;
    cout << "new num2: " << num2 << endl;
    
    return 0;
}

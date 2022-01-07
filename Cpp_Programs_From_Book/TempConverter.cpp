#include <iostream>

const double COEFF1 = 1.8;
const int COEFF2 = 32;

int main(int nNumberOfArgs, char* pszArgs[]) {
    double celsius;  // instruction
    double fahrenheit;

    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;  // instruction
    
    fahrenheit = celsius * COEFF1 + COEFF2;  // expression (because of math operations)

    std::cout << "Temperature in Fahrenheit is " << fahrenheit << std::endl;  // instruction

    return 0;
}

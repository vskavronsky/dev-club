#include <iostream>

// preprocessor substitutes SQUARE(X) by ((X) * (X))
#define SQUARE(X) ((X) * (X))

// compiler may or may not substitutes function call square1(2) by x * x  
inline int square1(int x) { return x * x; }

// works at compile time
// works only with literal types (char, int, double, void) 
constexpr int square2(int x) { return x * x; }

int main() {
    int x = 3;
    std::cout << "x = " << x << std::endl;
    int nSQ = square2(x++);
    std::cout << "SQUARE(x++) = " << nSQ << std::endl;
    std::cout << "Now x = " << x << std::endl;

    return 0;
}

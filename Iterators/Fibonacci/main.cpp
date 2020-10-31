#include <iostream>
#include "Fibonacci.hpp"

int main() {
    Fibonacci* posRange = new Fibonacci(21);

    std::cout << "Fibonacci positive values:";

    for ( ; !posRange->over(); (*posRange)++ ) {
        std::cout << " " << *posRange;
    }
    std::cout << std::endl;

    delete posRange;
    posRange = nullptr;

    Fibonacci* negRange = new Fibonacci(-21);

    std::cout << "Fibonacci negative values:";

    for ( ; !negRange->over(); (*negRange)-- ) {
        std::cout << " " << *negRange;
    }
    std::cout << std::endl;

    delete negRange;
    negRange = nullptr;

    return 0;
}

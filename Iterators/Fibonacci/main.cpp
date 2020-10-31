#include <iostream>
#include "FibonacciIter.hpp"

int main() {
    FibonacciIter* posRange = new FibonacciIter(21);

    std::cout << "Fibonacci positive values:";
    
    for ( ; !posRange->over(); (*posRange)++ ) {
        std::cout << " " << *posRange;
    }
    std::cout << std::endl;

    delete posRange;
    posRange = nullptr;

    FibonacciIter* negRange = new FibonacciIter(-21);

    std::cout << "Fibonacci negative values:";

    for ( ; !negRange->over(); (*negRange)-- ) {
        std::cout << " " << *negRange;
    }
    std::cout << std::endl;

    delete negRange;
    negRange = nullptr;

    return 0;
}

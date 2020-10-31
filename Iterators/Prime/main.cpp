#include <iostream>
#include "PrimeIter.hpp"

int main() {
    PrimeIter* range = new PrimeIter(5);

    std::cout << "Range:";
    for ( ; !range->end(); ++(*range) ) {
        std::cout << " " << *range;
    }
    std::cout << std::endl;

    range->getPrimes();

    std::cout << "=========================" << std::endl;

    range->setLimit(10);

    std::cout << "Range:";
    for ( ; !range->end(); (*range)++ ) {
        std::cout << " " << *range;
    }
    std::cout << std::endl;

    range->getPrimes();

    std::cout << "=========================" << std::endl;

    range->setLimit(5);

    std::cout << "Range:";
    for ( ; !range->end(); ++(*range) ) {
        std::cout << " " << *range;
    }
    std::cout << std::endl;

    range->getPrimes();

    std::cout << "=========================" << std::endl;

    std::cout << "Range:";
    for ( ; !range->begin(); ) {
        --(*range);
        std::cout << " " << *range;
    }
    std::cout << std::endl;

    range->getPrimes();

    std::cout << "=========================" << std::endl;

    std::cout << "Range:";
    for ( ; !range->end(); ++(*range) ) {
        std::cout << " " << *range;
    }
    std::cout << std::endl;

    range->getPrimes();

    delete range;
    range = nullptr;

    return 0;
}

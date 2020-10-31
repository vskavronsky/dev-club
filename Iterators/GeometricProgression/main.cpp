#include <iostream>
#include "GeometricProgIter.hpp"

int main() {
    GeometricProgIter* range = new GeometricProgIter(3, -2, 10);

    std::cout << "Range:";
    for ( ; !range->over(); (*range)++ ) {
        std::cout << " " << *range;
    }
    std::cout << std::endl;

    delete range;
    range = nullptr;

    return 0;
}

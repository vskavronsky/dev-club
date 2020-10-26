#include <iostream>
#include "GeometricProg.hpp"

int main() {
    GeometricProg* range = new GeometricProg(3, -2, 10);

    std::cout << "Range:";

    for ( ; !range->over(); (*range)++ ) {
        std::cout << " " << *range;
    }
    std::cout << std::endl;

    delete range;
    range = nullptr;

    return 0;
}

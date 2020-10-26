#include <iostream>
#include "ArithmeticProg.hpp"

int main() {
    ArithmeticProg* range = new ArithmeticProg(2, 3, 20);

    std::cout << "Range:";

    for ( ; !range->over(); ++(*range) ) {
        std::cout << " " << *range;
    }
    std::cout << std::endl;

    delete range;
    range = nullptr;

    return 0;
}

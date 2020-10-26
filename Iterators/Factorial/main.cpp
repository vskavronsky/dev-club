#include <iostream>
#include "Factorial.hpp"

int main() {
    Factorial* range = new Factorial(8);

    std::cout << "Range:";

    for ( ; !range->over(); ++(*range) ) {
        std::cout << " " << *range;
    }
    std::cout << std::endl;

    delete range;
    range = nullptr;

    return 0;
}

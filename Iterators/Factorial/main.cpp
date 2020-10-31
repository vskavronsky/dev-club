#include <iostream>
#include "FactorialIter.hpp"

int main() {
    FactorialIter* range = new FactorialIter(8);

    std::cout << "Range:";
    for ( ; !range->over(); ++(*range) ) {
        std::cout << " " << *range;
    }
    std::cout << std::endl;

    delete range;
    range = nullptr;

    return 0;
}

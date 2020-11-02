#include <iostream>
#include "ArrayIter.hpp"

int main() {
    int size = 10;
    double* array = new double[size];

    for ( int i = 0; i < size; ++i ) {
        array[i] = i * 2.094 + 1.37;
    }

    ArrayIter<double>* rangeDouble = new ArrayIter<double>(array, size);

    std::cout << "Double Range:";
    for ( ; !rangeDouble->end(); ++(*rangeDouble) ) {
        std::cout << " " << *rangeDouble;
    }
    std::cout << std::endl;

    std::cout << "Double Range:";
    for ( ; !rangeDouble->begin(); ) {
        --(*rangeDouble);
        std::cout << " " << *rangeDouble;
    }
    std::cout << std::endl;

    delete[] array;
    array = nullptr;

    delete rangeDouble;
    rangeDouble = nullptr;

    std::cout << "===========================================================================" << std::endl;

    int arrSize = 26;
    char* arrayChar = new char[arrSize];

    char j = 'a';
    for ( int i = 0; i < arrSize; ++i ) {
        arrayChar[i] = j + i;
    }

    ArrayIter<char>* rangeChar = new ArrayIter<char>(arrayChar, arrSize);

    std::cout << "Char Range:";
    for ( ; !rangeChar->end(); ++(*rangeChar) ) {
        std::cout << " " << *rangeChar;
    }
    std::cout << std::endl;

    std::cout << "Char Range:";
    for ( ; !rangeChar->begin(); ) {
        --(*rangeChar);
        std::cout << " " << *rangeChar;
    }
    std::cout << std::endl;

    delete[] arrayChar;
    arrayChar = nullptr;

    delete rangeChar;
    rangeChar = nullptr;

    return 0;
}

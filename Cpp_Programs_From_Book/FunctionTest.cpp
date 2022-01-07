#include <iostream>

void displayExplanation(void) {
    std::cout << "This programm add the sequence of the numbers, entered by user" << std::endl;
    std::cout << "The addition will end, when user entered 0 number" << std::endl;
    std::cout << "The program will end, when sum is less or equal 0" << std::endl << std::endl;
    
    return;
}

int sumSequence(void) {
    int accumulator = 0;

    for ( ; ; ) {
        int value;
        std::cout << "Enter the number: ";
        std::cin >> value;

        if ( value == 0 ) {
            break;
        }
        accumulator += value;
    }
    
    return accumulator;
}

int main() {
    int accumulatedValue;
    
    displayExplanation();

    for ( ; ; ) {
        std::cout << "Enter the sequence of the numbers:" << std::endl;

        accumulatedValue = sumSequence();

        if ( accumulatedValue <= 0 ) {
            break;
        }
        std::cout << "Total sum of the numbers: " << accumulatedValue << std::endl << std::endl;
    }

    std::cout << "Total sum of the numbers: " << accumulatedValue << std::endl << std::endl;

    return 0;
}

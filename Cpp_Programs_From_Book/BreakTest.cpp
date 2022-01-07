#include <iostream>

int main() {
    int accumulator = 0;
    
    std::cout << "This programm add numbers, entered by user" << std::endl
              << "The addition will end, when user entered zero number" << std::endl;

    for ( ; ; ) {
        int value;
        std::cout << "Enter the number: ";
        std::cin >> value;

        if ( value < 0 ) {
            continue;
        } else if (value == 0) {
            break;
        }
        accumulator += value;
    }

    std::cout << "Total sum of the numbers: " << accumulator << std::endl;

    return 0;
}

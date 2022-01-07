#include <iostream>

int main() {
    int arg1;
    std::cout << "Enter arg1: ";
    std::cin >> arg1;

    int arg2;
    std::cout << "Enter arg2: ";
    std::cin >> arg2;

    if ( arg1 > arg2 ) {
        std::cout << "arg1 is greater than arg2" << std::endl;
    } else {
        std::cout << "arg1 is less than arg2" << std::endl;
    }

    return 0;
}

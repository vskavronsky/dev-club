#include <iostream>

int main() {
    for ( ; ; ) {
        double num1;
        std::cout << "Enter the first number : ";
        std::cin >> num1;

        double num2;
        std::cout << "Enter the second number: ";
        std::cin >> num2;

        char operation;
        std::cout << "Choose operation -> '+', '-', '*', '/', '%': ";
        std::cin >> operation;

        switch (operation) {
        case '+':
            std::cout << "The sum of the numbers: " << num1 + num2 << std::endl << std::endl;
            break;
        case '-':
            std::cout << "The subtraction of the numbers: " << num1 - num2 << std::endl << std::endl;
            break;
        case '*':
            std::cout << "The multiplication of the numbers: " << num1 * num2 << std::endl << std::endl;
            break;
        case '/':
            std::cout << "The division of the numbers: " << num1 / num2 << std::endl << std::endl;
            break;
        case '%':
            std::cout << "The modulo of the numbers: " << static_cast<int>(num1) % static_cast<int>(num2) << std::endl << std::endl;
            break;
        default:
            std::cout << "You entered incorrect operation." << std::endl << std::endl;
            break;
        }
    }
    
    return 0;
}

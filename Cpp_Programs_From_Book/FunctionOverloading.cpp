#include <iostream>

int sum(int lhs, int rhs) {
    return lhs + rhs;
}

double sum(double lhs, double rhs) {
    return lhs + rhs;
}

char sum(char lhs, char rhs) {
    return lhs + rhs;
}

int main() {
    int iArg1 = 2, iArg2 = 3;
    double dArg1 = 2.5, dArg2 = 3.4;
    char cArg1 = 'h', cArg2 = 'i';

    std::cout << "int sum: " << iArg1 << " + " << iArg2 << " = " << sum(iArg1, iArg2) << std::endl;
    std::cout << "double sum: " << dArg1 << " + " << dArg2 << " = " << sum(dArg1, dArg2) << std::endl;
    std::cout << "char sum: " << cArg1 << " + " << cArg2 << " = " << sum(cArg1, cArg2) << std::endl;

    return 0;
}

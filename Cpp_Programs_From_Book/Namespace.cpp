#include <iostream>

namespace MathInt {
    int sum(int a, int b) {
        return a + b;
    }
}

namespace MathDouble {
    double sum(double a, double b) {
        return a + b;
    }
}

int main() {
    int nX = 2, nY = 3;
    double dX = 5.1, dY = 4.4;

    std::cout << "Int sum: " << MathInt::sum(nX, nY) << std::endl;
    std::cout << "Double sum: " << MathDouble::sum(dX, dY) << std::endl;

    return 0;
}

#include <iostream>

double* child(void) {
    // WARNING C4172:
    // A function returns the address of a local variable or temporary object.
    // Local variables and temporary objects are destroyed when a function returns,
    // so the address returned is not valid.
    // To fix, use operators new/delete.
    double* pdLocal = new double;
    return pdLocal;
}

void parent(void) {
    double* pdMyLocal = child();
    *pdMyLocal = 1.2;

    std::cout << "pdMyLocal = " << *pdMyLocal << std::endl;
    
    delete pdMyLocal;
    pdMyLocal = 0;
}

int main() {
    parent();

    return 0;
}

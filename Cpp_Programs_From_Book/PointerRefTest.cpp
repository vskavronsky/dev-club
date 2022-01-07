#include <iostream>

void passByValue(int nValue);
void passByPointer(int* pValue);
void passByReference(int& rValue);

void constValue(int nValue);
void constPointer(int nValue);

int main() {
    int value = 0;

    passByValue(value);
    std::cout << "After call passByValue function: " << value << std::endl;

    passByPointer(&value);
    std::cout << "After call passByPointer function: " << value << std::endl;

    passByReference(value);
    std::cout << "After call passByReference function: " << value << std::endl;

    std::cout << "After call constValue function:" << std::endl;
    constValue(value);

    std::cout << "After call constPointer function:" << std::endl;
    constPointer(value);

    return 0;
}

void passByValue(int nValue) {
    nValue = 10;
}

void passByPointer(int* pValue) {
    *pValue = 20;
}

void passByReference(int& rValue) {
    rValue = 30;
}

void constValue(int nValue) {
    // pointer: points to a const cell of the memory
    const int* pInt;
    pInt = &nValue;
    //*pInt = 10; 

    std::cout << "- Can assign to pointer different adresses, but cannot modify const variable: " << *pInt << std::endl;
}

void constPointer(int nValue) {
    int temp = nValue;
    int nVar = 40;
    int* const cpInt = &nValue;
    *cpInt = nVar;
    //cpInt = &nVar;

    std::cout << "- Cannot assign to pointer different adresses, but can modify variable:\n" <<
        "- Before: " << temp << ", " << "After: " << *cpInt << std::endl;
}

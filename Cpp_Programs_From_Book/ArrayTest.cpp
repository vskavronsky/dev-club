#include <iostream>

const int SIZE = 128;

void displayExplanation(void);
int readArray(int arr[], int sizeOfArray);
void displayArrayByIndex(int arr[], int numOfElements);
void displayArrayByPointer(int arr[], int numOfElements);
int sumArray(int arr[], int numOfElements);

int main() {
    displayExplanation();

    int arr[SIZE];
    int numOfElements = readArray(arr, SIZE);

    // displayArrayByIndex(arr, numOfElements);
    displayArrayByPointer(arr, numOfElements);

    std::cout << "The sum of the entered numbers: " << sumArray(arr, numOfElements) << std::endl;

    return 0;
}

void displayExplanation(void) {
    std::cout << "This programm add the sequence of the numbers, entered by user" << std::endl;
    std::cout << "The addition will end, when user entered 0 number" << std::endl << std::endl;

    return;
}

int readArray(int arr[], int sizeOfArray) {
    int numOfElements = 0;

    for ( int i = numOfElements; i < sizeOfArray; ++i ) {
        int value;
        std::cout << "Enter the number: ";
        std::cin >> value;

        if ( value == 0 ) {
            break;
        }
        arr[i] = value;
        numOfElements += 1;
    }
    return numOfElements;
}

void displayArrayByIndex(int arr[], int numOfElements) {
    std::cout << std::endl << "The numbers in array:" << std::endl;

    for ( int i = 0; i < numOfElements; ++i ) {
        std::cout.width(10);
        std::cout << "Index " << i << ": " << arr[i] << std::endl;
    }
    std::cout << std::endl;
}

void displayArrayByPointer(int arr[], int numOfElements) {
    std::cout << std::endl << "The numbers in array:" << std::endl;
    // will work with arr, arr here, local variable
    int* pArray = arr;

    for ( int i = 0; i < numOfElements; ++i, ++pArray ) {
        std::cout.width(10);
        std::cout << "Index " << i << ": " << *pArray << std::endl;
    }
    std::cout << std::endl;
}

int sumArray(int arr[], int numOfElements) {
    int accumulator = arr[0];

    for ( int i = 1; i < numOfElements; ++i ) {
        accumulator += arr[i];
    }
    return accumulator;
}

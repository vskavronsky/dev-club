#include <iostream>
#include <cstring>

const int SIZE = 255;
const int LIMIT = 765;

void concatString(char szTarget[], const char szSource[]);

int main() {
    char szConcatenator[LIMIT] = "";
    
    char szString1[SIZE];
    std::cout << "Enter the first string: ";
    std::cin.getline(szString1, SIZE);
    
    char szDelimiter[SIZE];
    std::cout << "Enter the delimiter: ";
    std::cin.getline(szDelimiter, SIZE);
    
    char szString2[SIZE];
    std::cout << "Enter the second string: ";
    std::cin.getline(szString2, SIZE);

    concatString(szConcatenator, szString1);
    concatString(szConcatenator, szDelimiter);
    concatString(szConcatenator, szString2);

    std::cout << "Concatenated string: " << szConcatenator << std::endl;
    std::cout << "The string lengths: " << strlen(szConcatenator) << std::endl;

    return 0;
}

void concatString(char szTarget[], const char szSource[]) {
    int targetIndex = 0;

    while ( szTarget[targetIndex] ) {
        targetIndex += 1;
    }

    for ( int sourceIndex = 0; szSource[sourceIndex]; ++sourceIndex, ++targetIndex ) {
        szTarget[targetIndex] = szSource[sourceIndex];
    }
    szTarget[targetIndex] = '\0';
}

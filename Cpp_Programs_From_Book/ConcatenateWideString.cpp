#include <iostream>
#include <cwchar>

const int SIZE = 255;
const int LIMIT = 765;

int main() {
    wchar_t szConcatenator[LIMIT] = L"";  // L"" -> L - identifies wide char array 
    
    wchar_t szString1[SIZE];
    std::cout << "Enter the first string: ";
    std::wcin.getline(szString1, SIZE);

    wchar_t szDelimiter[SIZE];
    std::cout << "Enter the delimiter: ";
    std::wcin.getline(szDelimiter, SIZE);

    wchar_t szString2[SIZE];
    std::cout << "Enter the second string: ";
    std::wcin.getline(szString2, SIZE);

    wcscat_s(szConcatenator, szString1);
    wcscat_s(szConcatenator, szDelimiter);
    wcscat_s(szConcatenator, szString2);

    std::wcout << L"Concatenated string: " << szConcatenator << std::endl;
    std::wcout << L"The string lengths: " << wcslen(szConcatenator) << std::endl;

    return 0;
}

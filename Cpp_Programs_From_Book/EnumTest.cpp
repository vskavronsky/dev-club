#include <iostream>

// All enum types are implemented as a built-in integral type known as the underlying type.
// In C, the underlying type is always int. In C++03, the underlying type is implementation-defined.
// An implementation is free to choose an arbitrary integral type (char, short, int, long, and their unsigned counterparts)
// as an enum’s underlying type.

// Unscope enumeration
// May occurs collision with values names with another enums values names
// Automatically converts to int
enum COLOR : int {
    red,
    green,
    blue
};

struct X {
    enum DIRECTION {
        left = 'l',
        right = 'r'
    };
};

// Scope enumeration
// More secure than enum, user define type
enum class ALTITUDE : char {
    high = 'h',
    low = 'l'
};

struct S {
    // using enum ALTITUDE; c++20
    enum class ALTITUDE : char {
        high = 'h',
        low = 'l'
    };
};

int main() {
    X x;
    X* px = &x;

    int a = X::DIRECTION::left;
    int b = X::left;
    int c = x.left;
    int d = px->left;

    std::cout << "Enum:" << std::endl;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    COLOR y = blue;
    std::cout << "y = " << y << std::endl;
    
    std::cout << "-------------------------" << std::endl;

    S s;
    S* ps = &s;
    
    char h = static_cast<char>(S::ALTITUDE::high);
    // char e = static_cast<char>(S::high); c++20
    // char f = static_cast<char>(s.high); c++20
    // char g = static_cast<char>(ps->high); c++20

    std::cout << "Enum Class:" << std::endl;

    std::cout << "h = " << h << std::endl;

    ALTITUDE l = ALTITUDE::low;
    std::cout << "l = " << static_cast<char>(l) << std::endl;

    return 0;
}

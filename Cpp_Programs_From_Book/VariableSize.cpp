#include <iostream>

int main() {
    bool b;
    char c;
    wchar_t wc;
    int n;
    long l;
    long long ll;
    float f;
    double d;
    long double ld;

    std::cout << "Bool size: " << sizeof(b) << std::endl;
    std::cout << "Char size: " << sizeof(c) << std::endl;
    std::cout << "WChar size: " << sizeof(wc) << std::endl;
    std::cout << "Int size: " << sizeof(n) << std::endl;
    std::cout << "Long size: " << sizeof(l) << std::endl;
    std::cout << "Long long size: " << sizeof(ll) << std::endl;
    std::cout << "Float size: " << sizeof(f) << std::endl;
    std::cout << "Double size: " << sizeof(d) << std::endl;
    std::cout << "Long double size: " << sizeof(ld) << std::endl;

    std::cout << std::endl;

    std::cout.setf(std::ios::hex);
    std::cout.unsetf(std::ios::dec);

    std::cout << "&b: " << &b << std::endl;
    std::cout << "&c: " << static_cast<void *>(&c) << std::endl;
    std::cout << "&wc: " << static_cast<void *>(&wc) << std::endl;
    std::cout << "&n: " << &n << std::endl;
    std::cout << "&l: " << &l << std::endl;
    std::cout << "&ll: " << &ll << std::endl;
    std::cout << "&f: " << &f << std::endl;
    std::cout << "&d: " << &d << std::endl;
    std::cout << "&ld: " << &ld << std::endl;
    
    return 0;
}

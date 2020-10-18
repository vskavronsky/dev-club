#include <iostream>
#include "Mohican.hpp"

int main() {
    Mohican* stas = new Mohican("Stas", 15);
    Mohican* john = new Mohican("John", 43);
    Mohican* mike = new Mohican("Mike", 27);
    Mohican* bob = new Mohican(*stas);

    std::cout << *stas << std::endl;
    std::cout << *john << std::endl;
    std::cout << *mike << std::endl;
    std::cout << *bob << std::endl;

    std::cout << "Last Mohican-> " << Mohican::getLast() << std::endl << std::endl;

    delete john;
    john = nullptr;

    std::cout << *stas << std::endl;
    std::cout << *mike << std::endl;
    std::cout << *bob << std::endl;

    std::cout << "Last Mohican-> " << Mohican::getLast() << std::endl << std::endl;

    delete stas;
    stas = nullptr;

    delete mike;
    mike = nullptr;

    delete bob;
    bob = nullptr;

    return 0;
}

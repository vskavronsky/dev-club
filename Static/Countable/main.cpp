#include <iostream>
#include "Countable.hpp"
#include "Journal.hpp"

int main() {
    Journal* pink = new Journal("Pink", 4.99);
    Journal* zebra = new Journal("Zebra", 1.20);
    Journal* newtimes = new Journal(*pink);
    Journal* natali = new Journal("Natali", 6.59);

    std::cout << *pink << std::endl;
    std::cout << *zebra << std::endl;
    std::cout << *newtimes << std::endl;
    std::cout << *natali << std::endl;

    std::cout << "Total Journals: " << Journal::getTotalCount() << std::endl << std::endl;

    delete newtimes;
    newtimes = nullptr;

    std::cout << *pink << std::endl;
    std::cout << *zebra << std::endl;
    std::cout << *natali << std::endl;

    std::cout << "Total Journals: " << Journal::getTotalCount() << std::endl;

    delete pink;
    pink = nullptr;

    delete zebra;
    zebra = nullptr;

    delete natali;
    natali = nullptr;

    return 0;
}

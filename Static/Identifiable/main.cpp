#include <iostream>
#include "Identifiable.hpp"
#include "Journal.hpp"

int main() {
    Journal* natali = new Journal("Natali", 6.99);
    Journal* forbes = new Journal(*natali);

    std::cout << *natali << std::endl;
    std::cout << *forbes << std::endl;

    Journal* spike = new Journal("Spike", 2.98);
    Journal* playboy = new Journal("PlayBoy", 10.59);

    *spike = *playboy;

    std::cout << *spike << std::endl;
    std::cout << *playboy << std::endl;

    delete natali;
    natali = nullptr;

    delete forbes;
    forbes = nullptr;

    delete spike;
    spike = nullptr;

    delete playboy;
    playboy = nullptr;

    return 0;
}

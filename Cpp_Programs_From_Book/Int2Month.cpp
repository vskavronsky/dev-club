#include <iostream>

const char* months[] = {
    "Error",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

const char* intToMonth(const int nMonth);

int main() {
    int nMonth;
    std::cout << "Enter month number: ";
    std::cin >> nMonth;

    std::cout << nMonth << " = " << intToMonth(nMonth) << std::endl;

    return 0;
}

const char* intToMonth(const int nMonth) {
    if ( nMonth < 1 || nMonth > 12 ) {
        return months[0];
    }
    return months[nMonth];
}

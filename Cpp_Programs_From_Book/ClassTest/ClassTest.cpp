#include <iostream>
#include "Savings.h"

int main() {
    std::cout << "Enter account number and your balance:" << std::endl;
    
    Savings mySave;
    std::cin >> mySave.accountNumber;
    std::cin >> mySave.balance;
    
    std::cout << "Account Number: " << mySave.accountNumber << std::endl;
    std::cout << "Balance: " << mySave.balance << std::endl << std::endl;

    mySave.recharge(10.25);

    std::cout << "After recharge:" << std::endl;
    std::cout << "Account Number: " << mySave.accountNumber << std::endl;
    std::cout << "Balance: " << mySave.balance << std::endl;

    return 0;
}

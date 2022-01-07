#pragma once

class Savings {
public:
    unsigned accountNumber;
    double balance;

    void recharge(double amount) {
        this->balance += amount;
    }
};

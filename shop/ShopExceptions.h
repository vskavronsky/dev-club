#ifndef SHOPEXCEPTIONS_H
#define SHOPEXCEPTIONS_H

#include <iostream>

class ShopExceptions : public std::exception {};

class InvalidParameterMoney : public ShopExceptions {
    public:
        const char* what() const noexcept;

};

class InvalidParameterPrice : public ShopExceptions {
    public:
        const char* what() const noexcept;

};

class OutOfMoney : public ShopExceptions {
    public:
        const char* what() const noexcept;

};

class NotEnoughMoney : public ShopExceptions {
    public:
        const char* what() const noexcept;

};

class CategoryWithoutItems : public ShopExceptions {
    public:
        const char* what() const noexcept;

};

class CustomerWithoutOrders : public ShopExceptions {
    public:
        const char* what() const noexcept;

};

class ItemWithoutOrders : public ShopExceptions {
    public:
        const char* what() const noexcept;

};

class OrderWitoutItems : public ShopExceptions {
    public:
        const char* what() const noexcept;

};

#endif // SHOPEXCEPTIONS_H

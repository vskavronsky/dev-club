#include "ShopExceptions.h"

const char* InvalidParameterMoney::what() const noexcept{
    return "Invalid parameter moneyAmount for Customer(const std::string& name, double moneyAmount). Value should be > 0!";
}

const char* InvalidParameterPrice::what() const noexcept{
    return "Invalid parameter price for Item(const std::string& title, double price, Category* category). Value should be > 0!";
}

const char* OutOfMoney::what() const noexcept{
    return "You are run out all money!";
}

const char* NotEnoughMoney::what() const noexcept{
    return "You dont have enough money to make order!";
}

const char* CategoryWithoutItems::what() const noexcept{
    return "You dont have any items in category yet!";
}

const char* CustomerWithoutOrders::what() const noexcept{
    return "You dont have make any orders yet!";
}

const char* ItemWithoutOrders::what() const noexcept{
    return "There are no orders for this item!";
}

const char* OrderWitoutItems::what() const noexcept{
    return "Please, create order to buy items!";
}

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include "ShopExceptions.h"
#include <iostream>
#include <set>

class Order;

class Customer {
    private:
        std::string m_name;
        double m_moneyAmount;
        double m_moneyAmountLimit;
        std::set<Order*>* m_orderList;
        int m_uniqueId;

        static int m_id;
        static std::set<Customer*> m_customerList;

    public:
        Customer(const std::string& name, double moneyAmount);
        virtual ~Customer();

        void ensureHaveMoney() const;

        const std::string& getName() const;
        double getMoneyAmount() const;
        double getMoneyAmountLimit() const;
        void getOrderList() const;
        int getUniqueId() const;

        void addMoney(double value);
        void refund(double value);
        void buy(double value);

        void addOrder(Order* order);
        void removeOrder(Order* order);
        void deleteOrder(Order* order);

        static void getCustomerList();

};

#endif // CUSTOMER_H

#ifndef ORDER_H
#define ORDER_H

#include "Customer.h"
#include "Item.h"
#include <set>

class Customer;
class Item;

class Order {
    private:
        int m_orderNumber;
        Customer* m_customer;
        std::multiset<Item*>* m_items;
        int m_uniqueId;

        static int m_id;
        static int m_orderNumberGenerator;
        static std::set<Order*> m_orderList;

    public:
        Order(Customer* customer, Item* item);
        virtual ~Order();

        int getOrderNumber() const;
        void getItems() const;
        int getUniqueId() const;

        void addItem(Item* item);
        void removeItem(Item* item);
        void deleteItem(Item* item);
        void orderCancellation(Order* order);

        static void getOrderList();

};

#endif // ORDER_H

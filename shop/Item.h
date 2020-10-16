#ifndef ITEM_H
#define ITEM_H

#include "Category.h"
#include "Order.h"
#include <iostream>
#include <set>

class Category;
class Order;

class Item {
    private:
        double m_price;
        std::string m_title;
        Category* m_categoty;
        std::set<Order*>* m_orders;
        int m_uniqueId;

        static int m_id;
        static std::set<Item*> m_itemList;

    public:
        Item(const std::string& title, double price, Category* category);
        virtual ~Item();

        double getPrice() const;
        const std::string& getTitle() const;
        void getItemInfo() const;
        void getOrders() const;
        int getUniqueId() const;

        void setPrice(int value);
        void setTitle(const std::string& title);
        void changeCategory(Category* category);

        void addOrder(Order* order);
        void deleteOrder(Order* order);

        static void getItemList();

};

#endif // ITEM_H

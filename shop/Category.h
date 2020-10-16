#ifndef CATEGORY_H
#define CATEGORY_H

#include "Item.h"
#include <iostream>
#include <set>

class Item;

class Category {
    private:
        std::string m_title;
        std::set<Item*>* m_itemList;
        int m_uniqueId;

        static int m_id;
        static std::set<Category*> m_categoryList;

    public:
        explicit Category(const std::string& title);
        virtual ~Category();

        const std::string& getTitle() const;
        void getItemList() const;
        int getUniqueId() const;

        void setTitle(const std::string& title);

        void addItem(Item* item);
        void deleteItem(Item* item);

        static void getCategoryList();

};

#endif // CATEGORY_H

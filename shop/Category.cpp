#include "Category.h"

Category::Category(const std::string& title) {
    m_id += 1;

    m_title = title;
    m_itemList = new std::set<Item*>();
    m_uniqueId = m_id;

    m_categoryList.insert(this);
}

Category::~Category() {
    for ( auto it : *m_itemList ) {
        delete it;
        it = nullptr;
    }
    delete m_itemList;
    m_itemList = nullptr;

    m_categoryList.erase(this);
}

const std::string& Category::getTitle() const {
    return m_title;
}

void Category::getItemList() const {
    std::cout << m_title << ":" << std::endl;
    if ( m_itemList->empty() ) {
        throw CategoryWithoutItems();
    } else {
        for ( const auto& it : *m_itemList ) {
            it->getItemInfo();
        }
        std::cout << std::endl;
    }
}

int Category::getUniqueId() const {
    return m_uniqueId;
}

void Category::setTitle(const std::string& title) {
    m_title = title;
}

void Category::addItem(Item* item) {
    m_itemList->insert(item);
}

void Category::deleteItem(Item* item) {
    m_itemList->erase(item);
}

int Category::m_id = 0;

std::set<Category*> Category::m_categoryList;

void Category::getCategoryList() {
    for ( auto it : m_categoryList) {
        it->getItemList();
    }
}

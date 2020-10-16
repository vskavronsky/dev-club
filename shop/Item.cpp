#include "Item.h"

Item::Item(const std::string& title, double price, Category* category) {
    if ( price <= 0 ) {
        throw InvalidParameterPrice();
    }
    m_id += 1;

    m_title = title;
    m_price = price;
    m_categoty = category;
    m_categoty->addItem(this);
    m_orders = new std::set<Order*>();
    m_uniqueId = m_id;

    m_itemList.insert(this);
}

Item::~Item() {
    m_categoty->deleteItem(this);

    for ( auto it : *m_orders ) {
        it->deleteItem(this);
    }
    delete m_orders;
    m_orders = nullptr;

    m_itemList.erase(this);
}

double Item::getPrice() const {
    return m_price;
}

const std::string& Item::getTitle() const {
    return m_title;
}

void Item::getItemInfo() const {
    std::cout << " --" << m_title << ": "
              << m_price << "$/"
              << m_categoty->getTitle() << std::endl;
}

void Item::getOrders() const {
    std::cout << m_title << ":" << std::endl;
    if ( m_orders->empty() ) {
        throw ItemWithoutOrders();
    } else {
        for ( const auto& it : *m_orders ) {
            it->getItems();
        }
    }
}

int Item::getUniqueId() const {
    return m_uniqueId;
}

void Item::setPrice(int value) {
    m_price = value;
}

void Item::setTitle(const std::string& title) {
    m_title = title;
}

void Item::changeCategory(Category* newCategory) {
    m_categoty->deleteItem(this);
    m_categoty = newCategory;
    m_categoty->addItem(this);
}

void Item::addOrder(Order* order) {
    m_orders->insert(order);
}

void Item::deleteOrder(Order* order) {
    m_orders->erase(order);
}

int Item::m_id = 0;

std::set<Item*> Item::m_itemList;

void Item::getItemList() {
    for ( auto it : m_itemList ) {
        it->getItemInfo();
    }
    std::cout << std::endl;
}

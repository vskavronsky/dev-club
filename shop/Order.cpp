#include "Order.h"

Order::Order(Customer* customer, Item* item) {
    m_id += 1;
    m_orderNumberGenerator += 1;

    m_orderNumber = m_orderNumberGenerator;
    m_items = new std::multiset<Item*>();
    m_customer = customer;
    m_uniqueId = m_id;

    this->addItem(item);
    m_customer->addOrder(this);
    item->addOrder(this);

    m_orderList.insert(this);
}

Order::~Order() {
    m_customer->deleteOrder(this);

    for ( auto it : *m_items ) {
        it->deleteOrder(this);
    }
    delete m_items;
    m_items = nullptr;

    m_orderList.erase(this);
}

int Order::getOrderNumber() const {
    return m_orderNumber;
}

void Order::getItems() const {
    if ( m_items->empty() ) {
        throw OrderWitoutItems();
    } else {
        std::cout << "Order number: " << m_orderNumber << std::endl
            << " -Customer: " << m_customer->getName() << std::endl;
        for ( const auto& it : *m_items ) {
            it->getItemInfo();
        }
        std::cout << std::endl;
    }
}

int Order::getUniqueId() const {
    return m_uniqueId;
}

void Order::addItem(Item* item) {
    m_customer->buy(item->getPrice());
    m_items->insert(item);
    item->addOrder(this);
}

void Order::removeItem(Item* item) {
    m_customer->refund(item->getPrice());
    m_items->erase(m_items->find(item));

    if ( !m_items->count(item) ) {
        item->deleteOrder(this);
    }
}

void Order::deleteItem(Item *item) {
    m_items->erase(item);
}

void Order::orderCancellation(Order* order) {
    for ( auto it : *m_items ) {
        m_customer->refund(it->getPrice());
    }
    delete order;
    order = nullptr;
}

int Order::m_id = 0;
int Order::m_orderNumberGenerator = 100;

std::set<Order*> Order::m_orderList;

void Order::getOrderList() {
    for ( auto it : m_orderList ) {
        it->getItems();
    }
}

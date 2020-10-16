#include "Customer.h"

Customer::Customer(const std::string& name, double moneyAmount) {
    if ( moneyAmount <= 0 ) {
        throw InvalidParameterMoney();
    }
    m_id += 1;

    m_name = name;
    m_moneyAmount = moneyAmount;
    m_moneyAmountLimit = moneyAmount;
    m_orderList = new std::set<Order*>();
    m_uniqueId = m_id;

    m_customerList.insert(this);
}

Customer::~Customer() {
    for ( auto it : *m_orderList ) {
        delete it;
        it = nullptr;
    }
    delete m_orderList;
    m_orderList = nullptr;

    m_customerList.erase(this);
}

void Customer::ensureHaveMoney() const {
    if ( m_moneyAmount == 0 ) {
        throw OutOfMoney();
    }
}

const std::string& Customer::getName() const {
    return m_name;
}

double Customer::getMoneyAmount() const {
    return m_moneyAmount;
}

double Customer::getMoneyAmountLimit() const {
    return m_moneyAmountLimit;
}

void Customer::getOrderList() const {
    std::cout << m_name << ": "
              << m_moneyAmount << "$/"
              << m_moneyAmountLimit << "$" << std::endl;
    if ( m_orderList->empty() ) {
        throw CustomerWithoutOrders();
    } else {
        for ( const auto& it : *m_orderList ) {
            it->getItems();
        }
    }
}

int Customer::getUniqueId() const {
    return m_uniqueId;
}

void Customer::addMoney(double value) {
    this->ensureHaveMoney();

    double total = m_moneyAmount + value;
    if ( total > m_moneyAmountLimit ) {
        m_moneyAmount = m_moneyAmountLimit;
        return;
    }
    m_moneyAmount = total;
}

void Customer::refund(double value) {
    this->addMoney(value);
}

void Customer::buy(double value) {
    this->ensureHaveMoney();

    if ( value > m_moneyAmount ) {
        throw NotEnoughMoney();
    }
    m_moneyAmount -= value;
}

void Customer::addOrder(Order* order) {
    m_orderList->insert(order);
}

void Customer::removeOrder(Order *order) {
    order->orderCancellation(order);
}

void Customer::deleteOrder(Order* order) {
    m_orderList->erase(order);
}

int Customer::m_id = 0;

std::set<Customer*> Customer::m_customerList;

void Customer::getCustomerList() {
    for ( auto it : m_customerList ) {
        it->getOrderList();
    }
}

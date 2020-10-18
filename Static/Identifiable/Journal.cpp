#include "Journal.hpp"

Journal::Journal(const std::string& title, double price) : Identifiable() {
    m_title = title;
    m_price = price;
}

Journal::Journal(const Journal& copy) {
    m_title = copy.m_title;
    m_price = copy.m_price;
}

Journal::~Journal() {}

const std::string& Journal::getTitle() const {
    return m_title;
}

double Journal::getPrice() const {
    return m_price;
}

void Journal::setTitle(const std::string& title) {
    m_title = title;
}

void Journal::setPrice(double price) {
    m_price = price;
}

Journal& Journal::operator=(const Journal& copy) {
    m_title = copy.m_title;
    m_price = copy.m_price;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Journal& journal) {
    return out << journal.getTitle() << ": " << journal.getPrice() << "$. ID-" << journal.getUniqueId();
}

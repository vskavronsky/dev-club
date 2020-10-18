#include "Countable.hpp"

Countable::Countable() {
    m_totalCount += 1;
}

Countable::~Countable() {
    m_totalCount -= 1;
}

int Countable::m_totalCount = 0;

int Countable::getTotalCount() {
    return m_totalCount;
}

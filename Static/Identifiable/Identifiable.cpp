#include "Identifiable.hpp"

Identifiable::Identifiable() {
    m_id += 1;
    m_uniqueId = m_id;
}

Identifiable::~Identifiable() {}

int Identifiable::getUniqueId() const {
    return m_uniqueId;
}

int Identifiable::m_id = 100;

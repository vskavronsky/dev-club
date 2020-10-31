#include "GeometricProgIter.hpp"

GeometricProgIter::GeometricProgIter(int current, int step, int limit)
    : m_current(current), m_step(step), m_limit(limit), m_count(0) {}

GeometricProgIter::~GeometricProgIter() {}

void GeometricProgIter::next() {
    if ( over() ) {
        return;
    }
    m_current *= m_step;
    m_count += 1;
}

void GeometricProgIter::operator++() {
    next();
}

void GeometricProgIter::operator++(int) {
    operator++();
}

bool GeometricProgIter::over() const {
    return m_count == m_limit;
}

int GeometricProgIter::value() const {
    return m_current;
}

int GeometricProgIter::operator*() const {
    return value();
}

std::ostream& operator<<(std::ostream& out, const GeometricProgIter& range) {
    return out << *range;
}

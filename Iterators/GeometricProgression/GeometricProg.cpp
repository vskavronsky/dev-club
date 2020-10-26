#include "GeometricProg.hpp"

GeometricProg::GeometricProg(int current, int step, int limit)
    : m_current(current), m_step(step), m_limit(limit), m_count(0) {}

GeometricProg::~GeometricProg() {}

void GeometricProg::next() {
    if ( over() ) {
        return;
    }
    m_current *= m_step;
    m_count += 1;
}

void GeometricProg::operator++() {
    next();
}

void GeometricProg::operator++(int) {
    operator++();
}

bool GeometricProg::over() const {
    return m_count == m_limit;
}

int GeometricProg::value() const {
    return m_current;
}

int GeometricProg::operator*() const {
    return value();
}

std::ostream& operator<<(std::ostream& out, const GeometricProg& range) {
    return out << *range;
}

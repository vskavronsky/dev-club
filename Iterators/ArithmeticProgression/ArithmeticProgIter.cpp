#include "ArithmeticProgIter.hpp"

ArithmeticProgIter::ArithmeticProgIter(int current, int step, int limit)
    : m_current(current), m_step(step), m_limit(limit), m_count(0) {}

ArithmeticProgIter::~ArithmeticProgIter() {}

void ArithmeticProgIter::next() {
    if ( over() ) {
        return;
    }
    m_current += m_step;
    m_count += 1;
}

void ArithmeticProgIter::operator++() {
    next();
}

void ArithmeticProgIter::operator++(int) {
    operator++();
}

bool ArithmeticProgIter::over() const {
    return m_count == m_limit;
}

int ArithmeticProgIter::value() const {
    return m_current;
}

int ArithmeticProgIter::operator*() const {
    return value();
}

std::ostream& operator<<(std::ostream& out, const ArithmeticProgIter& range) {
    return out << *range;
}

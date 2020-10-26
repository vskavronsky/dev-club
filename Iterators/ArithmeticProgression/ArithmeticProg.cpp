#include "ArithmeticProg.hpp"

ArithmeticProg::ArithmeticProg(int current, int step, int limit)
    : m_current(current), m_step(step), m_limit(limit), m_count(0) {}

ArithmeticProg::~ArithmeticProg() {}

void ArithmeticProg::next() {
    if ( over() ) {
        return;
    }
    m_current += m_step;
    m_count += 1;
}

void ArithmeticProg::operator++() {
    next();
}

void ArithmeticProg::operator++(int) {
    operator++();
}

bool ArithmeticProg::over() const {
    return m_count == m_limit;
}

int ArithmeticProg::value() const {
    return m_current;
}

int ArithmeticProg::operator*() const {
    return value();
}

std::ostream& operator<<(std::ostream& out, const ArithmeticProg& range) {
    return out << *range;
}

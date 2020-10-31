#include "FactorialIter.hpp"

#define SECOND 1
#define INITIAL_VALUE 1

FactorialIter::FactorialIter(int limit) : m_limit(limit), m_result(INITIAL_VALUE), m_count(SECOND) {}

FactorialIter::~FactorialIter() {}

unsigned long long int FactorialIter::factorial(int number) {
    unsigned long long int factorial = 1;

    for ( int i = 2; i <= number; i++ ) {
        factorial *= i;
    }
    return factorial;
}

void FactorialIter::next() {
    if ( over() ) {
        return;
    }
    if ( m_count >= 2 ) {
        m_result = factorial(m_count);
    }
    m_count += 1;
}

void FactorialIter::operator++() {
    next();
}

void FactorialIter::operator++(int) {
    operator++();
}

bool FactorialIter::over() const {
    return m_count > m_limit;
}

unsigned long long int FactorialIter::value() const {
    return m_result;
}

unsigned long long int FactorialIter::operator*() const {
    return value();
}

std::ostream& operator<<(std::ostream& out, const FactorialIter& factorial) {
    return out << *factorial;
}

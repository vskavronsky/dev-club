#include "Factorial.hpp"

#define SECOND 1
#define INITIAL_VALUE 1

Factorial::Factorial(int limit) : m_result(INITIAL_VALUE), m_count(SECOND), m_limit(limit) {}

Factorial::~Factorial() {}

unsigned long long int Factorial::factorial(int number) {
    unsigned long long int factorial = 1;

    for ( int i = 2; i <= number; i++ ) {
        factorial *= i;
    }
    return factorial;
}

void Factorial::next() {
    if ( over() ) {
        return;
    }
    if ( m_count >= 2 ) {
        m_result = factorial(m_count);
    }
    m_count += 1;
}

void Factorial::operator++() {
    next();
}

void Factorial::operator++(int) {
    operator++();
}

bool Factorial::over() const {
    return m_count > m_limit;
}

unsigned long long int Factorial::value() const {
    return m_result;
}

unsigned long long int Factorial::operator*() const {
    return value();
}

std::ostream& operator<<(std::ostream& out, const Factorial& factorial) {
    return out << *factorial;
}

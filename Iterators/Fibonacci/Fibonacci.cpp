#include "Fibonacci.hpp"

#define BEGIN 0
#define INITIAL_VALUE 0

Fibonacci::Fibonacci(int limit) : m_result(INITIAL_VALUE), m_count(BEGIN), m_limit(limit) {}

Fibonacci::~Fibonacci() {}

long long int Fibonacci::fibonacci(int number) {
    int fibonacci1 = 0;
    int fibonacci2 = 1;

    if ( number == 1 || number == -1 ) {
        return 1;
    }
    if ( number < -1 ) {
        for ( int i = -2; i >= number; i-- ) {
            int fibonacci = fibonacci2;

            fibonacci2 += fibonacci1;
            fibonacci1 = fibonacci;
        }
        if ( number % 2 == 0 ) {
            fibonacci2 *= -1;
        }
        return fibonacci2;
    }
    if ( number > 1 ) {
        for ( int i = 2; i <= number; i++ ) {
            int fibonacci = fibonacci2;

            fibonacci2 += fibonacci1;
            fibonacci1 = fibonacci;
        }
        return fibonacci2;
    }
    return 0;
}

void Fibonacci::next() {
    if ( over() ) {
        return;
    }
    m_count += 1;
    m_result = fibonacci(m_count);
}

void Fibonacci::prev() {
    if ( over() ) {
        return;
    }
    m_count -= 1;
    m_result = fibonacci(m_count);
}

void Fibonacci::operator++() {
    next();
}

void Fibonacci::operator++(int) {
    operator++();
}

void Fibonacci::operator--() {
    prev();
}

void Fibonacci::operator--(int) {
    operator--();
}

bool Fibonacci::over() const {
    return m_count == m_limit;
}

long long int Fibonacci::value() const {
    return m_result;
}

long long int Fibonacci::operator*() const {
    return value();
}

std::ostream& operator<<(std::ostream& out, const Fibonacci& fibonacci) {
    return out << *fibonacci;
}

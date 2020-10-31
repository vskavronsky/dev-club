#include "FibonacciIter.hpp"

#define BEGIN 0
#define INITIAL_VALUE 0

FibonacciIter::FibonacciIter(int limit) :  m_limit(limit), m_result(INITIAL_VALUE), m_count(BEGIN) {}

FibonacciIter::~FibonacciIter() {}

long long int FibonacciIter::fibonacci(int number) {
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

void FibonacciIter::next() {
    if ( over() ) {
        return;
    }
    m_count += 1;
    m_result = fibonacci(m_count);
}

void FibonacciIter::prev() {
    if ( over() ) {
        return;
    }
    m_count -= 1;
    m_result = fibonacci(m_count);
}

void FibonacciIter::operator++() {
    next();
}

void FibonacciIter::operator++(int) {
    operator++();
}

void FibonacciIter::operator--() {
    prev();
}

void FibonacciIter::operator--(int) {
    operator--();
}

bool FibonacciIter::over() const {
    return m_count == m_limit;
}

long long int FibonacciIter::value() const {
    return m_result;
}

long long int FibonacciIter::operator*() const {
    return value();
}

std::ostream& operator<<(std::ostream& out, const FibonacciIter& fibonacci) {
    return out << *fibonacci;
}

#include "PrimeIter.hpp"

#define DEFAULT_VALUE 0
#define EVEN_DIVISOR 2
#define ODD_DIVISOR 3

PrimeIter::PrimeIter(int limit) : m_limit(limit), m_result(2), m_vectorIndex(0) {
    m_primes = new std::vector<unsigned long long int>(m_limit);
    (*m_primes)[m_vectorIndex] = m_result;
}

PrimeIter::~PrimeIter() {
    delete m_primes;
    m_primes = nullptr;
}

unsigned long long int PrimeIter::prime(unsigned long long int number) {
    if (number == 3) {
        return number;
    }

    if (number % EVEN_DIVISOR == 0 || number % ODD_DIVISOR == 0) {
        return prime(number+1);
    }

    for (unsigned long long int i = 5; i * i <= number; i = i + 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return prime(number+1);
        }
    }

    return number;
}

void PrimeIter::setNext(int currentIndex) {
    m_result = prime(m_result+1);
    (*m_primes)[currentIndex] = m_result;
}

void PrimeIter::getPrimes() {
    std::cout << "Vector:";
    for ( const auto& prime : *m_primes ) {
        std::cout << " " << prime;
    }
    std::cout << std::endl;
}

void PrimeIter::setLimit(int limit) {
    for ( int i = 0; i < limit; ++i ) {
        m_primes->push_back(DEFAULT_VALUE);
    }
    setNext(m_limit);
    m_limit += limit;
}

void PrimeIter::next() {
    if ( end() ) {
        return;
    }

    m_vectorIndex += 1;
    if ( (*m_primes)[m_vectorIndex] == 0 ) {
        if ( m_vectorIndex < m_limit ) {
            (*m_primes)[m_vectorIndex] = prime(m_result+1);
            m_result = (*m_primes)[m_vectorIndex];
        }
    }
}

void PrimeIter::operator++() {
    next();
}

void PrimeIter::operator++(int) {
    operator++();
}

void PrimeIter::prev() {
    if ( begin() ) {
        return;
    }

    m_vectorIndex -= 1;
}

void PrimeIter::operator--() {
    prev();
}

void PrimeIter::operator--(int) {
    operator--();
}

bool PrimeIter::begin() const {
    return m_vectorIndex == 0;
}

bool PrimeIter::end() const {
    return m_vectorIndex == m_limit;
}

unsigned long long int PrimeIter::value() const {
    return (*m_primes)[m_vectorIndex];
}

unsigned long long int PrimeIter::operator*() const {
    return value();
}

std::ostream& operator<<(std::ostream& out, const PrimeIter& prime) {
    return out << *prime;
}

#ifndef PRIMEITER_HPP
#define PRIMEITER_HPP

#include <iostream>
#include <vector>

class PrimeIter {
    private:
        int m_limit;
        unsigned long long int m_result;
        int m_vectorIndex;

        std::vector<unsigned long long int>* m_primes;

        unsigned long long int prime(unsigned long long int number);
        void setNext(int currentIndex);

    public:
        explicit PrimeIter(int limit);
        virtual ~PrimeIter();

        void getPrimes();
        void setLimit(int limit);

        void next();
        void operator++();
        void operator++(int);

        void prev();
        void operator--();
        void operator--(int);

        bool begin() const;
        bool end() const;

        unsigned long long int value() const;
        unsigned long long int operator*() const;

};

std::ostream& operator<<(std::ostream& out, const PrimeIter& prime);

#endif // PRIMEITER_HPP

#ifndef PRIME_HPP
#define PRIME_HPP

#include <iostream>
#include <vector>

class Prime {
    private:
        unsigned long long int m_result;
        int m_vectorIndex;
        int m_limit;

        std::vector<unsigned long long int>* m_primes;

        unsigned long long int prime(unsigned long long int number);
        void setNext(int currentIndex);

    public:
        explicit Prime(int limit);
        virtual ~Prime();

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

std::ostream& operator<<(std::ostream& out, const Prime& prime);

#endif // PRIME_HPP

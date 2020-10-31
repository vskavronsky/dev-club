#ifndef FIBONACCIITER_HPP
#define FIBONACCIITER_HPP

#include <iostream>

class FibonacciIter {
    private:
        int m_limit;
        long long int m_result;
        int m_count;

        long long int fibonacci(int number);

    public:
        explicit FibonacciIter(int limit);
        virtual ~FibonacciIter();

        void next();
        void prev();

        void operator++();
        void operator++(int);

        void operator--();
        void operator--(int);

        bool over() const;

        long long int value() const;
        long long int operator*() const;

};

std::ostream& operator<<(std::ostream& out, const FibonacciIter& fibonacci);

#endif // FIBONACCIITER_HPP

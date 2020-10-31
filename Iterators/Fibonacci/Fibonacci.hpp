#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include <iostream>

class Fibonacci {
    private:
        long long int m_result;
        int m_count;
        int m_limit;

        long long int fibonacci(int number);

    public:
        explicit Fibonacci(int limit);
        virtual ~Fibonacci();

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

std::ostream& operator<<(std::ostream& out, const Fibonacci& fibonacci);

#endif // FIBONACCI_HPP

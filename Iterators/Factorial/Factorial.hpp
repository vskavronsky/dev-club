#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

#include <iostream>

class Factorial {
    private:
        unsigned long long int m_result;
        int m_count;
        int m_limit;

        unsigned long long int factorial(int number);

    public:
        explicit Factorial(int limit);
        virtual ~Factorial();

        void next();
        void operator++();
        void operator++(int);
        bool over() const;
        unsigned long long int value() const;
        unsigned long long int operator*() const;

};

std::ostream& operator<<(std::ostream& out, const Factorial& factorial);

#endif // FACTORIAL_HPP

#ifndef FACTORIALITER_HPP
#define FACTORIALITER_HPP

#include <iostream>

class FactorialIter {
    private:
        int m_limit;    
        unsigned long long int m_result;
        int m_count;

        unsigned long long int factorial(int number);

    public:
        explicit FactorialIter(int limit);
        virtual ~FactorialIter();

        void next();
        void operator++();
        void operator++(int);
        bool over() const;
        unsigned long long int value() const;
        unsigned long long int operator*() const;

};

std::ostream& operator<<(std::ostream& out, const FactorialIter& factorial);

#endif // FACTORIALITER_HPP

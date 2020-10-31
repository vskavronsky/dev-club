#ifndef ARITHMETICPROGITER_HPP
#define ARITHMETICPROGITER_HPP

#include <iostream>

class ArithmeticProgIter {
    private:
        int m_current;
        int m_step;
        int m_limit;
        int m_count;

    public:
        ArithmeticProgIter(int current, int step, int limit);
        virtual ~ArithmeticProgIter();

        void next();
        void operator++();
        void operator++(int);
        bool over() const;
        int value() const;
        int operator*() const;

};

std::ostream& operator<<(std::ostream& out, const ArithmeticProgIter& range);

#endif // ARITHMETICPROGITER_HPP

#ifndef ARITHMETICPROG_HPP
#define ARITHMETICPROG_HPP

#include <iostream>

class ArithmeticProg {
    private:
        int m_current;
        int m_step;
        int m_limit;
        int m_count;

    public:
        ArithmeticProg(int current, int step, int limit);
        virtual ~ArithmeticProg();

        void next();
        void operator++();
        void operator++(int);
        bool over() const;
        int value() const;
        int operator*() const;

};

std::ostream& operator<<(std::ostream& out, const ArithmeticProg& range);

#endif // ARITHMETICPROG_HPP

#ifndef COUNTABLE_HPP
#define COUNTABLE_HPP

#include <iostream>

class Countable {
    protected:
        static int m_totalCount;

    public:
        Countable();
        virtual ~Countable();

        static int getTotalCount();

};

#endif // COUNTABLE_HPP

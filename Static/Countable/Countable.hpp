#ifndef COUNTABLE_H
#define COUNTABLE_H

#include <iostream>

class Countable {
    protected:
        static int m_totalCount;

    public:
        Countable();
        virtual ~Countable();

        static int getTotalCount();

};

#endif // COUNTABLE_H

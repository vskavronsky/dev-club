#ifndef GEOMETRICPROGITER_HPP
#define GEOMETRICPROGITER_HPP

#include <iostream>

class GeometricProgIter {
    private:
        int m_current;
        int m_step;
        int m_limit;
        int m_count;

    public:
        GeometricProgIter(int current, int step, int limit);
        virtual ~GeometricProgIter();

        void next();
        void operator++();
        void operator++(int);
        bool over() const;
        int value() const;
        int operator*() const;

};

std::ostream& operator<<(std::ostream& out, const GeometricProgIter& range);

#endif // GEOMETRICPROGITER_HPP

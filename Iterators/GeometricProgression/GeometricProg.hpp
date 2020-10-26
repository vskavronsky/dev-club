#ifndef GEOMETRICPROG_HPP
#define GEOMETRICPROG_HPP

#include <iostream>

class GeometricProg {
    private:
        int m_current;
        int m_step;
        int m_limit;
        int m_count;

    public:
        GeometricProg(int current, int step, int limit);
        virtual ~GeometricProg();

        void next();
        void operator++();
        void operator++(int);
        bool over() const;
        int value() const;
        int operator*() const;

};

std::ostream& operator<<(std::ostream& out, const GeometricProg& range);

#endif // GEOMETRICPROG_HPP

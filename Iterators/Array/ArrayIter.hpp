#ifndef ARRAYITER_HPP
#define ARRAYITER_HPP

#include <iostream>

template <class Type>
class ArrayIter {
    private:
        Type* m_array;
        size_t m_size;
        size_t m_index;

    public:
        ArrayIter(Type* array, size_t size);
        virtual ~ArrayIter();

        void next();
        void prev();

        void operator++();
        void operator++(int);

        void operator--();
        void operator--(int);

        bool end() const;
        bool begin() const;

        Type value() const;
        Type operator*() const;

};

template <class Type>
std::ostream& operator<<(std::ostream& out, const ArrayIter<Type>& arrayIter);

#endif // ARRAYITER_HPP

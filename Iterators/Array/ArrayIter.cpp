#include "ArrayIter.hpp"

#define BEGIN 0

template <class Type>
ArrayIter<Type>::ArrayIter(Type* array, size_t size) : m_array(array), m_size(size), m_index(BEGIN) {}

template <class Type>
ArrayIter<Type>::~ArrayIter() {}

template <class Type>
void ArrayIter<Type>::next() {
    if ( end() ) {
        return;
    }
    m_index += 1;
}

template <class Type>
void ArrayIter<Type>::prev() {
    if ( begin() ) {
        return;
    }
    m_index -= 1;
}

template <class Type>
void ArrayIter<Type>::operator++() {
    next();
}

template <class Type>
void ArrayIter<Type>::operator++(int) {
    operator++();
}

template <class Type>
void ArrayIter<Type>::operator--() {
    prev();
}

template <class Type>
void ArrayIter<Type>::operator--(int) {
    operator--();
}

template <class Type>
bool ArrayIter<Type>::end() const {
    return m_index == m_size;
}

template <class Type>
bool ArrayIter<Type>::begin() const {
    return m_index == BEGIN;
}

template <class Type>
Type ArrayIter<Type>::value() const {
    return m_array[m_index];
}

template <class Type>
Type ArrayIter<Type>::operator*() const {
    return value();
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const ArrayIter<Type>& arrayIter) {
    return out << *arrayIter;
}

template class ArrayIter<int>;
template class ArrayIter<float>;
template class ArrayIter<double>;
template class ArrayIter<char>;
template class ArrayIter<std::string>;

template std::ostream& operator<<(std::ostream& out, const ArrayIter<int>& arrayIter);
template std::ostream& operator<<(std::ostream& out, const ArrayIter<float>& arrayIter);
template std::ostream& operator<<(std::ostream& out, const ArrayIter<double>& arrayIter);
template std::ostream& operator<<(std::ostream& out, const ArrayIter<char>& arrayIter);
template std::ostream& operator<<(std::ostream& out, const ArrayIter<std::string>& arrayIter);

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <cstdlib>

class OutOfMemoryException {};
class ZeroLenException {};

template <class Type>
class MyVector {
    private:
        Type* array;
        size_t capacity;
        size_t multiplier;
        size_t current;
        
    public:
        MyVector(size_t capacity = 100, size_t multiplier = 1.05);
        ~MyVector();
        
        size_t size() const;
        size_t max_size() const;
        
        void erase(size_t index);
        void insert(Type value, size_t index);
        size_t find(Type value) const;
        void push_back(Type value);
        Type pop_back();
        void sort();
        Type operator[](size_t index) const;
        bool operator==(const MyVector& other) const;
        bool operator!=(const MyVector& other) const;
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const MyVector<Type>& myVector);

#endif //MYVECTOR_H

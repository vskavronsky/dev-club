#include "MyVector.h"

template <class Type>
MyVector<Type>::MyVector(size_t capacity, size_t multiplier) {
    this->capacity = capacity;
    this->current = 0;
    this->multiplier = multiplier;
    
    array = (Type*)malloc(capacity*sizeof(Type));

    if ( array == NULL ) {
        throw OutOfMemoryException();   
    }
}

template <class Type>
MyVector<Type>::~MyVector() {
    free(array);
}

template <class Type>
size_t MyVector<Type>::size() const {
    return this->current;
}

template <class Type>
size_t MyVector<Type>::max_size() const {
    return this->capacity;
}

template <class Type>
void MyVector<Type>::erase(size_t index) {
    size_t newCurrent = this->current - 1;
    
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    if ( !(index >= 0 && index < newCurrent) ) {
        std::cout << "You entered incorrect index of the array!" << std::endl;
        return;
    } else {
        for ( size_t i = index; i < newCurrent; i++ ) {
            this->array[i] = this->array[i+1];
        }
        this->current = newCurrent;
    }
}

template <class Type>
void MyVector<Type>::insert(Type value, size_t index) {
    size_t newCurrent = this->current + 1;
    
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    if ( newCurrent > this->capacity ) {
        size_t newCapacity = this->capacity * this->multiplier;
        Type* newArray = (Type*)realloc(array, newCapacity*sizeof(Type));
        
        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }
        
        this->capacity = newCapacity;
        this->array = newArray;
    }
    if ( !(index >= 0 && index < this->current) ) {
        std::cout << "You entered incorrect index of the array!" << std::endl;
        return;
    } else {
        size_t i = this->current - 1;
        
        for ( ; i >= index; i-- ) {
            this->array[i+1] = this->array[i];
        }
        this->array[index] = value;
        this->current = newCurrent;
    }
}

template <class Type>
size_t MyVector<Type>::find(Type value) const {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    for ( size_t i = 0; i < this->current; i++ ) {
        if ( array[i] == value ) {
            return i;
        }
    }
    return -1;
}

template <class Type>
void MyVector<Type>::push_back(Type value) {
    size_t newCurrent = this->current + 1;
    
    if ( newCurrent > this->capacity ) {
        size_t newCapacity = this->capacity * this->multiplier;
        Type* newArray = (Type*)realloc(array, newCapacity*sizeof(Type));
        
        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }
        
        this->capacity = newCapacity;
        this->array = newArray;
    }
    this->array[current] = value;
    this->current = newCurrent;
}

template <class Type>
Type MyVector<Type>::pop_back() {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    this->current -= 1;
    
    return this->array[current]; 
}

template <class Type>
void MyVector<Type>::sort() {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    for ( size_t i = 0; i < this->current; i++ ) {
        size_t min = i;
        
        for ( size_t j = i + 1; j < this->current; j++ ) {
            if ( this->array[min] > this->array[j] ) {
                min = j;
            }
        }
        if ( min != i ) {
            size_t temp = this->array[min];
            
            this->array[min] = this->array[i];
            this->array[i] = temp;
        }
    }
}

template <class Type>
Type MyVector<Type>::operator[](size_t index) const {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    if ( index >= this->current || index < 0 ) {
        return -1;
    }
    return this->array[index];
}

template <class Type>
bool MyVector<Type>::operator==(const MyVector& other) const {
    if ( this->current == other.current ) {
        for ( size_t i = 0, j = this->current - 1; this->array[i] == other.array[i]; i++, j-- ) {
            if ( j == 0 ) {
                return true;
            }
        }
    }
    return false;
}

template <class Type>
bool MyVector<Type>::operator!=(const MyVector& other) const {
    if ( this->current != other.current ) {
        return true;
    } else {
        for ( size_t i = 0, j = this->current - 1; this->array[i] != other.array[i]; i++, j-- ) {
            if ( j == 0 ) {
                return true;
            }
        }
    }
    return false;
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const MyVector<Type>& myVector) {
    size_t last = myVector.size() - 1;
    
    out << "[ ";
    for ( size_t i = 0; i < last; i++ ) {
        out << myVector[i] << ' ';
    }
    if ( myVector.size() > 0 ) {
        out << myVector[last] << " ]";
    } else {
        out << " ]";    
    }
    
    return out;
}

template class MyVector<int>;
template class MyVector<float>;
template class MyVector<double>;

template std::ostream& operator<<(std::ostream& out, const MyVector<int>& myVector);
template std::ostream& operator<<(std::ostream& out, const MyVector<float>& myVector);
template std::ostream& operator<<(std::ostream& out, const MyVector<double>& myVector);

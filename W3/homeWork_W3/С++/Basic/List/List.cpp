#include "List.h"

using namespace std;

List::List(int capacity, double multiplier) {
    this->capacity = capacity;
    this->current = 0;
    this->multiplier = multiplier;
    
    array = (int*)malloc(capacity*sizeof(int));

    if ( array == NULL ) {
        throw OutOfMemoryException();   
    }
}

List::~List() {
    free(array);
}

int List::size() const {
    return this->current;
}

int List::max_size() const {
    return this->capacity;
}

void List::erase(int index) {
    int newCurrent = this->current - 1;
    
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    if ( !(index >= 0 && index < newCurrent) ) {
        cout << "You entered incorrect index of the array!" << endl;
        return;
    } else {
        for ( int i = index; i < newCurrent; i++ ) {
            this->array[i] = this->array[i+1];
        }
        this->current = newCurrent;
    }
}

void List::insert(int value, int index) {
    int newCurrent = this->current + 1;
    
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    if ( newCurrent > this->capacity ) {
        int newCapacity = this->capacity * this->multiplier;
        int* newArray = (int*)realloc(array, newCapacity*sizeof(int));
        
        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }
        
        this->capacity = newCapacity;
        this->array = newArray;
    }
    if ( !(index >= 0 && index < this->current) ) {
        cout << "You entered incorrect index of the array!" << endl;
        return;
    } else {
        int i = this->current - 1;
        
        for ( ; i >= index; i-- ) {
            this->array[i+1] = this->array[i];
        }
        this->array[index] = value;
        this->current = newCurrent;
    }
}

int List::find(int value) const {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    for ( int i = 0; i < this->current; i++ ) {
        if ( array[i] == value ) {
            return i;
        }
    }
    return -1;
}

void List::push_back(int value) {
    int newCurrent = this->current + 1;
    
    if ( newCurrent > this->capacity ) {
        int newCapacity = this->capacity * this->multiplier;
        int* newArray = (int*)realloc(array, newCapacity*sizeof(int));
        
        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }
        
        this->capacity = newCapacity;
        this->array = newArray;
    }
    this->array[current] = value;
    this->current = newCurrent;
}

int List::pop_back() {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    this->current -= 1;
    
    return this->array[current]; 
}

void List::sort() {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    for ( int i = 0; i < this->current; i++ ) {
        int min = i;
        
        for ( int j = i + 1; j < this->current; j++ ) {
            if ( this->array[min] > this->array[j] ) {
                min = j;
            }
        }
        if ( min != i ) {
            int temp = this->array[min];
            
            this->array[min] = this->array[i];
            this->array[i] = temp;
        }
    }
}

int List::operator[](int index) const {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    if ( index >= this->current || index < 0 ) {
        return -1;
    }
    return this->array[index];
}

bool List::operator==(const List& other) const {
    if ( this->current == other.current ) {
        for ( int i = 0, j = this->current - 1; this->array[i] == other.array[i]; i++, j-- ) {
            if ( j == 0 ) {
                return true;
            }
        }
    }
    return false;
}

bool List::operator!=(const List& other) const {
    if ( this->current != other.current ) {
        return true;
    } else {
        for ( int i = 0, j = this->current - 1; this->array[i] != other.array[i]; i++, j-- ) {
            if ( j == 0 ) {
                return true;
            }
        }
    }
    return false;
}

ostream& operator<<(ostream& out, const List& list) {
    int last = list.size() - 1;
    
    out << "[ ";
    for ( int i = 0; i < last; i++ ) {
        out << list[i] << ' ';
    }
    if ( list.size() > 0 ) {
        out << list[last] << " ]";
    } else {
        out << " ]";    
    }
    
    return out;
}

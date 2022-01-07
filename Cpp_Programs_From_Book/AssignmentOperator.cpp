#include <iostream>
#include <algorithm>
#include <utility>

class DynamicArray {
    protected:
        int m_length;
        int* m_pArray;

    public:
        DynamicArray(int length = 0) : m_length(length), m_pArray(nullptr) {
            std::cout << "Construct Dynamic Array by size: " << m_length << std::endl;
            
            if ( m_length > 0 ) {
                m_pArray = new int[m_length];
            }
        }
        
        // copy constructor, makes copy of the object; for new objects
        DynamicArray(const DynamicArray& other) : m_length(0), m_pArray(nullptr) {
            std::cout << "Copy Dynamic Array by size: " << other.m_length << std::endl;
            
            if ( other.m_length > 0 ) {
                m_pArray = new int[other.m_length];
                std::copy(other.m_pArray, other.m_pArray + other.m_length, m_pArray);
                m_length = other.m_length;
            }
        }

        // move constructor, steal resourses from the object; for temporary objects, std::move
        DynamicArray(DynamicArray&& other) noexcept : m_length(0), m_pArray(nullptr) {
            std::cout << "Move Dynamic Array by size: " << other.m_length << std::endl;

            if ( other.m_length > 0 ) {
                m_pArray = std::exchange(other.m_pArray, nullptr);
                m_length = std::exchange(other.m_length, 0);
            }
        }

        virtual ~DynamicArray() {
            m_length = 0;
            delete[] m_pArray;
            m_pArray = nullptr;
        }

        int size() const {
            return m_length;
        }

        // copy assignment, makes copy of the object; for existing objects
        DynamicArray& operator=(const DynamicArray& other) {
            std::cout << "Copy assigns Dynamic Array by size: " << other.m_length << std::endl;
            // guard self assignment
            if ( this == &other ) {
                return *this;
            }

            // assume *this manages a reusable resourses
            if ( m_length != other.m_length ) {
                delete[] m_pArray;
                m_pArray = nullptr;
                m_length = 0;
                m_pArray = new int[other.m_length]; // can throw
                m_length = other.m_length;
            }

            std::copy(other.m_pArray, other.m_pArray + other.m_length, m_pArray);
            
            return *this;
        }

        // move assignment, steal resourses from the object; for temporary objects, std::move
        DynamicArray& operator=(DynamicArray&& other) noexcept {
            std::cout << "Move assigns Dynamic Array by size: " << other.m_length << std::endl;
            
            if ( this == &other ) {
                return *this;
            }

            delete[] m_pArray;
            m_pArray = nullptr;
            m_length = 0;
            m_pArray = std::exchange(other.m_pArray, nullptr);
            m_length = std::exchange(other.m_length, 0);

            return *this;
        }

        int& operator[](int index) {
            return m_pArray[index];
        }
};

std::ostream& operator<<(std::ostream& out, DynamicArray& arr) {
    int last = arr.size() - 1;

    out << "[ ";
    for ( int i = 0; i < last; i++ ) {
        out << arr[i] << ' ';
    }
    if ( arr.size() > 0 ) {
        out << arr[last] << " ]";
    }
    else {
        out << " ]";
    }

    return out;
}

int main() {
    int value = 5;
    DynamicArray arr(value);

    for ( int i = 0; i < arr.size(); ++i ) {
        arr[i] = i;
    }

    std::cout << arr << std::endl;

    DynamicArray arr2(arr);
    arr2[3] = 30;
    std::cout << arr2 << std::endl;

    DynamicArray arr3;
    arr3 = arr;
    arr3[2] = 20;
    std::cout << arr3 << std::endl;

    DynamicArray arr4 = std::move(arr);
    std::cout << arr4 << std::endl;
    std::cout << arr << std::endl;

    DynamicArray arr5, arr6;
    arr5 = std::move(arr6);

    return 0;
}

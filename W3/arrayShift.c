#include <stdio.h>

void arrayShift(int array[], int size, int shift) {
    int temp;
    
    if ( shift < 0 ) {
        shift = size + shift % size;
    } else {
        shift %= size;
    }
    
    temp = size - shift;
    if ( temp > shift ) {
        int tempArray[shift];

        for ( int i = temp, j = 0; i < size; i++, j++ ) {
            tempArray[j] = array[i];
        }
        for ( int i = size - 1, j = temp - 1; i >= shift; i--, j-- ) {
            array[i] = array[j];
        }
        for ( int i = 0; i < shift; i++ ) {
            array[i] = tempArray[i];
        }
    } else {
        int tempArray[shift];

        for ( int i = temp - 1; i >= 0; i-- ) {
            tempArray[i] = array[i];
        }
        for ( int i = 0, j = temp; i < shift; i++, j++ ) {
            array[i] = array[j];
        }
        for ( int i = size - 1, j = temp - 1; j >= 0; i--, j-- ) {
            array[i] = tempArray[j];
        }
    }
}

void arrayPrint(int array[], int size) {
    int last = size - 1;
    
    printf("[ ");
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d ]\n", array[last]);
}

int main() {
    int size = 7;
    int shift = -2;
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    
    arrayShift(array, size, shift);
    arrayPrint(array, size);
    
    return 0;
}

// void arrayShift(int array[], int size, int shift) {
//     int arrayLast = size - 1;
    
//     if ( shift > 0 ) {
//         int shiftLast = shift - 1;
//         int tempArray[shift];
    
//         for ( int i = 0; i < shift; i++, shiftLast-- ) {
//             int prev = arrayLast - shiftLast;
        
//             tempArray[i] = array[prev];
//         }
//         for ( ; arrayLast > shiftLast; arrayLast-- ) {
//             int prev = arrayLast - shift;
        
//             array[arrayLast] = array[prev];
//         }
//         for ( int i = 0; i < shift; i++ ) {
//             array[i] = tempArray[i];
//         }
//     }
//     if ( shift < 0 ) {
//         shift *= -1;
//         int shiftLast = shift - 1;
//         int tempArray[shift];
        
//         for ( int i = 0; i < shift; i++ ) {
//             tempArray[i] = array[i];
//         }
//         for ( int i = 0, limit = arrayLast - shiftLast; i < limit; i++ ) {
//             int next = i + shift;
        
//             array[i] = array[next];
//         }
//         for ( int i = 0; i < shift; i++, shiftLast-- ) {
//             int prev = arrayLast - shiftLast;
        
//             array[prev] = tempArray[i];
//         }
//     }
// }

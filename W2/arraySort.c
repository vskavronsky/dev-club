#include <stdio.h>

void arraySort(int array[], int size) {
    for ( int i = 1; i < size; i++ ) {
        int j = i;
        int temp = array[i];
        
        for ( int prev = j - 1; j > 0 && temp < array[prev]; j--, prev-- ) {
            array[j] = array[prev];
        }
        array[j] = temp;
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
    int size = 10;
    int array[] = {0, 62, -33, -46, 91, -11, 55, 84, 73, 110}; // [ -46 -33 -11 0 55 62 73 84 91 110 ]
    
    arraySort(array, size);
    
    arrayPrint(array, size);
    
    return 0;
}

// void arraySort(int array[], int size) {
//     int sorted;
//     int last = size - 1;
    
//     for ( int i = 0; i < last; i++ ) {
//         if ( array[i] > array[i+1] ) {
//             int temp = array[i];
        
//             array[i] = array[i+1];
//             array[i+1] = temp;
//             sorted = 0;
//         }
//     }
//     if ( sorted == 0 ) {
//         arraySort(array, size);
//     }
// }

// length = 9
// [6, 5, 1, 3, 8, 2, 4, 9, 0, 7]
// [6, 5, 1, 3, 8] [2, 4, 9, 0, 7]
//  i = 2;          j = 1;
// [0, 1, 5, 6, 8] [2, 3, 4, 7, 9]
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
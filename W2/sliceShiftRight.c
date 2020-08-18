#include <stdio.h>

void sliceShiftRight(int array[], int start, int end) {
    if ( start < end ) {
        int temp = array[end];
    
        for ( int i = end; i > start; i-- ) {
            array[i] = array[i-1];
        }
        array[start] = temp;
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
    int array[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110}; // [ 11 99 22 33 44 55 66 77 88 110 ]
    int start = 8;
    int end = 1;
    
    sliceShiftRight(array, start, end);
    
    arrayPrint(array, size);
    
    return 0;
}

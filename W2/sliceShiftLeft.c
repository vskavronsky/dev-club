#include <stdio.h>

void sliceShiftLeft(int array[], int start, int end) {
    if ( start < end ) {
        int temp = array[start];
        
        for ( int i = start; i < end; i++ ) {
            array[i] = array[i+1];
        }
        array[end] = temp;
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
    int array[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110}; // [ 11 33 44 55 66 77 88 88 22 110 ]
    int start = 1;
    int end = 8;
    
    sliceShiftLeft(array, start, end);
    
    arrayPrint(array, size);
    
    return 0;
}

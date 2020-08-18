#include <stdio.h>

void sliceReverse(int array[], int lo, int hi) {
    for ( ; lo < hi; lo++, hi-- ) {
        int temp = array[lo];
        
        array[lo] = array[hi];
        array[hi] = temp;
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
    int array[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21}; // [ 12 20 19 18 17 16 15 14 13 21 ]
    int lo = 8;
    int hi = 1;
    
    sliceReverse(array, lo, hi);
    
    arrayPrint(array, size);
    
    return 0;
}

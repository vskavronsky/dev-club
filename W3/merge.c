#include <stdio.h>

void merge(int array[], int lo, int mid, int hi) {
    int size = hi - lo;
    int temp[size];
    int i = lo;
    int j = mid;
    int k = 0;
    
    for ( ; i < mid && j < hi; k++ ) {
        if ( array[i] <= array[j] ) {
            temp[k] = array[i];
            i += 1;
        } else {
            temp[k] = array[j];
            j += 1;
        }
    }
    for ( ; i < mid; i++, k++ ) {
        temp[k] = array[i];
    }
    for ( ; j < hi; j++, k++ ) {
        temp[k] = array[j];
    }
    for ( int l = 0; lo < hi; lo++, l++ ) {
        array[lo] = temp[l];
    }
}

void arrayPrint(int array[], int lo, int hi) {
    int last = hi - 1;
    
    printf("[ ");
    for ( ; lo < last; lo++ ) {
        printf("%d ", array[lo]);
    }
    if ( hi > 0 ) {
        printf("%d ]\n", array[last]);
    } else {
        printf("]\n");
    }
}

int main() {
    int hi = 7;
    int mid = 4;
    int lo = 1;
    int array[] = {2, 5, 6, 8, 7, 8, 9, 10};
    
    // lo-mid -> 5, 6, 8
    // mid-hi -> 7, 8, 9
    
    merge(array, lo, mid, hi);
    arrayPrint(array, lo, hi);
    
    return 0;
}

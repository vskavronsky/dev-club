#include <stdio.h>

int arraySize(FILE *in) {
    int size;
    
    fscanf(in, "%d", &size);
    return size;
}

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

void mergeSort(int array[], int first, int last) {
    int mid = (first + last) / 2;
    
    if ( first == mid ) {
        return;
    }
    
    mergeSort(array, first, mid);
    mergeSort(array, mid, last);
    merge(array, first, mid, last);
}

int main() {
    FILE *in = fopen("mergeSortIn.txt", "r");
    FILE *out = fopen("mergeSortOut.txt", "w");
    int size = arraySize(in);
    int last = size - 1;
    int array[size];
    
    for ( int i = 0; i < size && fscanf(in, "%d", &array[i]) == 1; i++ );
    
    mergeSort(array, 0, size);
    
    for ( int j = 0; j < last; j++ ) {
        fprintf(out, "%d ", array[j]);
    }
    fprintf(out, "%d\n", array[last]);
    
    return 0;
}

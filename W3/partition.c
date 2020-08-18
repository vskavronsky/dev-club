#include <stdio.h>

int partition(int array[], int start, int end) {
    int mid = (start + end) / 2;
    int temp = array[end];
    int partitionIndex = start;
    
    array[end] = array[mid];
    array[mid] = temp;
    
    for ( ; array[partitionIndex] < array[end]; partitionIndex++ );
    for ( int i = partitionIndex + 1; i < end; i++ ) {
        if ( array[i] < array[end] ) {
            temp = array[partitionIndex];
            
            array[partitionIndex] = array[i];
            array[i] = temp;
            partitionIndex += 1;
        }
    }
    temp = array[partitionIndex];

    array[partitionIndex] = array[end];
    array[end] = temp;
    
    return partitionIndex;
}

int partition2(int array[], int start, int end) {
    int pivot = array[end];
    int partitionIndex = start;
    
    for ( int i = start; i < end; i++ ) {
        if ( array[i] <= pivot ) {
            int temp = array[i];
            
            array[i] = array[partitionIndex];
            array[partitionIndex] = temp;
            partitionIndex += 1;
        }
    }
    int temp = array[partitionIndex];
    
    array[partitionIndex] = array[end];
    array[end] = temp;
    
    return partitionIndex;
}

void arrayPrint(int array[], int lo, int hi) {
    printf("[ ");
    for ( ; lo < hi; lo++ ) {
        printf("%d ", array[lo]);
    }
    if ( hi > 0 ) {
        printf("%d ]\n", array[hi]);
    } else {
        printf("]\n");
    }
}

int main() {
    int start = 0;
    int end = 7; 
    int array[] = {7, 2, 1, 6, 8, 5, 3, 4};
    
    partition(array, start, end);
    arrayPrint(array, start, end);
    
    return 0;
}

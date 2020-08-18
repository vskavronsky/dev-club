#include <stdio.h>

int arraySize(FILE *in) {
    int size;
    
    fscanf(in, "%d", &size);
    return size;
}

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

void quickSort(int array[], int start, int end) { 
    if ( start < end ) {
        int partitionIndex;
        
        partitionIndex = partition(array, start, end);
        quickSort(array, start, partitionIndex-1);
        quickSort(array, partitionIndex+1, end);
    }
}

int main() {
    FILE *in = fopen("quickSortIn.txt", "r");
    FILE *out = fopen("quickSortOut.txt", "w");
    int size = arraySize(in);
    int last = size - 1;
    int array[size];
    
    for ( int i = 0; i < size && fscanf(in, "%d", &array[i]) == 1; i++ );
    
    quickSort(array, 0, last);
    
    for ( int j = 0; j < last; j++ ) {
        fprintf(out, "%d ", array[j]);
    }
    fprintf(out, "%d\n", array[last]);
    
    return 0;
}

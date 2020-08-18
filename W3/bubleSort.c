#include <stdio.h>

void bubbleSort(int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        int limit = last - i;
        
        for ( int j = 0; j < limit; j++ ) {
            int next = j + 1;
            
            if ( array[j] > array[next] ) {
                int temp = array[j];
                
                array[j] = array[next];
                array[next] = temp;
            }
        }
    }
}

void bubbleSortMod(int array[], int size) {
    int last = size - 1;
    int isSorted = 0;
    
    for ( int i = 0; i < last && !isSorted; i++ ) {
        int limit = last - i;
        
        isSorted = 1;
        
        for ( int j = 0; j < limit; j++ ) {
            int next = j + 1;
            
            if ( array[j] > array[next] ) {
                int temp = array[j];
                
                array[j] = array[next];
                array[next] = temp;
                isSorted = 0;
            }
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
    int size = 10;
    int array[] = {0, 62, -33, -46, 91, -11, 55, 84, 73, 110}; // [ -46 -33 -11 0 55 62 73 84 91 110 ]
    
    insertSortMod(array, size);
    
    arrayPrint(array, size);
    
    return 0;
}

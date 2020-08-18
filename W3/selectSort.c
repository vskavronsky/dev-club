#include <stdio.h>

void selectSort(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        int min = i;
        
        for ( int j = i + 1; j < size; j++ ) {
            if ( array[min] > array[j] ) {
                min = j;
            }
        }
        if ( min != i ) {
            int temp = array[min];
            
            array[min] = array[i];
            array[i] = temp;
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
    int array[] = {10, 9, 7, 8, 6, 5, 4, 1, 2, 3};
    
    selectSort(array, size);
    arrayPrint(array, size);
    
    return 0;
}

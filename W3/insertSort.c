#include <stdio.h>

void insertSort(int array[], int size) {
    for ( int i = 1; i < size; i++ ) {
        int temp = array[i];
        int j = i;
        
        for ( int prev = j - 1; j > 0 && array[prev] > temp; j--, prev-- ) {
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
    int array[] = {10, 9, 7, 8, 6, 5, 4, 1, 2, 3};
    
    insertSort(array, size);
    arrayPrint(array, size);
    
    return 0;
}

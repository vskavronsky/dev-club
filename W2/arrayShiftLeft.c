#include <stdio.h>

void arrayShiftLeft(int array[], int size) {
    int temp = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        array[i-1] = array[i];
    }
    array[size-1] = temp;
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
    int size = 7;
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    
    arrayShiftLeft(array, size);
    
    arrayPrint(array, size);
    
    return 0;
}

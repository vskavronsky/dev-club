#include <stdio.h>

void arrayShiftRight(int array[], int size) {
    int last = size - 1;
    int first = array[last];
    
    for ( ; last > 0; last-- ) {
        array[last] = array[last-1];
    }
    array[0] = first;
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
    
    arrayShiftRight(array, size);
    
    arrayPrint(array, size);
    
    return 0;
}

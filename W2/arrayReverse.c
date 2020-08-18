#include <stdio.h>

void arrayReverse(int array[], int size) { // working with one address of array
    for ( int input = 0, reverse = size - 1; input < reverse; input++, reverse-- ) {
        int temp = array[input]; // 2
        
        array[input] = array[reverse]; // {10, 9, 3, 4, 5, 6, 7, 8, 9, 10}
        array[reverse] = temp; // {10, 9, 3, 4, 5, 6, 7, 8, 2, 1}
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
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // array = pointer, that holds address of the first element
    
    arrayReverse(array, size); // working with one address of array
    
    arrayPrint(array, size);
    
    return 0;
}

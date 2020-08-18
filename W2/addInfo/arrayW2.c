#include <stdio.h>

void arrayZeroFill(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        array[i] = 0;
    }
}

void arrayIncrement(int array[], int size, int increment) {
    for ( int i = 0; i < size; i++ ) {
        array[i] += increment;
    }
}

void print( int array[], int size ) {
    int limit = size - 1;
    
    printf("[");
    for ( int i = 0; i < limit; i++ ) {
        printf("%d, ", array[i]);
    }
    if ( size > 0 ) {
        printf("%d]\n", array[limit]);
    } else {
        printf("]\n");    
    }
    
}

int main() {
    int size = 7;
    int array2[] = {10, 20, 30, 40, 50, 60, 70};
    
    
    // array2[1] = 777;
    
    print(array2, size);
    arrayIncrement(array2, size, 3);
    print(array2, size);
    
    print("%d\n", array2[4]);
    print("");
    
    return 0;
}

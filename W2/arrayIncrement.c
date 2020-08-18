#include <stdio.h>

void arrayIncrement(int array[], int size) {
    int limit = size - 1;
    
    printf("[ ");
    for ( int i = 0; i < limit; i++ ) {
        printf("%d, ", array[i] += 1);
    }
    if ( size > 0 ) {
        printf("%d ]\n", array[limit] += 1);
    } else {
        printf(" ]\n");
    }
}

int main() {
    int size = 10;
    int array2[] = {98, -2, 645, 34, 6, 13, 2146, 33, 9, 0};
    
    arrayIncrement(array2, size);
    
    return 0;
}

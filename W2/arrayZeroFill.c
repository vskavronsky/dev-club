#include <stdio.h>

void arrayZeroFill(int array[], int size) {
    int limit = size - 1;
    
    printf("[ ");
    for ( int i = 0; i < limit; i++ ) {
        printf("%d, ", array[i] = 0);
    }
    if ( size > 0 ) {
        printf("%d ]\n", array[limit] = 0);
    } else {
        printf(" ]\n");
    }
}

int main() {
    int size = 10;
    int array2[size];
    
    arrayZeroFill(array2, size);
    
    return 0;
}

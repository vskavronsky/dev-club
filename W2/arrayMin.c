#include <stdio.h>

int arrayMin(int array[], int size) {
    int min = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( min > array[i] ) {
            min = array[i];
        }
    }
    return min;
}

int main() {
    int size = 10;
    int array[] = {0, 10, 20, 30, 40, 50, 60, -70, -20, -10};
    
    printf("min number of the array - %d\n", arrayMin(array, size));
    
    return 0;
}

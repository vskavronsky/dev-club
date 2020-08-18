#include <stdio.h>

int arrayMax(int array[], int size) {
    int max = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( max < array[i] ) {
            max = array[i];
        }
    }
    return max;
}

int main() {
    int size = 10;
    int array[] = {0, 10, 20, 30, 40, 50, 60, -70, -20, -10};
    
    printf("max number of the array - %d\n", arrayMax(array, size));
    
    return 0;
}

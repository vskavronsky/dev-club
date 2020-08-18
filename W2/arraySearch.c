#include <stdio.h>

int arraySearch(int array[], int size, int needle) {
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] == needle ) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size = 10;
    int needle = 9;
    int array[] = {67, 239, 0, 11, -8, -990, 51, 5963, 9, 1001};
    
    printf("index of needle - %d\n", arraySearch(array, size, needle));
    
    return 0;
}

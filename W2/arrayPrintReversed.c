#include <stdio.h>

void arrayPrintReversed(int array[], int size) {
    for ( int i = size - 1; i > 0; i-- ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[0]);
}

int main() {
    int size = 10;
    int array[] = {10, 11, 12, 13, 14, 15, 16, 17, 18 ,19};
    
    arrayPrintReversed(array, size);
        
    return 0;
}

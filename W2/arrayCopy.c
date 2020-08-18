#include <stdio.h>

void arrayCopy(int destination[], int source[], int size) {
    for ( int i = 0; i < size; i++ ) {
        destination[i] = source[i];
    }
}

int main() {
    int size = 10;
    int arraySourse[] = {30, -98, 332, 7, 2376, 0, -11, 670, 2, -311};
    int arrayDestination[size];
    
    arrayCopy(arrayDestination, arraySourse, size);
    
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", arraySourse[i]);
    }
    printf("%d\n", arraySourse[last]);
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", arrayDestination[i]);
    }
    printf("%d\n", arrayDestination[last]);

    return 0;
}

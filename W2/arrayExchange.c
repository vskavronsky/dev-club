#include <stdio.h>

void arrayExchange(int array[], int len) {
    for ( int i = 1; i < len; i += 2 ) {
        int temp = array[i];
        
        array[i] = array[i-1];
        array[i-1] = temp;
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
    int size = 8;
    int array[] = {2, 1, 4, 3, 6, 5, 8, 7}; 
    
    arrayExchange(array, size);
    
    arrayPrint(array, size);
    
    return 0;
}

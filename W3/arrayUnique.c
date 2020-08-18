#include <stdio.h>

int arrayUnique(int array[], int size) {
    int marker = array[0];
    int len = 1;
    
    for ( int i = 1; i < size; i++ ) {
        if ( array[i] != marker ) {
            array[len] = array[i];
            
            for ( int j = i + 1; j < size; j++ ) {
                if ( array[j] == array[len] ) {
                    array[j] = marker;
                }
            }
            len += 1;
            for ( int i = 0; i < size; i++ ) {
                printf("%d ", array[i]);
            }
            printf("\n");
            for ( int i = 0; i < size; i++ ) {
                printf("%d ", i);
            }
            printf("\n----------------------------------------------");
            printf("len - %d\n", len);
        }
    }
    return len;
}

// {1, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7, 7, 8, 9, 10, 1, 2, 3};

// i = 1 - {1, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7, 7, 8, 9, 10, 1, 2, 3}; len = 1
// i = 2 - {1, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7, 7, 8, 9, 10, 1, 2, 3}; len = 2

int main() {
    int size = 18;
    int array[] = {1, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7, 7, 8, 9, 10, 1, 2, 3};    
    
    printf("new size of array - %d", arrayUnique(array, size));
    
    return 0;
}

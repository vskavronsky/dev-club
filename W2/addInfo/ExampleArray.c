#include <stdio.h>

// void arrayScan(int array[], int size) {
//     for ( int i = 0; i < 5; i++ ) {
//         scanf("%d", &array[i]);
//     }
// }

// void arrayPrint(int array[], int size) {
//     int last = size - 1;
    
//     for ( int i = 0; i < last; i++ ) {
//         printf("%d ", array[i]);
//     }
//     printf("%d\n", array[last]);
// }

int main() {
    // int array[5];
    
    // printf("Array address: %p\n", array); // initial address of array - 0060FEEC
    // printf("Size of array: %lu bytes\n", sizeof(array)); // 5*4 = 20 byte
    
    // int magicNumber = 42;
    // int numbers[3] = {1, 2, 3};
    
    // // printf("%d %d %d\n", numbers[0], numbers[1], numbers[2]);
    // printf("%d\n", numbers[3]); // random value - 4200864
    
    // int array[3];
    
    // scanf("%d", &array[0]); // 2
    // scanf("%d", &array[1]);
    // scanf("%d", &array[2]);
    
    // printf("%d\n", array[0]); // 2
    // printf("%d\n", array[1]);
    // printf("%d\n", array[2]);
    
    // int size = 5;
    // int array[size];
    
    // arrayScan(array, size);
    
    // arrayPrint(array, size);
    
    int *pointer;
    int array[5] = {1, 2, 3, 4, 5};
    
    pointer = array;
    
    printf("%d\n", pointer[4]);
    printf("%d\n", *(pointer+4));
    
    // printf("%p\n", array);
    // printf("%d\n", *array); // *(array+0)
    // printf("%d\n", *(array+1)); // array[1]
    // printf("%d\n", *(array+2));
    // printf("%d\n", *(array+3));
    // printf("%d\n", *(array+4));
    
    // printf("%d\n", *(array+90)); // 524298
    // printf("%d\n", *(array+190)); // 721408
    
    return 0;
}

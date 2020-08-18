#include <stdio.h>

void arrayAbs(int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        if ( array[i] < 0 ) {
            array[i] *= -1;
        }
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

// epic win
// void arrayAbs(int array[], int size) {
//     for ( int i = 0; i < size; i++ ) {
//         if ( array[i] < 0 ) {
//             array[i] *= -1;
//         }
//     }
// }

int main() {
    int size = 10;
    int array[] = {10, -11, 12, 13, -14, -15, 16, -17, -18 ,19};
    
    arrayAbs(array, size);
        
    return 0;
}

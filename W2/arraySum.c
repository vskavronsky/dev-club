#include <stdio.h>

int arraySum(int array[], int size) {
    int sum = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        sum += array[i];
    }
    return sum;
}

int main() {
    int size = 10;
    int array[] = {0, 10, 20, 30, 40, 50, 60, -70, -20, -10};
    
    printf("sum of array elements - %d\n", arraySum(array, size));
    
    return 0;
}

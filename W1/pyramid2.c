#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int column = 0, counter = 1; column < size; column++ ) {
        for ( int row = 0; row < column; row++ ) {
            printf("%d ", counter);
            counter += 1;
        }
        printf("%d\n", counter);
        counter += 1;
    }
    return 0;
}

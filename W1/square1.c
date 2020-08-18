#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int column = 1; column <= size; column++ ) {
        for ( int row = 1; row < size; row++ ) {
            printf("%d ", row);
        }
        printf("%d\n", size);
    }
    
    return 0;
}

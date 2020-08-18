#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int column = 1; column <= size; column++ ) {
        for ( int row = 1; row < column; row++ ) {
            printf("%d ", row);
        }
        printf("%d\n", column);
    }
    return 0;
}

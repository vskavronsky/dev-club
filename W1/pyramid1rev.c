#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( ; 1 <= size; ) {
        for ( int row = 1; row < size; row++ ) {
            printf("%d ", row);
        }
        printf("%d\n", size);
        size -= 1;
    }
    return 0;
}

#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int column = 0, total = size * size; column < size; column++ ) {
        for ( int row = 1, counter = total - size; row < size; row++ ) {
            counter += 1;
            printf("%d ", counter);
        }
        printf("%d\n", total);
        total -= size;
    }
    
    return 0;
}

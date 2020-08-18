#include <stdio.h>

int main() {
    int size;
    int x, y;
    
    scanf("%d", &size);
    for ( int i = 0; i < size; i++ ) {
        scanf("%d", &x);
        if ( i == 0 ) {
           y = x; 
        }
        if ( y > x ) {
            printf("no\n");
            return 0;
        }
        y = x;
    }
    printf("yes\n");

    return 0;
}

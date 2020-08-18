#include <stdio.h>

int main() {
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    if ( x < 0 && y < 0 ) {
        printf("bravo\n");
    } else if ( y == 0 ) {
        printf("charlie\n");
    } else if (  x <= y ) {
        printf("alpha\n");
    } else {
        printf("zulu\n");
    }
    
    return 0;
}

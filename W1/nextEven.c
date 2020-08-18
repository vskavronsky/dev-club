#include <stdio.h>

int main() {
    int x;

    scanf("%d", &x);

    // if ( x % 2 != 0 ) {
    //     printf("%d\n", x+1);
    // } else {
    //     printf("%d\n", x);
    // }
    
    if ( x % 2 != 0 ) {
        x += 1;
    }
    
    printf("%d\n", x);
    
    return 0;
}

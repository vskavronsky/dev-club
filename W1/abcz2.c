#include <stdio.h>

int main() {
    int x;
    int a = 1;
    
    scanf("%d", &x);
    
    if ( x % 2 == 0 ) {
        printf("alpha\n");
        a = 0;
    }
    if ( x % 3 == 0 ) {
        printf("bravo\n");
        a = 0;
    }
    if ( x % 5 == 0 ) {
        printf("charlie\n");
        a = 0;
    }
    if ( a ) {
        printf("zulu\n");
    }
    // if ( a == 1 ) {
    //     printf("zulu\n");
    // }
    
    return 0;
}

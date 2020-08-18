#include <stdio.h>

int main() {
    int powerOf2;
    
    scanf("%d", &powerOf2);
    
    if ( !(powerOf2 & (powerOf2 - 1)) ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    // printf("%d\n", !powerOf2);
    
    // printf("2 << %d == %d\n", powerOf2, 2 << powerOf2);
    
    // for ( int i = 1; i <= powerOf2; i *= 2 ) {
    //     if ( i == powerOf2 ) {
    //         printf("yes\n");
    //         return 0;
    //     }
    // }
    
    // printf("no\n");
    
    return 0;
}

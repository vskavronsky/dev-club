#include <stdio.h>

int main() {
    int divisor, remainder;
    
    scanf("%d", &divisor);
    
    printf("0/1 ");
    
    for ( int i = divisor; i > 1; i-- ) {
        for ( int j = 1; j < i; j++ ) {
            remainder = j % i;
            if ( j % i == 1 ) {
                printf("%d/%d ", j, i);
            } else if ( i % remainder == 1 ) {
                printf("%d/%d ", j, i);
            }
        }
    }
        
    printf("1/1\n");
    
    return 0;
}

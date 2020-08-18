#include <stdio.h>

int main() {
    int dividend, divisor, remainder;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( divisor < 0 ) {
        divisor *= -1;
    }
    remainder = dividend % divisor;
    if ( remainder <= 0 ) {
        dividend += remainder;
    } else {
        dividend -= divisor - remainder;
    }
    printf("%d\n", dividend);
    
    return 0;
}

#include <stdio.h>

int main() {
    int dividend, divisor, prevMultiple;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( divisor < 0 ) {
        divisor *= -1;
    }
    prevMultiple = dividend - dividend % divisor; // positive and zero dividend
    
    if ( prevMultiple > dividend ) { // negative dividend
        prevMultiple -= divisor;
    }
    printf("%d\n", prevMultiple);
    
    // prevMultiple = dividend - dividend % divisor;
    // if ( dividend < 0 && dividend % divisor != 0 ) {
    //     prevMultiple -= divisor;
    // }
    // printf("%d\n", prevMultiple);
    
    return 0;
}

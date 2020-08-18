#include <stdio.h>

int main() {
    int dividend, divisor, /*remainder*/ nextMultiple;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( divisor < 0 ) {
        divisor *= -1;
    }
    nextMultiple = dividend - dividend % divisor; // negative and zero dividend
    
    if ( nextMultiple < dividend ) { // positive dividend
        nextMultiple += divisor;
    }
    printf("%d\n", nextMultiple);
    
    // remainder = dividend % divisor;
    // if ( remainder <= 0 ) {
    //     dividend -= remainder;
    // } else {
    //     dividend += divisor - remainder;
    // }
    // printf("%d\n", dividend);
    
    return 0;
}

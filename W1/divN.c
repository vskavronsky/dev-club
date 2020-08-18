#include <stdio.h>

int main() {
    int min, max;
    // int remainder;
    int multiple;
    int divisor;
    
    scanf("%d %d %d", &min, &max, &divisor);
    
    // remainder = min % divisor;
    // if ( remainder <= 0 ) {
    //     min -= remainder;
    // } else {
    //     min += divisor - remainder;
    // }
    
    multiple = min - min % divisor;
    if ( multiple < min ) {
        multiple += divisor;
    }
    for ( ; multiple <= max; multiple += divisor ) {
        printf("%d\n", multiple);
    }
    return 0;
}

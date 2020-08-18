#include <stdio.h>

#define DIVISOR 3

int main() {
    int min, max, remainder;
    
    scanf("%d %d", &min, &max);
    
    remainder = min % DIVISOR;
    if ( remainder <= 0 ) {
        min -= remainder;
    } else {
        min += DIVISOR - remainder;
    }
    for ( ; min <= max; min += DIVISOR ) {
        printf("%d\n", min);
    }
    
    return 0;
}

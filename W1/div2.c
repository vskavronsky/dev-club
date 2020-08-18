#include <stdio.h>

#define DIVISOR 2

int main() {
    int min, max;
    
    scanf("%d %d", &min, &max);
    
    // min += min % DIVISOR;
    
    if ( min % DIVISOR != 0 ) {
        min += 1;
    }
    for ( ; min <= max; min += DIVISOR ) {
        printf("%d\n", min);
    }
    
    return 0;
}

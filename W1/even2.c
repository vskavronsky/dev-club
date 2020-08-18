#include <stdio.h>

#define DIVISOR 2

int main() {
    int min, max;
    
    scanf("%d %d", &min, &max);
    
    if ( min % DIVISOR != 0 ) {
        min += 1;
    }
    max -= max % DIVISOR;
    for ( ; min < max; min += DIVISOR ) {
        printf("%d ", min);
    }
    printf("%d\n", max);
    
    return 0;
}

#include <stdio.h>

#define DIVISOR 2

int main() {
    int min, max;
    int power;
    
    scanf("%d %d", &min, &max);
    
    if ( min % DIVISOR != 0 ) {
        min += 1;
    }
    max -= max % DIVISOR;
    for ( ; min < max; min += DIVISOR ) {
        power = min * min;
        printf("%d ", power);
    }
    printf("%d\n", max*max);
    
    return 0;
}

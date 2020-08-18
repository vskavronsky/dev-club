#include <stdio.h>

#define DIVISOR 2

int main() {
    int min, max;
    int power;
    
    scanf("%d %d", &min, &max);
    
    if ( min % DIVISOR == 0 ) {
        min += 1;
    }
    if ( max % DIVISOR == 0 ) {
        max -= 1;
    }
    for ( ; min < max; min += DIVISOR ) {
        power = min * min * min;
        printf("%d ", power);
    }
    max *= max * max;
    printf("%d\n", max);
    
    return 0;
}

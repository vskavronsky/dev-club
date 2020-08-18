#include <stdio.h>

#define DIVIDER 10

int main() {
    int number;
    int counter = 1;
    
    scanf("%d", &number);
    
    if ( number > 0 ) {
        counter -= 1;
    }
    for ( ; number != 0; counter++ ) {
        number /= DIVIDER;
    }
    
    printf("%d\n", counter);
    
    return 0;
}

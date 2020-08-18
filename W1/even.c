#include <stdio.h>

#define DIVISOR 2

int main() {
    int element;
    
    scanf("%d", &element);
    
    element -= element % DIVISOR;
    
    // if ( element % 2 != 0 ) {
    //     element -= 1;
    // }
    
    for ( int i = 0; i < element; i += DIVISOR ) {
        printf("%d ", i);
    }
    printf("%d\n", element);
    
    return 0;
}

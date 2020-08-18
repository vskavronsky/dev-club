#include <stdio.h>

int main() {
    int number;
    int counter = 0;
    
    scanf("%d", &number);
    
    for ( int divisor = 1; divisor <= number; divisor++ ) {
        if ( number % divisor == 0 ) {
            counter += 1;
        }
    }
    printf("%d\n", counter);
    
    return 0;
}

#include <stdio.h>

#define SUBTRACTOR 10

int main() {
    int number, base;
    int maxPower = 1;
    
    scanf("%d %d", &number, &base);
    
    if ( number < 0 ) {
        printf("%c", '-');
        number *= -1;
    }
    for ( int limit = number / base; maxPower <= limit; maxPower *= base );
    
    for ( ; maxPower > 0; maxPower /= base ) {
        int element = number / maxPower;
        
        if ( element >= 0 && element <= 9 ) {
            printf("%c", '0'+element);
        } else {
            int upperCase = element - SUBTRACTOR;
            
            printf("%c", 'A'+upperCase);
        }
        number %= maxPower;
    }
    printf("\n");
    
    return 0;
}

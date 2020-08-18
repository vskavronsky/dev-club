#include <stdio.h>

int main() {
    int number, base;
    int maxPower = 1;
    
    scanf("%d %d", &number, &base);
    
    for ( int limit = number / base; maxPower <= limit; maxPower *= base );
    
    for ( ; maxPower > 0; maxPower /= base ) {
        printf("%d", number / maxPower);
        number %= maxPower; 
    }
    printf("\n");
    
    return 0;
}

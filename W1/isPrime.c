#include <stdio.h>

int isPrime(int n) {
    if ( n <= 1 ) {
        return 0;
    }
    for ( int divisor = 2; divisor < n; divisor++ ) {
        if ( n % divisor == 0 ) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int number;
    
    scanf("%d", &number);
    
    printf("%d\n", isPrime(number));
    
    return 0;
}

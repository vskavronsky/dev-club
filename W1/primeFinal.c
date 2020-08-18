#include <stdio.h>

int isPrime(int n) {
    for ( int divisor = 2; divisor < n; divisor++ ) {
        if ( n % divisor == 0 ) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int element;
    int primeNumber;
    
    scanf("%d", &element);
    
    if ( element <= 0 ) {
        printf("-1\n");
        return 0;
    }
    
    primeNumber = 1;
    for ( ; element > 0; ) {
        primeNumber += 1;
        if ( isPrime(primeNumber) ) {
            element -= 1;
        }
        if ( element == 0 ) {
            printf("%d\n", primeNumber);
            return 0;
        }
    }
}

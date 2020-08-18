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
    int element;
    
    scanf("%d", &element);
    
    if ( element <= 0 ) {
        printf("-1\n");
        return 0;
    }
    
    // if ( element == 1 ) {
    //     printf("2\n");
    //     return 0;
    // }
    
    // if ( element == 2 ) {
    //     printf("3\n");
    //     return 0;
    // }
    
    int primeNumber = 0;
    while (element > 0) {
        primeNumber++;
        int result = isPrime(primeNumber);
        if (result == 1) {
            element--;
        }
        if (element == 0) {
            printf("%d", primeNumber);
            return 0;
        }
            
    }
    
    
    
    
    // for ( int divisor = 2, n = 5; divisor < n; divisor++, n++ ) {
    //     if ( n % divisor == 0 ) {
    //         divisor = 3;
    //         n += 1;
    //     } else if ( n % divisor == 0 ) {
    //         divisor = 5;
    //         n += 1;
    //     } else if ( n % divisor == 0 ) {
    //         divisor = 7;
    //         n += 1;
    //     } else if ( n % divisor == 0 ) {
    //         n += 1;
    //     }
    //     if ( element == 3 ) {
    //         printf("%d\n", n);
    //         return 0;
    //     }
    //     element -= 1;
    // }
    
    // return 0;
}

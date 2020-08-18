#include <stdio.h>

int fibonacci(int n) {
    int f1 = 0;
    int f2 = 1;
    
    if ( n == 0 ) {
        return 0;
    }
    if ( n == 1 || n == -1 ) {
        return 1;
    }
    if ( n < -1 ) {
        for ( int i = -2; i >= n; i-- ) {
            int f = f2;
            
            f2 += f1;
            f1 = f;
        }
        if ( n % 2 == 0 ) {
            f2 *= -1;
        }
        return f2;
    }
    if ( n > 1 ) {
        for ( int i = 2; i <= n; i++ ) {
            int f = f2;
            
            f2 += f1;
            f1 = f;
        }
        return f2;
    }
    return 0;
}

int main() {
    int number;
    
    scanf("%d", &number);
    
    if ( number > 46 || number < -46 ) {
        return 0;
    }
    printf("%d\n", fibonacci(number));
    
    return 0;
}

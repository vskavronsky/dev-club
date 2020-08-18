#include <stdio.h>

int fibonacci(int n) {
    if ( n == 0 ) {
        return 0;
    }
    if ( n == 1 || n == 2 ) {
        return 1;
    }
    if ( n < 0 ) {
        return fibonacci(n+2) - fibonacci(n+1);
    }
    
    return fibonacci(n-1) + fibonacci(n-2);
}
// epic win
// int fibonacci(int n) {
//     if ( n == 0 ) {
//         return 0;
//     }
//     if ( n == 1 || n == -1 ) {
//         return 1;
//     }
//     if ( n < 0 ) {
//         return fibonacci(n+2) - fibonacci(n+1);
//     }
//     return fibonacci(n-1) + fibonacci(n-2);
// }
    
int main() {
    int number;
    
    scanf("%d", &number);
    
    printf("%d\n", fibonacci(number));
    
    return 0;
} 

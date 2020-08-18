#include <stdio.h>

int main() {
    int number;
    int factorial = 1;
    
    scanf("%d", &number);
    
    if ( number < 0 ) {
        printf("-1\n");
        return 0;
    }
    for ( int i = 2; i <= number; i++ ) {
        factorial *= i;
    }
    printf("%d\n", factorial);
    
    return 0;
}

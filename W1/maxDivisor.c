#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);
    for ( int i = 0, divisor = number - 1; i < number; divisor -= 1, i++ ) {
        if ( divisor <= 1 ) {
            printf("0\n");
            return 0;
        } else if ( number % divisor == 0 ) {
            printf("%d\n", divisor);
            return 0;
        } 
    }
    return 0;
}

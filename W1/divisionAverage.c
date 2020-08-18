#include <stdio.h>

int main() {
    unsigned int x, y;
    
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);
    
    printf("Average of two numbers - %d\n", x / 2 + y / 2 + ( x % 2 + y % 2 ) / 2);
    printf("Average of two numbers - %d\n", (x + y) / 2 );
    
    return 0;
}

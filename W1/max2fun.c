#include <stdio.h>

int max2(int x, int y);

int main() {
    int num1, num2;
    
    scanf("%d %d", &num1, &num2);
    
    printf("%d\n", max2(num1, num2));
    
    return 0;
}

int max2(int x, int y) {
    if ( x > y ) {
        return x;
    } 
    return y;
}

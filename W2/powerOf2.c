#include <stdio.h>

int powerOf2(int exponent) {
    return 1 << exponent;
}

int main() {
    int exp;
    
    scanf("%d", &exp);
    
    printf("%d\n", powerOf2(exp));
    
    return 0;
}

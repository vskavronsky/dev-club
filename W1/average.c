#include <stdio.h>

unsigned int average(unsigned int a, unsigned int b) {
    return a / 2 + b / 2 + (a % 2 + b % 2) / 2;
}

int main() {
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    printf("%d", average(x, y));
    
    return 0;
}

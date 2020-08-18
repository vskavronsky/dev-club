#include <stdio.h>

int average(int a, int b) {
    int min, max;
    
    min = -32768; // min = -32767;
    max = 32767;
    
    if ( a + b > max || a + b < min ) {
        return a / 2 + b / 2;
    }
    return (a + b) / 2;
}

int main() {
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    printf("%d", average(x, y));
    
    return 0;
}

#include <stdio.h>

int main() {
    int base, power;
    int i = 1;
    
    scanf("%d %d", &base, &power);
    
    for ( int count = 0; count < power; count++, i *= base ) {
        printf("%d ", i);
    }
    printf("%d\n", i);
    
    return 0;
}

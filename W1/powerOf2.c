#include <stdio.h>

int main() {
    int power;
    int i = 1;
    
    scanf("%d", &power);
    
    for ( int count = 0; count < power; count++, i *= 2 ) {
        printf("%d ", i);
    }
    printf("%d\n", i);
    
    return 0;
}

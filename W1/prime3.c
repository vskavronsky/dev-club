#include <stdio.h>

#define INT_MAX 2147483647

int main() {
    int element;
    int d = 3;
    int counter = 2;
    
    scanf("%d", &element);
    
    if ( element <= 0 ) {
        printf("-1\n");
        return 0;
    }
    
    if ( element == 1 ) {
        printf("2\n");
        return 0;
    }
    
    
    if ( element == 2 ) {
        printf("3\n");
        return 0;
    for ( int i = 3; i < INT_MAX; i += 2 ) {       
        for ( ; d * d <= i && i % d != 0; ) {
            d += 2;
        }
        
        if ( d * d > i ) {
            if ( counter == element ) {
                printf("%d\n", i);
                return 0;
            }
            counter++;
        }
    }
    printf("-1\n");
    return 0;
}

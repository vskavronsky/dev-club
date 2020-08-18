#include <stdio.h>

int main() {
    int element;
    int d = 3;
    int INT_MAX = sizeof(int);
    
    scanf("%d", &element);
    
    if ( element <= 0 ) {
        printf("-1\n");
        return 0;
    }
    for ( int i = element + 1; i < INT_MAX; i++ ) {
        if ( i % 2 == 0 && i != 2 ) {
            continue;
        }
        while ( d * d <= i && i % d != 0 ) {
            d += 2;
        }
        if ( d * d > i ) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

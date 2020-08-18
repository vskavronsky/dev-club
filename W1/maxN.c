#include <stdio.h>

int main() {
    int count;
    int number, max;
    
    scanf("%d\n%d", &count, &max);
    
    for ( int i = 2; i <= count; i++ ) {
        scanf("%d", &number);
        if ( max < number ) {
            max = number;
        }
    }
    printf("%d\n", max);
    
    return 0;
}

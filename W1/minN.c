#include <stdio.h>

int main() {
    int count;
    int number, min;
    
    scanf("%d\n%d", &count, &min);
    
    for ( int i = 2; i <= count; i++ ) {
        scanf("%d", &number);
        if ( number < min ) {
            min = number;
        }
    }
    printf("%d\n", min);
    
    return 0;
}

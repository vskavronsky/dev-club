#include <stdio.h>

int main() {
    int element;
    
    scanf("%d", &element);
    
    if ( element % 2 == 0 ) {
        element -= 1;
    }
    
    for ( int i = 1; i < element; i += 2 ) {
        printf("%d ", i);
    }
    printf("%d\n", element);
    
    return 0;
}

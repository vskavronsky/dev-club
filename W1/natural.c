#include <stdio.h>

int main() {
    int element;
    
    scanf("%d", &element);
    
    for ( int i = 1; i < element; i++ ) {
        printf("%d ", i);
    }
    printf("%d\n", element);
    
    return 0;
}

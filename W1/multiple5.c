#include <stdio.h>

#define MULTIPLE 5

int main() {
    int element;
    
    scanf("%d", &element);
    
    element -= element % MULTIPLE;
    
    for ( int i = 0; i < element; i += MULTIPLE ) {
        printf("%d ", i);
    }
    printf("%d\n", element);
    
    return 0;
}

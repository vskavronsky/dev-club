#include <stdio.h>

int main() {
    int element;
    
    scanf("%d", &element);
    
    for ( ; element > 0; element-- ) {
        printf("%d ", element);
    }
    printf("0\n");
    
    return 0;
}

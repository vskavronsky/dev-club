#include <stdio.h>

#define ELEMENT 42

int main() {
    int count;
    int number;
    
    scanf("%d\n", &count);
    
    for ( int i = 0; i < count; i++ ) {
        scanf("%d", &number);
        number ^= ELEMENT;
        printf("%d\n", number);
    }
    
    return 0;
}

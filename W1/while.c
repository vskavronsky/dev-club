#include <stdio.h>

int main() {
    int a = 0;
    
    while ( a > 2 ) {
        printf("%d\n", a);
        a += 1;
    }
    
    // do {
    //     printf("%d\n", a);
    //     a -= 1;
    // } while (a > 0);
    
    printf("%d\n", a);
    
    return 0;
}

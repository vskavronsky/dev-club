#include <stdio.h>

int main() {
    int disciminant;
    
    scanf("%d", &disciminant);
    
    if ( disciminant > 0 ) {
        printf("2\n");
    } else if ( disciminant == 0 ) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    
    return 0;
}

#include <stdio.h>

int main() {
    int personAge;
    
    scanf("%d", &personAge);
    
    if ( personAge >= 21 ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}

#include <stdio.h>

int main() {
    int countOfDays;
    
    scanf("%d", &countOfDays);
    
    if ( countOfDays == 366 ) {
        printf("yes\n");
    } else if ( countOfDays == 365 ) {
        printf("no\n");
    } else {
        printf("Invalid param\n");
    }
    
    return 0;
}

#include <stdio.h>

int main() {
    int call, cost;
    
    scanf("%d %d", &call, &cost);
    
    if ( call == 101 || call == 102 || call == 103 || call == 104 || call == 112 ) {
        printf("0$\n");
    } else if ( call > 100 && call < 999 ) {
        printf("%d$\n", cost*40);
    } else if ( call > 1000000 && call < 9999999 ) {
        printf("%d$\n", cost*1);
    } else {
        printf("-1\n");
    }
    
    return 0;
}

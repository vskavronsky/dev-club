#include <stdio.h>

int main() {
    int limit;

    scanf("%d", &limit);

    for ( int i = 1; i < limit; i += 1 ) {
        printf("%d\n ", i);
    }
    printf("%d\n", limit);

    return 0;
}

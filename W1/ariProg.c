#include <stdio.h>

int main() {
    int element, step, count;
    // int lastElement;
    
    scanf("%d %d %d", &element, &step, &count);
    
    // lastElement = firstElement + (count-1)*step;
    for ( int i = 1; i < count; i++ ) {
        printf("%d ", element);
        element += step;
    }
    printf("%d\n", element);
    
    return 0;
}

#include <stdio.h>

void pointerIncrement(int *value) { // address of x  
    *value += 1; // value of x
}

int main() {
    int x;
    void *pointer;
    
    scanf("%d", &x);
    
    pointer = &x;
    
    pointerIncrement(pointer);
    
    printf("%d\n", x);
    
    return 0;
}

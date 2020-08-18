#include <stdio.h>

// int increment(int *y) {
//     return *y += 1;
// }

int main() {
    int *pointer;
    int x = 10;
    // int y = 20;
    // int z = 30;
    
    // *pointer += 1;
    
    // printf("size of pointer: %lu\n", sizeof(pointer)); // 4 bite
    
    // increment(&x);
    // printf("value of x: %d\n", x);
    // printf("value of x * 5: %d\n", x*5);
    
    // printf("address of x: %p\n", &x);
    // printf("value of pointer: %p\n", pointer);
    // printf("address of pointer: %p\n", &pointer);
    
    pointer = &x;
    
    pointer += 100000000000000000;
    // *pointer -= 10;
    
    // pointer -= 1;
    // *pointer -= 20;
    
    printf("pointer - %d (%p)\n", *pointer, pointer); // calculating then end process
    // printf("y - %d (%p)\n", y, &y);
    // printf("z - %d (%p)\n", z, &z);
    
    // printf("pointer - %p\n", pointer);
    
    // pointer -= 1;
    // printf("pointer - %p\n", pointer); // address of y
    
    // pointer = -1;
    // printf("pointer - %p\n", pointer);
    
    return 0;
}

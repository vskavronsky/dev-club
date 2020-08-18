#include <stdio.h>

int globalVariable = 10;

int main() {
    int value = 42;
    
    {
        int localVariable = 57;
        
        printf("internal block: value = %d\n", value);
        printf("internal block: globalVariable = %d\n", globalVariable);
        // printf("internal block: localVariable = %d\n", localVariable);
        // value += 10;
        // globalVariable += 7;
    }
    printf("external block: value = %d\n", value);
    printf("external block: globalVariable = %d\n", globalVariable);
    // printf("external block: localVariable = %d\n", localVariable);
    
    return 0;
}

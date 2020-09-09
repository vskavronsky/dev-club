#include <stdio.h>

#define MAX_CELL 100

int main() {
    int maxJump;
    int cell;
    unsigned long long ways[MAX_CELL];
    FILE *in = fopen("hopperIn.txt", "r");
    FILE *out = fopen("hopperOut.txt", "w");
    
    fscanf(in, "%d %d", &maxJump, &cell);
    
    for ( int i = 0; i < maxJump; i++ ) {
        ways[i] = 1 << i;
    }
    
    for ( int i = maxJump; i < cell; i++ ) {
        ways[i] = 0;
        
        for ( int j = i - maxJump; j < i; j++ ) {
            ways[i] += ways[j]; 
        }
    }
    fprintf(out, "%llu\n", ways[cell-1]);
    
    fclose(in);
    fclose(out);
    
    return 0;
}

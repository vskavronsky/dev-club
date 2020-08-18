#include <stdio.h>

#define LIMIT 100

int main() {
    int number;
    int length = 0;
    FILE *in = fopen("seqLenIn.txt", "r");
    FILE *out = fopen("seqLenOut.txt", "w");
    
    for ( ; fscanf(in, "%d", &number) == 1 && length < LIMIT; length++ );
    
    fprintf(out, "%d\n", length);
    
    fclose(in);
    fclose(out);
    
    return 0;
}

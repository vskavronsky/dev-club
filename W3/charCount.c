#include <stdio.h>

#define ALPHABET 26
#define DIFF 32

int main() {
    FILE *in = fopen("charCountIn.txt", "r");
    FILE *out = fopen("charCountOut.txt", "w");
    int array[ALPHABET];
    char character;
    
    for ( int i = 'a'; i <= 'z'; i++ ) {
        array[i] = 0;
    }
    for ( ; fscanf(in, "%c", &character) == 1; ) {
        for ( int i = 'a'; i <= 'z'; i++ ) {
            if ( character == i || character == i - DIFF ) {
                array[i] += 1;
            }
        }
    }
    for ( int i = 'a'; i <= 'z'; i++ ) {
        if ( array[i] > 0 ) {
            fprintf(out, "%c %d\n", i, array[i]);
        }
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}

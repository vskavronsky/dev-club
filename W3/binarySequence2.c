#include <stdio.h>

int main() {
    FILE *in = fopen("binarySequenceIn.txt", "r");
    FILE *out = fopen("binarySequenceOut.txt", "w");
    int symbol;
    int zeroCounter = 0;
    int changeCounter = 0;
    
    for ( ; fscanf(in, "%1d", &symbol) == 1; ) {
        if ( symbol == 0 ) {
            zeroCounter += 1;
        }
    }
    
    rewind(in);
    for ( int j = 0; j < zeroCounter; j++ ) {
        fscanf(in, "%1d", &symbol);
        if ( symbol != 0 ) {
            changeCounter += 1;
        }
    }
    
    fprintf(out, "%d\n", changeCounter);
    
    fclose(in);
    fclose(out);
    
    return 0;
}

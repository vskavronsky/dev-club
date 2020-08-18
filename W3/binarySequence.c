#include <stdio.h>

int main() {
    FILE *in = fopen("binarySequenceIn.txt", "r");
    FILE *out = fopen("binarySequenceOut.txt", "w");
    int size = 256;
    int array[size];
    int quantity = 0;
    int oneCounter = 0;
    int changeCounter = 0;
    int limit;
    
    for ( ; quantity < size && fscanf(in, "%1d", &array[quantity]) == 1; quantity++ ) {
        if ( array[quantity] == 1 ) {
            oneCounter += 1;
        }
    }
    limit = quantity - oneCounter;
    
    for ( int i = 0; i < limit; i++ ) {
        if ( array[i] != 0 ) {
            changeCounter += 1;
        }
    }
     
    fprintf(out, "%d\n", changeCounter);
    
    fclose(in);
    fclose(out);
    
    return 0;
}

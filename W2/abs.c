#include <stdio.h>

int arraySize(FILE *in) {
    int size;
    
    fscanf(in, "%d", &size);
    return size;
}

void arrayAbs(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] < 0 ) {
            array[i] *= -1;
        }
    }
}

int main() {
    FILE *in = fopen("absIn.txt", "r");
    FILE *out = fopen("absOut.txt", "w");
    int size = arraySize(in);
    int array[size];
    int last = size - 1;
    
    for ( int i = 0; i < size && fscanf(in, "%d", &array[i]) == 1; i++ );
    
    arrayAbs(array, size);
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
    
    fclose(in);
    fclose(out);
    
    return 0;
}

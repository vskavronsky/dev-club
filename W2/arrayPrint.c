#include <stdio.h>

void arrayPrint(FILE *out, int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

int main() {
    FILE * out = fopen("arrayPrint.txt", "w");
    
    int size = 8;
    int array[] = {23, 6307, 2, 783, 5, 66, 0, -19.4};
    
    arrayPrint(out, array, size);
    
    fclose(out);
    
    return 0;
}

#include <stdio.h>

int main() {
    int size = 10;
    int last = size - 1;
    int array[size];
    FILE *in = fopen("arrayIn.txt", "r");
    FILE *out = fopen("arrayOut.txt", "w");
    
    for ( int i = 0; fscanf(in, "%d", &array[i]) == 1 && i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
    
    fclose(in);
    fclose(out);
    
    return 0;
}

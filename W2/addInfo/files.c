#include <stdio.h>

int intScan(FILE *in) {
    int number;
    
    fscanf(in, "%d", &number);
    return number;
}

void arrayPrint(FILE *out, int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

int main() {
    int x, y;
    int *z = &x;
    FILE *in = fopen("info.txt", "r");
    FILE *out = fopen("info1.out", "w");
    
    for ( int i = 0; i <= 3; i++ ) {
        y = fscanf(in, "%d", &x);
        
        printf("x: %d\n", x);
        printf("y: %d\n", y);
    }
    
    for ( int i = 0; ( fscanf(in, "%d", &x )) != EOF && ( i < 5 ); i++ ) {
        printf("x: %d\n", x);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}

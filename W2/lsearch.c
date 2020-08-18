#include <stdio.h>

int needleNum(FILE *in) {
    int needle;
    
    fscanf(in, "%d", &needle);
    return needle;
}

int arraySearch(int array[], int quantity, int needle) {
    for ( int i = 0; i < quantity; i++ ) {
        if ( array[i] == needle ) {
            return i;
        }
    }
    return -1;
}

int main() {
    FILE *in = fopen("lsearchIn.txt", "r");
    FILE *out = fopen("lsearchOut.txt", "w");
    int needle = needleNum(in);
    int size = 100;
    int array[size];
    int quantity = 0;
    
    for ( ; quantity < size && fscanf(in, "%d", &array[quantity]) == 1; quantity++ );
    
    fprintf(out, "%d\n", arraySearch(array, quantity, needle));
    
    fclose(in);
    fclose(out);
    
    return 0;
}

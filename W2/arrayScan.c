#include <stdio.h>

int arrayScan(FILE *in, int array[], int limit) {
    int quantity = 0;
    
    for ( ; quantity < limit && fscanf(in, "%d", &array[quantity]) == 1; quantity++ );
    return quantity;
}

int main() {
    int limit = 100;
    int array[limit];
    FILE *in = fopen("arrayScanIn.txt", "r");
    
    printf("%d\n", arrayScan(in, array, limit));
    
    fclose(in);
    
    return 0;
}

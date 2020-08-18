#include <stdio.h>

#define SIZE 3

void fillZero(int target[SIZE][SIZE], int size) {
    for ( int i = 0; i < size; i++ ) {
        for (int j = 0; i < size; j++ ) {
            target[i][j] = 0;
        }
    }
}

void matrixPrint(FILE *out, int matrix[SIZE][SIZE], int size) {
    int last = size - 1;
    
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < last; col++ ) {
            fprintf(out, "%d ", matrix[col][row]);
        }
        fprintf(out, "%d\n", matrix[last][row]);
    }
}

int main() {
    FILE *out = fopen("matrixPrintOut.txt", "w");
    
    int size = 3;
    int matrix[SIZE][SIZE];
    
    matrixPrint(out, matrix, size);
    
    fclose(out);
    
    return 0;
}

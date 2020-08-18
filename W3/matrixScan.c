#include <stdio.h>

#define SIZE 3
 
void matrixScan(FILE *in, int matrix[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int column = 0; column < size; column++ ) {
            fscanf(in, "%d", &matrix[column][row]);
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE], int size) {
    int lastCol = size - 1;
    
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < lastCol; col++ ) {
            printf("%d ", matrix[row][col]);
        }
        printf("%d\n", matrix[row][lastCol]);
    }
}

int main() {
    int size = 3;
    int matrix[SIZE][SIZE];
    FILE *in = fopen("matrixScanIn.txt", "r");
    
    matrixScan(in, matrix, size);
    printMatrix(matrix, size);
    
    fclose(in);
    
    return 0;
}

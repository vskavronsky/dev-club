#include <stdio.h>

#define SIZE 5

void fillMatrix(int matrix[SIZE][SIZE]) {
    int data = 1;
    
    for ( int row = 0; row < SIZE; row++ ) {
        for ( int col = 0; col < SIZE; col++ ) {
            matrix[row][col] = data;
            data += 1;
        }
    }
}

void matrixMultiply(int matrix[SIZE][SIZE], int size, int multiplier) {
    for ( int row = 0; row < size; row++ ) {
        for ( int column = 0; column < size; column++ ) {
            matrix[row][column] *= multiplier;
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
    int size = 5;
    int multiplier = 2;
    int matrix[SIZE][SIZE];
    
    fillMatrix(matrix);
    printf("\n");
    printMatrix(matrix, size);
    matrixMultiply(matrix, size, multiplier);
    printf("\n");
    printMatrix(matrix, size);
    
    return 0;
}

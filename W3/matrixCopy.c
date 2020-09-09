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

void matrixCopy(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int column = 0; column < size; column++ ) {
            target[row][column] = source[row][column];
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
    int source[SIZE][SIZE];
    int target[SIZE][SIZE];
    
    fillMatrix(source);
    matrixCopy(target, source, size);
    printf("\n");
    printMatrix(source, size);
    printf("\n");
    printMatrix(target, size);
    return 0;
}

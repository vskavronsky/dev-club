#include <stdio.h>

#define SIZE 3

void fillMatrix(int matrix[SIZE][SIZE]) {
    int data = 1;
    
    for ( int row = 0; row < SIZE; row++ ) {
        for ( int col = 0; col < SIZE; col++ ) {
            matrix[row][col] = data;
            data += 1;
        }
    }
}

void matrixRotate90(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int row = 0, rot = size - 1; row < size; row++, rot-- ) {
        for ( int col = 0; col < size; col++ ) {
            target[row][col] = source[col][rot];
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
    int source[SIZE][SIZE];
    int target[SIZE][SIZE];
    
    fillMatrix(source);
    matrixRotate90(target, source, size);
    printf("\n");
    printMatrix(source, size);
    printf("\n");
    printMatrix(target, size);
    
    return 0;
}

#include <stdio.h>

#define SIZE 3

void fillZero(int target[SIZE][SIZE], int size) {
    for ( int i = 0; i < size; i++ ) {
        for (int j = 0; i < size; j++ ) {
            target[i][j] = 0;
        }
    }
}

void fillMatrix(int matrix[SIZE][SIZE]) {
    int data = 1;
    
    for ( int row = 0; row < SIZE; row++ ) {
        for ( int col = 0; col < SIZE; col++ ) {
            matrix[row][col] = data;
            data += 1;
        }
    }
}

void printMatrix(int m[SIZE][SIZE], int size) {
    int lastCol = size - 1;
    
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < lastCol; col++ ) {
            printf("%d ", m[row][col]);
        }
        printf("%d\n", m[row][lastCol]);
    }
}

int main() {
    int size = 3;
    int matrix[size][size];
    
    fillMatrix(matrix);
    printMatrix(matrix, size);
    
    return 0;
}

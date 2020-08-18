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

void fillIncrement(int increment[SIZE][SIZE]) {
    int data = 10;
    
    for ( int row = 0; row < SIZE; row++ ) {
        for ( int col = 0; col < SIZE; col++ ) {
            increment[row][col] = data;
        }
    }
}

void matrixIncrement(int matrix[SIZE][SIZE], int increment[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int column = 0; column < size; column++ ) {
            matrix[row][column] += increment[row][column];
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
    int matrix[SIZE][SIZE];
    int increment[SIZE][SIZE];
    
    fillMatrix(matrix);
    printMatrix(matrix, size);
    printf("\n");
    
    fillIncrement(increment);
    printMatrix(increment, size);
    printf("\n");
    
    matrixIncrement(matrix, increment, size);
    printMatrix(matrix, size);
    
    return 0;
}

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

void fillDecrement(int decrement[SIZE][SIZE]) {
    int data = 10;
    
    for ( int row = 0; row < SIZE; row++ ) {
        for ( int col = 0; col < SIZE; col++ ) {
            decrement[row][col] = data;
        }
    }
}

void matrixDecrement(int matrix[SIZE][SIZE], int decrement[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int column = 0; column < size; column++ ) {
            matrix[row][column] -= decrement[row][column];
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
    int decrement[SIZE][SIZE];
    
    fillMatrix(matrix);
    printMatrix(matrix, size);
    printf("\n");
    
    fillDecrement(decrement);
    printMatrix(decrement, size);
    printf("\n");
    
    matrixDecrement(matrix, decrement, size);
    printMatrix(matrix, size);
    
    return 0;
}

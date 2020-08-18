#include <stdio.h>

int main() {
    int total, rows, cols;
    int col, row, number;
    
    scanf("%d%d%d", &total, &rows, &cols);
    
    if ( cols > rows ) {
        rows = cols;
    }
    number = cols + 1;
    for ( row = rows; row < total; row++ ) {
        for ( col = cols; col < row; col++ ) {
            printf("%d ", col+1);
        }
        printf("%d\n", col+1);
        number += 1;
    }
    return 0;
}

#include <stdio.h>

void arrayMerge(int target[], int src1[], int len1, int src2[], int len2) {
    int i = 0;
    int j = 0;
    int k = 0;
    
    for ( ; j < len1 && k < len2; i++ ) {
        if ( src1[j] <= src2[k] ) {
            target[i] = src1[j];
            j += 1;
        } else {
            target[i] = src2[k];
            k += 1;
        }
    }
    for ( ; j < len1; i++, j++ ) {
        target[i] = src1[j];
    }
    for ( ; k < len2; i++, k++ ) {
        target[i] = src2[k];
    }
}

void arrayPrint(int target[], int len3) {
    int last = len3 - 1;
    
    printf("[ ");
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", target[i]);
    }
    if ( len3 > 0 ) {
        printf("%d ]\n", target[last]);
    } else {
        printf("]\n");
    }
}

int main() {
    int len1 = 4;
    int len2 = 7;
    int len3 = len1 + len2;
    int src1[] = {1, 2, 3, 3}; 
    int src2[] = {2, 5, 5, 6, 7, 8, 9};
    int target[len3]; 
    
    arrayMerge(target, src1, len1, src2, len2);
    arrayPrint(target, len3);
    
    return 0;
}

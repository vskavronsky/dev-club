#include <stdio.h>

int gcdMinus(int a, int b) {
    for ( ; a != b; ) {
        if ( a > b ) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a + b;
}

int gcdPercent(int a, int b) {
    for ( ; a != 0 && b != 0; ) {
        if ( a > b ) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

int gcdRecursion(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcdRecursion(b, a%b);
}

int main() {
    int first = 1634896042;
    int second = 7923;
    
    // scanf("%d %d", &first, &second);
    
    printf("%d\n", gcdMinus(first, second)); /* 0.364s */
    printf("%d\n", gcdPercent(first, second)); /* 0.357s */
    printf("%d\n", gcdRecursion(first, second)); /* 0.320s */
    
    return 0;    
}

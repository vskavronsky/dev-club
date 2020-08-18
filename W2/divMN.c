#include <stdio.h>

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

int main() {
    int min, max;
    int m, n;
    int multiple;
    int divisor;
    
    scanf("%d %d %d %d", &min, &max, &m, &n);
    
    divisor = lcm(m, n);
    
    multiple = min - min % divisor; // negative and zero min
    if ( multiple < min ) { // positive min
        multiple += divisor;
    }
    for ( ; multiple <= max; multiple += divisor ) {
        printf("%d\n", multiple);
    }
    
    return 0;
}

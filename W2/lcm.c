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
    int first, second;
    FILE *in = fopen("lcmIn.txt", "r");
    FILE *out = fopen("lcmOut.txt", "w");
    
    fscanf(in, "%d %d", &first, &second);
    fprintf(out, "%d\n", lcm(first, second));
    
    fclose(in);
    fclose(out);
    
    return 0;
}

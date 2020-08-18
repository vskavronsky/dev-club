#include <stdio.h>

int main() {
    
    // from 0 till N
    for ( int k = 0; k < N; k++ ) {
        // some calculations
    }
    
    // N*42, N*M, N/4 just N
    for ( int k = 0; k < N*42; k++ ) {
        // some calculations
    }
    
    // from -N till N
    for ( int k = -N; k < N + 9; k += 17 ) {
        // some calculations
    }
    
    // O(N)*O(1) == O(N)
    for ( int k = 8108; k < N/2; k += 3 ) {
        for ( int i = 0; i < 10; i++ ) {
            // some calculations
        }
    }
    
    // O(1)*O(N) == O(N)
    for ( int k = -23; k <= N % 148; k++ ) {
        for ( int i = N - 271; i > -58; i -= N % 100 - 1 ) {
            // some calculations
        }
    }
    
    // O(N), recursive function
    int factorial(int n) {
        if ( n <= 1 ) {
            if ( n < 0 ) {
                return -1;
            }
            return 1;
        }
        return factorial(n-1) * n;
    }
    
    // O(N), recursive function, step -1
    int bench1(int n) {
        if ( n <= 0 ) {
            return 0;
        }
        return bench1(n-1);
    }
    
    return 0;
}

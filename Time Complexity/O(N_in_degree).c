#include <stdio.h>

int main() {
    
    // O(N^2), N in degree 2
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            // some calculations
        }
    }
    
    // O(N^2)
    for ( int i = 1, j = 0; i <=N; j++ ) {
        if ( j == N ) {
            i += 1;
            j = 0;
            // some calculations
        } else {
            // some calculations
        }
    }
    
    // O(N^2)
    for ( int i = 0; i < N * N; i++ ) {
        // some calculations
    }
    
    // O(N^3)
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            for ( int k = 0; k < N; k++ ) {
                // some calculations
            }
        } 
    }
    
    // O(N!)
    int limit = factorial(N);
    for ( int i = 0; i < limit; i++ ) {
        // some calculations
    }
    
    // O(2^N)
    for ( int i = 0; i < (1 << N); i++ ) {
        // some calculations
    }
    
    // O(2^N), recursive function
    int fibonacci(int n) {
        if ( n == 0 ) {
            return 0;
        }
        if ( n == 1 || n == -1 ) {
            return 1;
        }
        if ( n < 0 ) {
            return fibonacci(n+2) - fibonacci(n+1);
        }
        return fibonacci(n-1) + fibonacci(n-2);
    }
    
    // O(N)*O(N) == O(N^2), recursive function
    int bench(int n) {
        if ( n == 0 ) {
            return 0;
        }
        if ( n < 0 ) {
            return bench(n+1);
        }
        return bench(n-1) + bench(-n);
    }
    
    return 0;
}

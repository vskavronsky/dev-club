#include <stdio.h>

int main() {
    
    // O(logN)
    for ( int i = N; i > 1; i /= 2 ) {
        // some calculations
    }
     
     // O(logN)
    for ( int i = 1; i < N; i *= 4 ) {
        // some calculations
    }
    
    // O(1)*O(logN) == O(logN)
    for ( int i = 0; i < (N % 87) + 4; i += 11 ) {
        for ( int j = 2; j < N + 3489; j *= 3 ) {
            // some calculations
        }
    }
    
    // O(logN)*O(1) == O(logN)
    for ( int i = N; i >= 8; i >>= 8 ) {
        for ( int j = N % 103; j >= 33; j -= 29 ) {
            // some calculations
        }
    }
  
    // O(logN), recursive function, step /2
    int bench2(int n) {
        if ( n <= 0 ) {
            return 0;
        }
        return bench2(n/2);
    }
    
    return 0;
}

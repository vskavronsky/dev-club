#include <stdio.h>

int main() {
    
    // will perform 10 times
    for ( int k = 0; k < 10; k++ ) {
        // some calculations
    }
    
    // will perform 99 times, N % 100 gives range of values from 0 till 99
    for ( int k = 0; k < (N % 100); k++ ) {
        // some calculations
    }
    
    // will perform 3 times, k = 3-part of N
    for ( int k = 0; k < N; k += (N/3 + 1) ) {
        // some calculations
    }
    
    // will perform 1000 times
    for ( int k = 0; k > 100; k++ ) {
        for ( int i = 0; i < 10; i++ ) {
            // some calculations
        }
    }
    
    return 0;
}

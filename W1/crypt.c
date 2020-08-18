#include <stdio.h>

int main() {
    double keyA, keyB;
    int plain1, encrypted1, plain2, encrypted2, sequence;
    int length, result;
    
    scanf("%d%d", &plain1, &encrypted1);
    scanf("%d%d", &plain2, &encrypted2);
    
    keyA = (encrypted1 - encrypted2) / (plain1 - plain2);
    keyB = (plain1 * encrypted2 - encrypted1 * plain2) / (plain1 - plain2);
    
    scanf("%d", &length);
    
    for ( int i = 0; i < length; i++ ) {
        scanf("%d", &sequence);
        result = (sequence - keyB) / keyA;
        if ( i < length - 1 ) {
            printf("%d ", result);
        } else {
            printf("%d\n", result);
        }
    }
    
    return 0;
}

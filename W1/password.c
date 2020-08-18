#include <stdio.h>

int main() {
    int password;
    int attemp = 0;
    int pass = 1488;
    
    for ( int i = 0; i < 5; i++ ) {
        scanf("%d", &password);
        
        if ( password == pass ) {
            printf("accepted\n");
            return 0;
        } else {
            printf("incorrect password\n");
            attemp += 1;
        }
        if ( attemp == 5 ) {
            printf("denied\n");
        }
    }
    
    // do {
    //     scanf("%d", &password);
        
    //     if ( password == pass ) {
    //         printf("accepted\n");
    //         return 0;
    //     } else {
    //         printf("incorrect password\n");
    //         attemp += 1;
    //     } if ( attemp == 5 ) {
    //         printf("denied\n");
    //         return 0;
    //     }
    // } while ( attemp > 0 );
    
    return 0;
}

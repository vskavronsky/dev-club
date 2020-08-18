#include <stdio.h>

int strEqual(char str1[], char str2[]) {
    for ( int item = 0; str1[item] == str2[item]; item++ ) {
        if ( str1[item] == '\0' ) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char str1[] = "hello";
    char str2[] = "hello";
    
    printf("%d\n", strEqual(str1, str2));
    
    return 0;
}

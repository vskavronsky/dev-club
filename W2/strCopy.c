#include <stdio.h>

void strCopy(char target[], char source[]) {
    int item = 0;
    
    for ( ; source[item] != '\0'; item++ ) {
        target[item] = source[item];
    }
    target[item] = '\0';
}

int main() {
    char str1[11] = "ABCDEFGHIJ";
    char str2[12];
    
    strCopy(str2, str1);
    printf("%s\n", str1);
    printf("%s\n", str2);
    
    return 0;
}

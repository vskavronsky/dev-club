#include <stdio.h>

#define SIZE 100

int strEqual(char str1[], char str2[]) {
    for ( int item = 0; str1[item] == str2[item]; item++ ) {
        if ( str1[item] == '\0' ) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *in = fopen("strEqualIn.txt", "r");
    FILE *out = fopen("strEqualOut.txt", "w");
    char str1[SIZE];
    char str2[SIZE];
    
    fscanf(in, "%100s %100s", str1, str2);
    
    if ( strEqual(str1, str2) ) {
        fprintf(out, "yes\n");
    } else {
        fprintf(out, "no\n");
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}

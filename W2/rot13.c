#include <stdio.h>

void strRot13(char str[]) {
    int key = 13;
    
    for ( char *symbol = str; *symbol != '\0'; symbol++ ) {
        if ( *symbol >= 'a' && *symbol <= 'z' ) {
            if ( *symbol <= 'm' ) {
                *symbol += key;
            } else {
                *symbol -= key;
            }
        }
        if ( *symbol >= 'A' && *symbol <= 'Z' ) {
            if ( *symbol <= 'M' ) {
                *symbol += key;
            } else {
                *symbol -= key;
            }
        }
    }
}

int main() {
    FILE *in = fopen("rot13In.txt", "r");
    FILE *out = fopen("rot13Out.txt", "w");
    int size = 100;
    char str[size];
    
    fscanf(in, "%100s", str);
    
    strRot13(str);
    
    fprintf(out, "%s\n", str);
    
    fclose(in);
    fclose(out);
    
    return 0;
}

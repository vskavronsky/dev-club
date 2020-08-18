#include <stdio.h>

int main() {
    char letter;
    FILE *in = fopen("lowerCaseIn.txt", "r");
    FILE *out = fopen("lowerCaseOut.txt", "w");
    
    for ( ; fscanf(in, "%c", &letter) == 1; ) {
        if ( letter > 64 && letter < 91 ) {
            letter += 32;
        }
        fprintf(out, "%c", letter);
    }
    fprintf(out, "\n");
    
    fclose(in);
    fclose(out);
    
    return 0;
}

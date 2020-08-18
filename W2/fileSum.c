#include <stdio.h>

int main() {
    int first, second;
    FILE *in = fopen("sumIn.txt", "r");
    FILE *out = fopen("sumOut.txt", "w");
    
    fscanf(in, "%d %d", &first, &second);
    fprintf(out, "%d\n", first+second);
    
    fclose(in);
    fclose(out);
    
    return 0;
}

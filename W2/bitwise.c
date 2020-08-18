#include <stdio.h>

int main() {
    int number1, number2;
    FILE *in = fopen("bitWiseIn.txt", "r");
    FILE *out = fopen("bitWiseOut.txt", "w");
    
    fscanf(in, "%d %d", &number1, &number2);
    
    fprintf(out, "%d&%d=%d\n", number1, number2, number1&number2);
    fprintf(out, "%d|%d=%d\n", number1, number2, number1|number2);
    fprintf(out, "%d^%d=%d\n", number1, number2, number1^number2);
    fprintf(out, "%d<<%d=%d\n", number1, number2, number1<<number2);
    fprintf(out, "%d>>%d=%d\n", number1, number2, number1>>number2);
    
    fclose(in);
    fclose(out);
    
    return 0;
}

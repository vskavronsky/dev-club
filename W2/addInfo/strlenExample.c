#include <stdio.h>

// void saveToFile(FILE *ptr, char str[], int size) {
//     int counter = 0;
    
//     for ( int i = 0; str[i] != '\0'; i++ ) {
//         fscanf(ptr, "%c", str[i]);
//         counter += 1;
//     }
//     fprintf(ptr, "%d\n", counter);
// }

int strLen(char str[]) {
    int length = 0;
    
    for ( ; str[length] != '\0'; length++ );
    return length;
}

int main() {
    // int size = 100;
    // char str[size];
    
    char str1[10] = "ABCDEFGHIJ";
    printf("%d\n", strLen(str1));
    
    // FILE *in = fopen("task.in", "r");
    // FILE *out = fopen("task.out", "w");
    
    // fscanf(in, "%s", str);
    // fprintf(out, "%s\n", str);
    
    return 0;
}

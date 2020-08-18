// void print( char array[], int size ) {
//     int limit = size - 1;
    
//     printf("[");
//     for ( int i = 0; i < limit; i++ ) {
//         printf("%c, ", array[i]);
//     }
//     if ( size > 0 ) {
//         printf("%c]\n", array[limit]);
//     } else {
//         printf("]\n");    
//     }
    
// }

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
    
    // int size = 26;
    // char str[size];
    
    printf("%s\n", str2);
    
    return 0;
}

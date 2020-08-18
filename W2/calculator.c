#include <stdio.h>

#define MAXLEN 1000

int isDigits ( char *ch ) {
    if ( ch == '9' || 
         ch == '8' ||
         ch == '7' ||
         ch == '6' ||
         ch == '5' ||
         ch == '4' ||
         ch == '3' ||
         ch == '2' ||
         ch == '1' ||
         ch == '0' ) {
        return 1;
    }
    else {
        return -1;
    } 
}

int doOperation ( int x, int y, char operation ) {
    if ( operation == '+' ) {
        return x + y;
    }
    else if ( operation == '-' ) {
        return x - y;
    }
    else if ( operation == '*' ) {
        return x * y;
    }
    else if ( operation == '/' ) {
        return x / y;
    }
    else {
        return -1;
    }
}

int main() {
    char str[MAXLEN];
    char buffer;
    int i = 0;
    double sum = 0;
    int start = 0;
    int finish = 0;
    
    FILE *in = fopen("task.in", "r");
    if ( in == NULL ) {
        return -1;
    }
    
    
    if ( fgets( str, MAXLEN, in ) != NULL ) {
        i = 0;
        buffer = str[i];
        if ( isDigits( buffer ) == -1 ) {
            return -1;
        }

        while ( buffer != '\0' ) {
            start = i;
            while ( isDigits( buffer ) != -1 ) { 
                finish = i;
                i++;
                buffer = str[i];
                printf("buffer=%d\n", i);
            } 
            printf("start=%d\nfinish=%d\n", start, finish); 
        }
        
       
    }
    fclose(in);
    

   // fprintf(out, "%g\n", sum);
    
    
    
    //FILE *out = fopen("task.out", "w");
    //fclose(out);
    
    return 0;
}

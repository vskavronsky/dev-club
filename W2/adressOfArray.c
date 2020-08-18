#include <stdio.h>

int main() {
    int array2[] = {98, -2, 645, 34, 6, 13, 2146, 33, 9, 0};
    
    printf("%p - adress of array2\n", &array2); /*0060FEC8 - adress of array2*/
    printf("%p - adress in array2\n", array2);  /*0060FEC8 - adress in array2*/
    
    printf("%p - adress of %d\n", &(*(array2+0)), *(array2+0));  /*0060FEC8 - adress of 98*/
    printf("%p - adress of %d\n", &(*(array2+1)), *(array2+1));  /*0060FECC - adress of -2*/
    printf("%p - adress of %d\n", &(*(array2+2)), *(array2+2));  /*0060FED0 - adress of 645*/
    printf("%p - adress of %d\n", &(*(array2+3)), *(array2+3));  /*0060FED4 - adress of 34*/
    printf("%p - adress of %d\n", &(*(array2+4)), *(array2+4));  /*0060FED8 - adress of 6*/
    printf("%p - adress of %d\n", &(*(array2+5)), *(array2+5));  /*0060FEDC - adress of 13*/
    printf("%p - adress of %d\n", &(*(array2+6)), *(array2+6));  /*0060FEE0 - adress of 2146*/
    printf("%p - adress of %d\n", &(*(array2+7)), *(array2+7));  /*0060FEE4 - adress of 33*/
    printf("%p - adress of %d\n", &(*(array2+8)), *(array2+8));  /*0060FEE8 - adress of 9*/
    printf("%p - adress of %d\n", &(*(array2+9)), *(array2+9));  /*0060FEEC - adress of 0*/
    
    return 0;
}

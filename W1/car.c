#include <stdio.h>

int main() {
    int carSpeed, speedLimit;
    
    scanf("%d %d", &carSpeed, &speedLimit);
    
    if ( carSpeed > speedLimit ) {
        printf("violation\n");
    } else {
        printf("ok\n");
    }
    
    return 0;
}

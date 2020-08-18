#include <stdio.h>

#define MAX_PRICE 1001

int main() {
    int farmerQuantity;
    int farmersHave = 0;
    unsigned long long amoundNeeded;
    unsigned long long minPrice = 0;
    FILE *in = fopen("milkIn.txt", "r");
    FILE *out = fopen("milkOut.txt", "w");
    int milkPrices[MAX_PRICE];
    
    fscanf(in, "%d %llu", &farmerQuantity, &amoundNeeded);
    
    for ( int i = 0; i < MAX_PRICE; i++ ) {
        milkPrices[i] = 0;
    }
    for ( int i = 0; i < farmerQuantity; i++ ) {
        int index;
        int amount;
        
        fscanf(in, "%d %d", &amount, &index);
        milkPrices[index] += amount;
        farmersHave += amount; 
    }
    if ( farmersHave >= amoundNeeded ) {
        for ( int i = 0; i < MAX_PRICE; i++ ) {
            if ( milkPrices[i] != 0 ) {
                if ( amoundNeeded > milkPrices[i] ) {
                    amoundNeeded -= milkPrices[i];
                    minPrice += milkPrices[i] * i;
                } else {
                    minPrice += amoundNeeded * i;
                    amoundNeeded = 0;
                }
            }
        }
    }
    fprintf(out, "%llu\n", minPrice);
    
    fclose(in);
    fclose(out);
    
    return 0;
}

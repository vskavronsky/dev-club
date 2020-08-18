#include <stdio.h>

int main() {
    int homeTeam, awayTeam;
    
    scanf("%d %d", &homeTeam, &awayTeam);
    
    if ( homeTeam > awayTeam ) {
        printf("Home team wins\n");
    } else if ( homeTeam < awayTeam ) {
        printf("Away team wins\n");
    } else {
        printf("Draw\n");
    }
    
    return 0;
}

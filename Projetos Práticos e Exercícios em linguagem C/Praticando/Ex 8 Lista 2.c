#include <stdio.h>
#include <stdlib.h>

int main(){

    int aresta1, aresta2, aresta3;
    int area1, area2, area3;

    printf( "Digite a medida da aresta do primeiro quadrado: " );
    scanf( "%d", &aresta1 );

    printf( "Digite a medida da aresta do segundo quadrado: " );
    scanf( "%d", &aresta2 );

    printf( "Digite a medida da aresta do terceiro quadrado: " );
    scanf( "%d", &aresta3 );

    area1 = aresta1 * aresta1;
    area2 = aresta2 * aresta2;
    area3 = aresta3 * aresta3;

    printf( "Area do primeiro: %d\n", area1 );

    printf( "Area do segundo: %d\n", area2 );

    printf( "Area do terceiro: %d\n", area3 );

    if ( area1 < area2 && area1 < area3 ){

        printf( "O primeiro quadrado tem a menor area.\n");

    } else if ( area2 < area1 && area2 < area3 ){

        printf( "O segundo quadrado tem a menor area.\n" );

    } else if ( area3 < area1 && area3 < area2 ){

        printf( "O terceiro quadrado tem a menor area.\n" );

    }


    return 0;

}

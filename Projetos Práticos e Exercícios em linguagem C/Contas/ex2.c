#include <stdio.h>
#include <stdlib.h>

int main () {

    float deposito;
    float rendimento;

    printf( "Deposito: R$" );
    scanf( "%f", &deposito );

    for( int i = 1; i <= 78; i++) {
        deposito = deposito * 1.05;
    }
    printf( "Rendimento foi de R$%.2f", deposito );

    return 0;

}

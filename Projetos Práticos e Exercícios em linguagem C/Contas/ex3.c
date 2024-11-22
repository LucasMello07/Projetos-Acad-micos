#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {


    int nprodutos;
    char nome[100];
    int qtd;
    float valor;
    float valorf = 0;
    float valorpago;
    float troco;

    printf( "Numero de produtos: " );
    scanf( "%d", &nprodutos );

    for(int i = 1; i <= nprodutos; i++){
        printf( "Nome do produto: " );
        scanf( "%s", &nome );
        printf( "Valor do produto: " );
        scanf( "%f", &valor );
        printf( "Quantidade do produto: " );
        scanf( "%d", &qtd );

        valorf = valorf + (valor * qtd);

    }
    printf( "Valor da compra: R$%.2f\n", valorf );

    printf( "Valor pago:" );
    scanf( "%f", &valorpago );

    if( valorpago < valorf ) {
        printf( "Compra cancelada" );
    } else {

    troco = valorpago - valorf;

    printf( "Troco: R$%.2f", troco );


    }

    return 0;

}

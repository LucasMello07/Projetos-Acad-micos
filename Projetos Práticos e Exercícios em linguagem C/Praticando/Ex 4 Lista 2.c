#include <stdio.h>
#include <stdlib.h>

int main(){

    int lados;
    int tamanhoLado;
    int perimetro;
    int area;

    printf( "Digite um numero de lados: " );
    scanf( "%d", &lados );

    printf( "Tamanho do lado: " );
    scanf( "%d", &tamanhoLado );

    if ( lados == 3 ){

        printf( "TRIANGULO\n" );

        perimetro = tamanhoLado + tamanhoLado + tamanhoLado;

        printf( "Perimetro: %d\n", perimetro );

    } else if ( lados == 4 ){

        printf( "QUADRADO\n" );

        area = tamanhoLado * tamanhoLado;

        printf( "Area: %d\n", area );


    } else if ( lados == 5 ){

        printf( "PENTAGONO" );

    } else {

        printf( "Poligono nao identificado.\n" );

    }



    return 0;

}

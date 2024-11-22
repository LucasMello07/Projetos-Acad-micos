#include <stdio.h>
#include <stdlib.h>

int main(){

    float peso;
    float altura;
    float imc;

    printf( "Digite seu peso em Kg: " );
    scanf ( "%f", &peso );

    printf( "Digite sua altura em m: " );
    scanf( "%f", &altura );

    imc = peso / ( altura * altura );

    printf( "IMC = %f\n", imc );

    if( imc < 18.5 ){

        printf( "Voce esta abaixo do peso ideal." );

    } else if( imc >= 18.5 && imc <= 24.9){

        printf( "Parabens!Voce esta em seu peso normal!" );

    } else if( imc >= 24.9 && imc >= 29.9 ){

        printf( "Voce esta acima de seu peso(sobrepeso)." );

    } else if ( imc >= 29.9 && imc <= 34.9 ){

        printf( "Obesidade grau I" );

    } else if ( imc >= 34.9 && imc <= 39.9 ){

        printf( "Obesidade grau II" );

    } else if ( imc > 39.9 ){

        printf( "Obesidade grau III" );

    }

    return 0;

}

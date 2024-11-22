#include <stdio.h>
#include <stdlib.h>

int main () {

    int elemento;
    int quad;

    printf( "Elemento: " );
    scanf( "%d", &elemento );

    quad = 2 * elemento - 1;



    printf( "O numero de quadrados no elemento %d e igual a %d", elemento, quad );


    return 0;

}

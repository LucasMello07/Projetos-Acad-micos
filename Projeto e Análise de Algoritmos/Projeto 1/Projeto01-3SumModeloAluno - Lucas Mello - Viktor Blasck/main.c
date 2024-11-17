#include <stdio.h>
#include <stdlib.h>
#include "threesum.h"

/* Vari�veis Globais */
int *A;

int main() {

  int n;

  printf("\n ---Projeto 01 - 3SUM--- \n");

  printf("\n  Definir o tamanho do Array: ");
  scanf("%d", &n);

  int conjunto[n];
  A = (int *)malloc(n * sizeof(int));

  // Perguntar ao usu�rio os valores do array;
  for (int i = 0; i < n; i++) {
    printf(" Entre com o %d elemento do Array: ", i + 1);
    scanf("%d", &A[i]);
  }


  printf("\n\n -----3SUM -- Forca Bruta: ---\n\n");
  ImprimeArray(A, "Array Infor.   []", n);
  treeSumForcaBruta(A, n);

  printf("\n");

  printf("\n\n -----3SUM -- Melhorado: ---\n\n");

  treeSumMelhorado(A, n);

  ImprimeQtdOperacoes();

  return 0;
}

#include "threesum.h"
#include <stdio.h>
#include <stdlib.h>

int qtdOperacoes3SumFB = 0;
int qtdOperacoes3SumMelhorado = 0;

/* treeSumForcaBruta(): */
void treeSumForcaBruta(int A[], int n) {

  int contador = 0;

  // Calculo para achar as triplas Forca Bruta;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        qtdOperacoes3SumFB++;
        if (A[i] + A[j] + A[k] == 0) {
          printf("\n( %d Tripla Encontrada: %d, %d, %d)",contador+1, A[i], A[j], A[k]);
          contador++;
        }
      }
    }
  }

  printf("\nTotal de Triplas encontradas pela Forca Bruta: %d\n", contador);
}


/* treeSumMelhorado(): */
void treeSumMelhorado(int A[], int n) {

  int contador = 0;

  for(int i = 0; i < n ; i++) {
    qtdOperacoes3SumMelhorado++;
    for (int j = (i + 1); j < n - 1; j++) {
      qtdOperacoes3SumMelhorado++;
      int k = 0 - (A[i]) - (A[j]);
      int posicao = BuscaBinaria(k, A, (j+1), (n-1));
        if(posicao != -1){
          printf("\n( %d Tripla Encontrada: %d %d %d)", contador, A[i], A[j], k);
        }
   }
  }
}

/* BuscaBinaria(): */
int BuscaBinaria(int x, int A[], int inicio, int fim) {

  int meio = (inicio + fim) / 2;
    if (inicio > fim) {
      return -1;
    }
    else if (A[meio] == x){
      return meio;
    } else {
      qtdOperacoes3SumMelhorado++;
      if (x > A[meio]){
        return BuscaBinaria(x, A, (meio + 1), fim);
      } else {
        return BuscaBinaria(x, A, inicio, (meio - 1));
      }
    }

}


/* MergeSortRecursivo(): */
void MergeSortRecursivo(int A[], int inicio, int fim, int n) {
    int meio;

    if(inicio < fim){
      meio = (inicio + fim) / 2;
      MergeSortRecursivo(A, inicio, meio, n);
      MergeSortRecursivo(A, meio+1, fim, n);
      IntercalaSemSentinela(A, inicio, meio, fim, n);
    }
}


/* IntercalaSemSentinela(): */
void IntercalaSemSentinela(int A[], int inicio, int meio, int fim, int n) {

  int i, j;
  int *arrayB;

  arrayB = (int *)malloc(n * sizeof(int));

  for (i = inicio; i <= meio; i++) {
    arrayB[i] = A[i];
  }

  for (j = meio + 1; j <= fim; j++) {
    arrayB[fim + meio + 1 - j] = A[j];
  }

  i = inicio;
  j = fim;

  for (int k = inicio; k <= fim; k++) {
    if (arrayB[i] <= arrayB[j]) {
      A[k] = arrayB[i];
      i++;
    } else {
      A[k] = arrayB[j];
      j--;
    }
  }

  free(arrayB);
}


/* ImprimeArray(): */
void ImprimeArray(int A[], char Msg[], int n) {

  printf("\n %s: ", Msg);

  for(int i=0; i<n; i++){
    printf(" %d" , A[i]);
  }
}


/* ImprimeQtdOperacoes():  */
void ImprimeQtdOperacoes() {

    printf("\nQuantidade de Operacoes - 3SUM - Forca Bruta: %d\n", qtdOperacoes3SumFB);
    printf("Quantidade de Operacoes - 3SUM - Melhorado: %d\n", qtdOperacoes3SumMelhorado);

}

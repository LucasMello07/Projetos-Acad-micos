#include <stdio.h>

int main() {
  int meio, n1, n2;

  printf("Valor entrada: ");
  scanf("%d",&meio);

  printf("Limite Inferior: ");
  scanf("%d",&n1);

  printf("Limite Superior: ");
  scanf("%d", &n2);

  if (meio >= n1 && meio <= n2){
    printf("O valor de entrada est� nos limites do intervalo lido ");
  } else {
    printf("N�o est� no intervalo.");
  }
  return 0;
}

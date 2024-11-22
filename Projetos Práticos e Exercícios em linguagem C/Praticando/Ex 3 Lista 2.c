#include <stdio.h>

int main() {
  float n1,n2,n3,media;

  scanf("%f",&n1);
  scanf("%f",&n2);
  scanf("%f",&n3);

  media = ((n1 + n2) + n3) / 3;

  if (media >= 6){
    printf("Aprovado.");
  }   else if (media < 4){
        printf("Reprovado.");
      } else if (media >=4 && media < 6){
          printf("Exame.");
        }
  return 0;
}

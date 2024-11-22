#include <stdio.h>

int main() {
  float n1;
  scanf("%f",&n1);

  if (n1 >= 20){
    printf("Sua metade é %.2f", n1/2);
  } else printf("Seu triplo é %.2f",n1*3);

  return 0;
}

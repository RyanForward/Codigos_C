#include <stdio.h>

int main(void) {
  //Declaração de variáveis
  int n1, n2;
  int num, c;

  //Entrada de dados
  printf("\n Digite o primeiro número: ");
  scanf("%d", &n1);
  printf(" Digite o segundo número: ");
  scanf("%d", &n2);

  num = n1;
  printf("\n");
  for(num = n1; num <=n2; num++){
    for (c = 0; c<=10; c++){
      printf("%d x %d = %d\n", num, c, num*c);
    }
    printf("\n");
  }
  return 0;
}
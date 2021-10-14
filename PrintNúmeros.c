#include <stdio.h>
#include <stdlib.h>

int main(void) {
  //Declaração de variáveis
  int x;

  //Estrutura de repetição While
  x = 0;
  printf("\n-----------------------Parte A----------------------\n");
  while(x<=20){
    printf("%d ", x);
    x++;
  }

  //Estrutura Faça Enquanto
  x = 20;
  printf("\n\n-----------------------Parte B----------------------\n");
  do{
    printf("%d ", x);
    x--;
  }while(x>0);

  //Estrutura Para
  printf("\n\n-----------------------Parte C----------------------\n");
  for (x = 1; x<=20; x++){
    if (x%2 == 1){
      printf(" %d   ", x);
    }
  }
  return 0;
}
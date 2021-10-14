#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  //Variáveis
  int i, j; 
  float M[4][7] = {0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0}, linha_menor;


  //Criação da matriz
  srand(time(NULL)); //seed

  float menor = 101;
  printf("\n");
  printf("==========MATRIZ===========");
  for(i=0; i<4; i++){
    printf("\n");
    printf("---------------------------\n");
    for(j=0; j<7; j++){
      M[i][j] = rand() % 100; //randomiza os números
      //Encontra o menor elemento da matriz
      if((M[i][j])<menor){
        menor = (M[i][j]);
        linha_menor = i;
      }
      printf("%.0f\t", M[i][j]);
    }
  }
  printf("\n---------------------------");
  //Busca o maior elemento da linha
  float minmax = -1;
  i = linha_menor;
  for(j=0; j<7; j++){
    if(M[i][j]>minmax){
      minmax = M[i][j];
    }
  }
  printf("\n\nO menor elemento está na linha %.0f e é: %.0f", linha_menor+1, menor);
  printf("\nJá o MINMAX da matriz é o número %.0f", minmax);

  return 0;
}
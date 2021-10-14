#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  //variaveis
  int num[20], i, j, freq[6];

  //sorteio dos numeros
  srand( (unsigned)time(NULL) );

  printf("=========================SORTEIO==========================\n");
  for(i=0; i<20; i++){
    num[i] = 1 + rand() % 6;
    printf("%d, ", num[i]);
  }

  //checa se tem iguais  
  for(j=0; j<6; j++){
    for(i=0; i<20; i++){
      if((j+1)==(num[i])){
        freq[j]+=1;
      }
    }
  }
  printf("\n==========================================================");
  printf("\n\n");
  printf("--------FREQUÊNCIA------------\n");
  for(j=0; j<6; j++){
    printf("| O número %d aparece %d vezes |\n", j+1, freq[j]);
  }
  printf("------------------------------\n");
  return 0;
}
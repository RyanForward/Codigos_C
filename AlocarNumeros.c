#include <stdio.h>

int main(void) {

  int vetor[8] = {0,0,0,0,0,0,0,0}, i, j, aux;

  // preencher o vetor
  for(i=0; i<8; i++)
  {
    printf("\n Digite o número da posição %d: ", i+1);
    scanf("%d", &vetor[i]);

    // verificar se o vetor continua ordenado em ordem crescente
    for(j=0; j<i; j++){

      // troca números se o elemento da posição i for menor que o elemento da posição j
      if(vetor[i] < vetor[j])
      {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;        
      }
    }  

    // imprime o vetor
    for(j=0; j<8; j++)
    {
      printf("%d | ", vetor[j]);
    }  
  }

  return 0;
}
        
#include <stdio.h>

int main(void) {
//Declaração
int M[2][2], R[2][2];
int i, j, maior=-10000000;

//Preenche a matriz
printf("=========================================\n");
for(i=0; i<2; i++){
  for(j=0; j<2; j++){
    printf(" Digite um valor para a posição X[%d][%d]: ", i, j);
    scanf("%d", &M[i][j]);

    //Maior?
    if (maior<M[i][j]){
      maior = M[i][j];
    }
  }
}
printf("\n=========================================\n");
//Multiplica os valores pelo maior
for(i=0; i<2; i++){
  for(j=0; j<2; j++){
    R[i][j] = M[i][j]*maior;
  }
}
printf("Maior = %d", maior);
printf("\n");
printf("-----------------------------------------\n");
for(i=0; i<2; i++){
  for(j=0; j<2; j++){
    printf("[%d][%d] * %d = %d\n", i, j, maior, R[i][j]);
  }
}
printf("-----------------------------------------");
  return 0;
}
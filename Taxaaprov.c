#include <stdio.h>
#include <stdlib.h>

int main(void) {
  //declaração
 char gab[8], resp[8];
 int i, j, num[10];
 float notas[10], taxaapro=0;


  //GABARITO
  for(i=0; i<8; i++){
    printf(" Digite a resposta da questão %d: ", i+1);
    scanf(" %c", &gab[i]);
  }

  //NUMERO
  for(j=0; j<10; j++){
    printf("---------------------------------------\n");
    printf(" Digite o número do aluno %d: ", j+1);
    scanf(" %d", &num[j]);

    //NOTA
    printf("-------------------------------------\n");
    notas[j] = 0;
    for(i=0; i<8; i++){
      printf(" Digite a questão %d do aluno: ", i+1);
      scanf(" %c", &resp[i]);
      if((gab[i]) == (resp[i])){
        notas[j]+=1.25;
        }
      }
    }

  //SAIDA
  float aprov=0;
  printf("\n\n\n===========================================\n");
  for(j=0; j<10; j++){
    if ((notas[j])>=6){
      printf("| Número: %d - nota %.1f - Aprovado!   \n", num[j], notas[j]);
      aprov+=1;
    } 
    else{ 
      printf("| Número: %d - nota %.1f - Reprovado!  \n", num[j], notas[j]);
    }
  }
  taxaapro = aprov/10;
  printf("============================================\n");
  printf(" %.0f alunos foram aprovados, sendo o total de aprovação de %.0f por cento ", aprov, taxaapro*100);


  return 0;
}
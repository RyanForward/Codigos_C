#include <stdio.h>
#include <stdlib.h>

int main(void) {
  //Declaração de variáveis
  double nota1, nota2, nota3, nota4, media;

  //Entrada de dados
  printf(" Digite a primeira nota: ");
  scanf("%lf", &nota1);
  printf(" Digite a segunda nota: ");
  scanf("%lf", &nota2);
  printf(" Ditite a terceira nota: ");
  scanf("%lf", &nota3);
  printf(" Digite a quarta nota: ");
  scanf("%lf", &nota4);
  printf(" --------------------------------------------------\n");

  //Cálculo da média 
  media = (nota1 + nota2 + nota3 + nota4)/4;
  if (media<6 == 0){
    printf(" Parabéns, você foi aprovado! Sua média final foi de %.2f", media);
  }
  else{
    printf(" Infelizmente você foi reprovado... Sua média final foi de %.2f", media);
  }

  return 0;
}
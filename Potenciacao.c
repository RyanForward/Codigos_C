#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//obs: professora, utilizei a biblioteca math.h para a realização da potência

int main(void) {
   
    //Declaração de variáveis
    double x, res;
    int pot = 0;

    //Entrada de dados
    printf(" Digite o número que irá ser potencializado: ");
    scanf("%lf", &x);

    //Cálculo e saída da parte A
    printf("-------------------------------------");
    printf("\nPotencialização de %.0lf, de 0 a 10: \n", x);
   
    
    while (pot<=10){
      res = pow(x, pot);
      printf("%.0lf ^ %d = %.0lf \n", x, pot, res);
      pot++;
    }

    //Cálculo e saída da parte B
    
    printf("-------------------------------------\n");
    printf("Base 10, elevada de a %.2lf: \n", x);
    res = 0;
    pot = 0;
    
    //Esse bloco calcula a potência e printa na tela o resultado em forma de lista
    x++;
    while (pot!=x){
      res = pow(10, pot);
      printf("10 ^ %d = %.0lf\n", pot, res);
      pot++;
    }
    //Fim do programa
  return 0;
}
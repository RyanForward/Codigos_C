#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  //Declaração de variáveis
  double sal;

  //Entrada de dados
  printf(" Digite o salário para cálculo do reajuste: ");
  scanf("%lf", &sal);

  //Classificação e cálculo do novo salário
  if (sal<=1000){
    sal = sal*1.15;
  }
  else if(sal>=2000)
  {
    sal = sal*1.05;
  }
  else
  {
    sal = sal*1.1;
  }

  //Saída de dados
  printf("------------------------------------\n");
  printf(" O novo salário será de R$ %.2lf ", sal);
  return 0;
}
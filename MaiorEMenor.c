#include <stdio.h>
#include <stdlib.h>
    
int main(void) {
    
    float num1, num2, num3, maior, menor;
    
    //Entrada de dados
    printf(" Digite o valor do primeiro número: \n");
    scanf("%f", &num1);
    printf(" Digite o valor do segundo número: \n");
    scanf("%f", &num2);
    printf(" Digite o valor do terceiro número: \n");
    scanf("%f", &num3);

    //Cálculo da Saída
    maior = num1;
    menor = num1;

    if (num2>maior){
    maior = num2;
    }
    if (num3>maior){
    maior = num3;
    }
    if (num2<menor){
    menor = num2;
    }
    if (num3<menor){
    menor = num3;
    }
    
    //Saída de dados
    
    printf(" O maior número é %.2lf, e o menor %.2lf ", maior, menor);
    return 0;
}
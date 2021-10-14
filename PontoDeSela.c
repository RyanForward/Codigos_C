#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//A matriz está setada para ter como ponto de sela o número 60, para testar isso, só por como comentário as linhas 21 e 30
//Já para testar que o random está funcionando, só tirar o comentário na linha 22 e na 79(vai rodar infinito, ai só parar e procurar as matrizes com ponto de sela)

int main(void) {
 
  //Variáveis
int M[5][7] = 
{0, 10, 20, 10, 30, 40, 50,
 80, 70, 65, 60, 90, 95, 99,
 0, 0, 0, 40, 0, 0, 0,
 0, 0, 0, 30, 0, 0, 0,
 0, 0, 0, 20, 0, 0, 0}, sela, i_sela, j_sela;
int i , j, k, menor[5], maior[5], col_do_menor[5], flag = 0, aga=2;


//Preenche a matriz aleatoriamente entre 0 e 100 e printa na tela
srand(time(NULL));                        //seed para randomizar 
//while(aga!=1){ //para testar as chances de ter sela 
printf("\n");
printf("Definição de ponto de sela: elemento que é, simultâneamente,\no menor de sua linha, e o maior de sua coluna. \n");
printf("\n");
printf("=======MATRIZ[5][7]=======\n");                
printf("\n");                                          
for(i=0; i<5; i++){
  for(j=0; j<7; j++){
   M[i][j] = rand() % 100;
    printf("%d\t", M[i][j]);
  }
printf("\n");
}
printf("\n==========================");                

//Menor da linha e a coluna em que se encontra
for(i=0; i<5; i++){
  for(j=0; j<7; j++){
    //Inicia a comparação dos elementos na linha
    if(j==0){
      menor[i] = M[i][j];
      col_do_menor[i] = j;
    }
    else{
      //Confirma o menor elemento da linha e substitui se for preciso
      if((M[i][j]) < menor[i]){
        menor[i] = M[i][j];
        col_do_menor[i] = j;   //Pega a coluna do menor elemento 
      }
    }
  }
}
//Maior da coluna de cada um dos menores das linhas
for(i=0; i<5; i++){
  j=col_do_menor[i];         //Deixa fixada a coluna do menor elemento 
  for(k=0; k<5; k++){
    if(k==0){
      maior[j] = M[k][j];
    }
    if((M[k][j])>maior[j]){
      maior[j] = M[k][j];
    }
  }
  //Confere se o elemento sustenta ambas as condições para ser sela
  if((menor[i])==(maior[j])){  
    sela = menor[i];
    i_sela = i;  //Pega a linha
    j_sela = j;  //Pega a coluna
    printf("\nA sela é o número %d, que está localizado da posição M[%d][%d]! ", sela, i_sela+1, j_sela+1);
  }
  else{
    flag+=1; //Se um elemento não for a sela, 1 unidade é adicionada na variável
  }
}
if(flag==5){   //Como são 5 candidatos a ponto de sela, se nenhum for, não há ps
  printf(" \nNão existe nenhum ponto de sela nesta matriz");
}
//} 
return 0;
}

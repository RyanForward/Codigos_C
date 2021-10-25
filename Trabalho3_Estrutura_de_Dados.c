#include <stdio.h>
#include <stdlib.h>

//SUGESTAO DE ESTRUTURA PARA GUARDAR UM BLOCO
//PODE MUDAR SE QUISER
typedef struct bloco{
  int id;
  int altura;
  struct bloco* prox;
} bloco;

typedef struct bloco * p_Bloco;


//SUGESTAO DE ESTRUTURA PARA GUARDAR UM MACACO
//PODE MUDAR SE QUISER
typedef struct Macaco{
  int altura;
  struct bloco* lista_blocos;
} Macaco;

typedef struct Macaco * p_Macaco;


//SUGESTAO DE FUNCOES PARA IMPRESSAO
//PODE MUDAR SE QUISER
//Hokama, alterei a ordem dos comandos na linha 30 e 31 para que imprimisse na ordem certa (já que optei por adicionar os novos blocos no fim da lista)
void imprime_blocos(p_Bloco lista){
  if(lista == NULL) return;
  imprime_blocos(lista->prox);
  printf(" %d %d", lista->id, lista->altura);

}

void imprime_macacos(p_Macaco M, int num_macacos){
  for(int i = 0; i < num_macacos; i++){
    printf("M[%d] altura = %d:", i, M[i].altura);
    imprime_blocos(M[i].lista_blocos);
    printf("\n");
  }
}

p_Macaco inicializa_macacos(int num_mac){
    p_Macaco M; //variável do tipo ponteiro para macaco
    M = malloc(num_mac * sizeof(Macaco)); //Inicializa um vetor de 'Macacos', do tamanho da struct macaco

    for(int i=0; i<num_mac; i++){ //Laço para zerar as duas variáveis que estão dentro da struct
      M[i].altura = 0; //Zera a altura
      M[i].lista_blocos = NULL; //Faz o ponteiro apontar para NULL
    }
    return M; //Retorna o vetor de macacos
}

void libera_bloco(p_Bloco No){ //Desaloca os nós que estão dentro da lista
  if(No == NULL)return; //Quando o nó for NULL, ele sai da recursividade
  libera_bloco(No->prox); //acessa o próximo nó da lista
  free(No); //Libera o nó
}

void libera_macacos(p_Macaco M, int num_macacos){ //Desaloca o vetor de macacos
  for(int i=0; i<num_macacos; i++){
    libera_bloco(M[i].lista_blocos); //Chamada da função libera_bloco
  }
  free(M); //Quando a função libera bloco já liberou toda a lista de todos os macacos, esse free libera o vetor de macacos
}

p_Bloco adiciona_bloco(p_Bloco lista, int id_bloco, int altura_bloco){

    p_Bloco novo = (p_Bloco) malloc(sizeof(bloco)); //Aloca espaço para um novo nó

    novo->altura = altura_bloco; //Bloco recebe a altura digitada na entrada
    novo->id = id_bloco; //Bloco recebe o id digitado na entrada
    novo->prox = lista; //Ponteiro dentro da struct bloco aponta para a lista novamente

  return novo;
}

p_Macaco bota_no_menor(p_Macaco M, int num_macacos, int id_bloco, int altura_bloco){

    int i=0, pos_menor = 0;

    for(i=0; i<num_macacos; i++){
        if(M[i].altura < M[pos_menor].altura){ //Compara os valores de altura para encontrar o menor
                pos_menor = i; //guarda a posição do menor
        }
    }

    M[pos_menor].altura += altura_bloco; //Adiciona a altura do bloco ao valor total da altura da pilha do macaco
    M[pos_menor].lista_blocos = adiciona_bloco(M[pos_menor].lista_blocos, id_bloco, altura_bloco); // A lista localizada na posição que o macaco ocupa no vetor é atualizada com a função adiciona

    return M; //A função retorna o vetor agora atualizado com o novo bloco

}

//******************************
//VOCE NAO PODE MODIFICAR A MAIN
//******************************
int main(int argc, char * argv[]){

  p_Macaco M;
  int num_macacos;
  int id_bloco;
  int altura_bloco;

  //le o numero de macacos
  scanf("%d", &num_macacos);

  M = inicializa_macacos(num_macacos);

  //le o primeiro bloco
  scanf("%d %d", &id_bloco, &altura_bloco);
  while(id_bloco != -1){
    bota_no_menor(M, num_macacos, id_bloco, altura_bloco);
    //le o proximo bloco
    scanf("%d %d", &id_bloco, &altura_bloco);
  }

  imprime_macacos(M, num_macacos);

  //Lembre que cada macaca tem uma lista que precisa ser liberada
  libera_macacos(M, num_macacos);
  return 0;
}

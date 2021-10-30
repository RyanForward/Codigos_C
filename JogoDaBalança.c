#include <stdio.h>
#include <stdlib.h>

typedef struct item{     //Criação de struct item
    int in_out;  
    int peso;
} item;

typedef struct item * p_item; // Ponteiro para struct item

p_item inicia_vetor(int num_itens){   // Função para alocar e iniciar um vetor

    p_item item;
    item = malloc(num_itens * sizeof(item));  //A locação dinâmica para um vetor

    for(int i=0; i<num_itens; i++){    // Inicialização dos dois campos da struct item
        item[i].peso = 0;
        item[i].in_out = 0;
    }
    return item;
}

int escolhe_oq_entra(int pesotot, p_item item, int num_itens, int atual, int index){

        if(atual == pesotot) return 1;     // Caso o valor atual seja igual ao peso total, o algoritmo atingiu o resultado
        
        if(num_itens == 0) return 0;    //Se o número de itens acabou e o programa não conseguiu chegar ao resultado, ele encerra

        if(atual>pesotot) return 0;    //Se a soma atual for maior que o peso total, ele retorna ao valor anterior do vetor

        item[index].in_out = 1;     // Caso nenhuma das situações anteriores aconteça, o item será escolhido

        int fun_prox = escolhe_oq_entra(pesotot, item, num_itens-1, atual+item[index].peso, index+1); //Recursividade: testa se o próximo item somado com o número atual do peso é igual ao peso que   

        if(fun_prox == 1){  // 
          return 1;
        }

        item[index].in_out = 0;

        int fun_volta = escolhe_oq_entra(pesotot, item, num_itens-1, atual, index+1); //Recursividade: continua tentando adicionar no próximo item do vetor

        if(fun_volta == 1){  //Retorna caso o retorno da função seja 1, o que implica em ter encontrado o resultado 
          return 1;
        }
        
    return 0;
}

void print_result(p_item B, int num_itens){   //Função para printar o resultado
    for(int i=0; i<num_itens; i++){
        printf("%d ", B[i].in_out);           // Usei o dado in_out da escruct para saber se o item está dentro ou fora da balança
    }
    printf("\n");
}

void libera_list(p_item B, int num_itens){    //Libera o vetor
  free(B);
}

int main(int argc, char * argv[]){

    int pesotot = 0, num_itens = 0, atual = 0;

    scanf("%d", &pesotot);   //Entrada do peso total
    scanf("%d", &num_itens); //Entrada do número de itens

    p_item B = inicia_vetor(num_itens);  //Alocação do vetor de itens

    for(int i = 0; i<num_itens; i++){
        scanf("%d", &B[i].peso);       //Preenchimento do vetor com os pesos dos itens
    }

    escolhe_oq_entra(pesotot, B, num_itens, atual, 0);

    print_result(B, num_itens);

    libera_list(B, num_itens);

}

#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int in_out;  
    int peso;
} item;

typedef struct item * p_item;

p_item inicia_vetor(int num_itens){

    p_item item;
    item = malloc(num_itens * sizeof(item));

    for(int i=0; i<num_itens; i++){
        item[i].peso = 0;
        item[i].in_out = 0;
    }
    return item;
}

int escolhe_oq_entra(int pesotot, p_item item, int num_itens, int atual, int index){

        if(atual == pesotot) return 1;
        if(num_itens == 0) return 0;
        if(atual>pesotot) return 0;

        item[index].in_out = 1;

        if(escolhe_oq_entra(pesotot, item, num_itens-1, atual+item[index].peso, index+1)){
          return 1;
        }

        item[index].in_out = 0;

        if(escolhe_oq_entra(pesotot, item, num_itens-1, atual, index+1)){
          return 1;
        }
        
    return 0;
}

void print_result(p_item B, int num_itens){
    for(int i=0; i<num_itens; i++){
        printf("%d ", B[i].in_out);
    }
    printf("\n");
}

void libera_list(p_item B, int num_itens){
  free(B);
}

int main(int argc, char * argv[]){

    int pesotot = 0, num_itens = 0, atual = 0;

    scanf("%d", &pesotot);
    scanf("%d", &num_itens);

    p_item B = inicia_vetor(num_itens);

    for(int i = 0; i<num_itens; i++){
        scanf("%d", &B[i].peso);
    }

    escolhe_oq_entra(pesotot, B, num_itens, atual, 0);

    print_result(B, num_itens);

    libera_list(B, num_itens);

}

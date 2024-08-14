#include <stdio.h>
#include <stdlib.h>

#define MAX_PILHAS 1000
#define MAX_CAIXAS 1000

typedef struct {
    int tamanho;
    int caixas[MAX_CAIXAS];
} Pilha;

int main() {
    int N, P;
    Pilha pilhas[MAX_PILHAS];

    while(scanf("%d %d", &N, &P) && (N != 0 || P != 0)){
        int i, j, pos_pilha_1 = -1, pos_caixa_1 = -1;

        for(i = 0; i < P; i++){
            scanf("%d", &pilhas[i].tamanho);
            for(j = 0; j < pilhas[i].tamanho; j++){
                scanf("%d", &pilhas[i].caixas[j]);
                if(pilhas[i].caixas[j] == 1){
                    pos_pilha_1 = i;
                    pos_caixa_1 = j;
                }
            }
        }

        int removidas = 0;

        for(i = 0; i < P; i++){
            if(i == pos_pilha_1){
                removidas += pilhas[i].tamanho - pos_caixa_1 - 1;
            } else{
                if(pilhas[i].tamanho > 0){
                    int topo_caixa = pilhas[i].caixas[pilhas[i].tamanho - 1];
                    if((i > 0 && pilhas[i - 1].tamanho == 0) || (i < P - 1 && pilhas[i + 1].tamanho == 0)){
                        removidas++;
                    } else if(i == 0 || i == P - 1){
                        removidas++;
                    }
                }
            }
        }

        printf("%d\n", removidas);
    }

    return 0;
}
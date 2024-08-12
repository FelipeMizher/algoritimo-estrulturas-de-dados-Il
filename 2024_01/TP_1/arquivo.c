#include <stdio.h>

void numeros_inversos(FILE *arq, int linha){
    char numero[1000];
    int posicao = 0;

    fseek(arq, 0, SEEK_SET);
    
    while(fgets(numero, sizeof(numero), arq) != NULL){
        posicao++;
        if(linha == posicao){
            printf("%s", numero);
        }
    }
}

int main(void){
    int n = 0;
    FILE *arq = fopen("numeros.txt", "wt");
    double numero = 0.0;

    scanf(" %d", &n);

    for(int i = 0; i < n; i++){
        scanf(" %lf", &numero);

        fprintf(arq, "%g\n", numero);
    }

    fclose(arq);

    arq = fopen("numeros.txt", "rt");

    for(int i = n; i > 0; i--){
        numeros_inversos(arq, i);
    }

    fclose(arq); 
  return 0;
}
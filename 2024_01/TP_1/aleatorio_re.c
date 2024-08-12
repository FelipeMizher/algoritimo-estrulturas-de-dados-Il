#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alteracao(char ptr[], int i){
    char atual = ('a' + rand() % 26);
    char nova = ('a' + rand() % 26);

    if(i < strlen(ptr)){
        if(ptr[i] == atual){
            ptr[i] = nova;
        }
        return alteracao(ptr, i + 1);
    }

  return ptr;
}

int main(){
    char frase[1000];

    fgets(frase, sizeof(frase), stdin);
    while(strcmp(frase, "FIM\n") != 0){
        srand(4);
        frase[strcspn(frase, "\n")] = '\0';

        char *resp = alteracao(frase, 0);
        printf("%s\n", resp);
        fgets(frase, sizeof(frase), stdin);
    }

  return 0;
}

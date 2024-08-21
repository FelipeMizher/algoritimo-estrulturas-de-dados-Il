#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verificar_palindromo_recursivo(char *str, int i, int j) {
    if (i >= j) {
        return 1; 
    }
    
    if (str[i] != str[j]) {
        return 0;
    }
    
    return verificar_palindromo_recursivo(str, i + 1, j - 1);
}

int verificar_palindromo(char *str){
    int tamanho = strlen(str) - 1;

    return verificar_palindromo_recursivo(str, 0, tamanho);
}

int main(){
    char line[400];
    int continua = 1;

    while(continua){
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

        if(strcmp(line, "FIM") == 0){
            continua = 0;
        } else{
            if(verificar_palindromo(line) == 1){
                printf("SIM\n");
            } else{
                printf("NAO\n");
            }
        }
    }

 return 0;
}
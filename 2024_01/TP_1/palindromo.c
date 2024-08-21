#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verificar_palindromo(char *str){
    int i = 0;
    int j = strlen(str) - 1;

    while(i < j){
        if(str[i] != str[j]){
            return 0;
        }

        i++;
        j--;
    }

    return 1;
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
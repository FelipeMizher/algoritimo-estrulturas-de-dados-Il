#include <stdio.h>
#include <string.h>

int contar_maiusculos(char *str){
    int count = 0;
    
    if (*str == '\0'){
        return 0;
    }

    if (*str >= 'A' && *str <= 'Z'){
        count = 1;
    }

    return count + contar_maiusculos(str + 1);
}

int main(){
    char line[80];

        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        if(strcmp(line, "FIM") != 0){
            printf("%d\n", contar_maiusculos(line));
        } else{
            return 0;
        }

 return main();
}
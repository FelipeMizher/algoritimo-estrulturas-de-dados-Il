#include <stdio.h>
#include <string.h>

int contar_maiusculos(char *str) {
    int count = 0;
    char *ptr = str;

    while (*ptr != '\0') {
        if (*ptr >= 'A' && *ptr <= 'Z') {
            count++;
        }
        ptr++;
    }
    
 return count;
}

int main(){
    char line[80];

    do{
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        if(strcmp(line, "FIM") != 0){
            printf("%d\n", contar_maiusculos(line));
        }
    } while (strcmp(line, "FIM") != 0);

 return 0;
}
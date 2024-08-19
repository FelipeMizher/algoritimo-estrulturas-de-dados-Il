#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100001
char output[MAX_SIZE];

void beiju(char *text){
    int i, len = strlen(text);
    int cursor;
    cursor = 0;

    for(i = 0; i < len; i++){
        if(text[i] == '['){
            cursor = 0; 
        } else if(text[i] == ']'){
            cursor = strlen(output);
        } else{
            memmove(output + cursor + 1, output + cursor, strlen(output) - cursor + 1);
            output[cursor++] = text[i];
        }
    }

    output[strlen(output)] = '\0';
}

int main(){
    char frase[MAX_SIZE];

    while(scanf("%s", frase) == 1 && strcmp(frase, "FIM") != 0){
        beiju(frase);
        printf("%s\n", output);

        output[0] = '\0';
    }

    return 0;
}

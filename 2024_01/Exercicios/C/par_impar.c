#include <stdio.h>

char verificar_num(int num){

    if(num % 2 == 0){
        return 'P';;
    } else{
        return 'I';
    } 
}

int main(){
    int num = 0;

    do{
        scanf("%d", &num);
        if(num != 0){
            printf("%c\n", verificar_num(num));
        }
    } while(num != 0);

 return 0;
}
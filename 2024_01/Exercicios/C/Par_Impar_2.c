#include <stdio.h>

int verificar(int x){
    if(x % 2 == 0){
        return 1;
    } else{
        return 0;
    }

}

int main(void){
    int x = 0;

    scanf("%d", &x);

    if(verificar(x) == 1){
        printf("Par");
    } else{
        printf("Impar");
    }

  return 0;
}
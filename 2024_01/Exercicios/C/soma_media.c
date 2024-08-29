#include <stdio.h>

int main(void){
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
    int soma = 0, media = 0;
    
     scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

     soma = n1 + n2 + n3 + n4 + n5;

     media = soma / 5;

     printf("%d\n", soma);
     printf("%d\n", media);

  return 0;
}
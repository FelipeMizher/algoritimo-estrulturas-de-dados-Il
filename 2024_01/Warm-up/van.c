#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
    char nome[50];
    int custo;
    char regiao;
};

int comparar(const void *a, const void *b) {
    struct Aluno *alunoA = (struct Aluno *)a;
    struct Aluno *alunoB = (struct Aluno *)b;

    if (alunoA->custo != alunoB->custo) {
        return alunoA->custo - alunoB->custo;
    }

    if (alunoA->regiao != alunoB->regiao) {
        return alunoA->regiao - alunoB->regiao;
    }

    return strcmp(alunoA->nome, alunoB->nome);
}

int main(void){
    int Q = 0;

    scanf("%d", &Q);

    struct Aluno alunos[Q];

    for(int i = 0; i < Q; i++){
        scanf("%s %c %d", alunos[i].nome, &alunos[i].regiao, &alunos[i].custo);
    }

     qsort(alunos, Q, sizeof(struct Aluno), comparar);

    for(int i = 0; i < Q; i++){
        printf("%s\n", alunos[i].nome);
    }

  return 0;
}
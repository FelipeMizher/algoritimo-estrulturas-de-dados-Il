#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int count = 0;
float tempo = 0.0;
clock_t inicio;
clock_t fim;

typedef struct{
    int dia; 
    int mes; 
    int ano;
} LocalDate;

typedef struct{
    char id[50];
    char name[50];
    char alternate_names[200];
    char house[50];
    char ancestry[50];
    char species[50];
    char patronus[50];
    char actorName[50];
    char alternate_actors[200];
    char eyeColour[50];
    char gender[50];
    char hairColour[50];
    int yearOfBirth;
    bool hogwartsStaff;
    bool hogwartsStudent;
    bool alive;
    bool wizard;
    LocalDate dateOfBirth;
}Personagem;

typedef struct No{
    Personagem elemento;
    struct No *esq, *dir;
    int nivel;
} No;

No *novoNo(Personagem p);
void start();
int max(int a, int b);
int altura(No *no);
int fatorBalanceamento(No *no);
No *rotacionarDir(No *no);
No *rotacionarEsq(No *no);
void inserir(Personagem elemento);
No *inserirRec( Personagem elemento, No *no);
No *balancear(No *no);
void pesquisar(char x[]);
bool pesquisarRec(No *i, char x[]);
void caminharPre();
void caminharPreRec(No* i);

No *novoNo(Personagem p){
    No *novo = (No *)malloc(sizeof(No));

    novo->elemento = p;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->nivel = 1;

    return novo;
}

No* raiz;

void start(){
    raiz = NULL;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int altura(No *no){
    if(no == NULL){
        return 0;
    }

    return no->nivel;
}

int fatorBalanceamento(No *no){
    if(no == NULL){
        return 0;
    }

    return altura(no -> dir) - altura(no -> esq);
}

No *rotacionarDir(No *no){
    No *noEsq = no->esq;
    No *noEsqDir = noEsq->dir;

    noEsq->dir = no;
    no->esq = noEsqDir;
    no->nivel = max(altura(no->esq), altura(no->dir)) + 1;
    noEsq->nivel = max(altura(noEsq->esq), altura(noEsq->dir)) + 1;

    return noEsq;
}

No *rotacionarEsq(No *no){
    No *noDir = no->dir;
    No *noDirEsq = noDir->esq;

    noDir->esq = no;
    no->dir = noDirEsq;
    no->nivel = max(altura(no->esq), altura(no->dir)) + 1;
    noDir->nivel = max(altura(noDir->esq), altura(noDir->dir)) + 1;

    return noDir;
}   

void inserir(Personagem elemento){
    raiz = inserirRec(elemento, raiz);
}

No *inserirRec(Personagem elemento, No *no){
    if(no == NULL){
        return novoNo(elemento);
    }
    int comparacao = strcmp(elemento.name, no->elemento.name);

    if(comparacao < 0){
        no->esq = inserirRec(elemento, no->esq);
    } else if(comparacao > 0){
        no->dir = inserirRec(elemento, no->dir);
    } else{
        no->elemento = elemento;
        return no;
    }
    balancear(no);
}

No *balancear(No *no){
    no->nivel = 1 + max(altura(no->esq), altura(no->dir));
    int fator = fatorBalanceamento(no);

    if(fator > 1){
        if(fatorBalanceamento(no->dir) < 0){
            no->dir = rotacionarDir(no->dir);
        }
        return rotacionarEsq(no);
    }

    if(fator < -1){
        if(fatorBalanceamento(no->esq) > 0){
            no->esq = rotacionarEsq(no->esq);
        }
        return rotacionarDir(no);
    }
    return no;
}

void pesquisar(char *nome) {
    printf("%s => raiz", nome);
    count = 0;

    if(pesquisarRec(raiz, nome)) {
        printf(" SIM\n");
    } else {
        printf(" NAO\n");
    }
}

bool pesquisarRec(No *no, char *nome){
    if (no == NULL){
        return false;
    }
    int comparacao = strcmp(nome, no->elemento.name);
    count++;

    if (comparacao == 0) {
        return true;
    }
    else if (comparacao > 0) {
        printf(" dir");
        return pesquisarRec(no->dir, nome);
    }
    else {
        printf(" esq");
        return pesquisarRec(no->esq, nome);
    }
}

Personagem personagens[404];

void initPersonagem(Personagem *p){
    strcpy(p->id, "");
    strcpy(p->name, "");
    strcpy(p->alternate_names, "");
    strcpy(p->house, "");
    strcpy(p->ancestry, "");
    strcpy(p->species, "");
    strcpy(p->patronus, "");
    strcpy(p->actorName, "");
    strcpy(p->alternate_actors, "");
    strcpy(p->eyeColour, "");
    strcpy(p->gender, "");
    strcpy(p->hairColour, "");
    p->hogwartsStaff = false;
    p->hogwartsStudent = false;
    p->alive = false;
    p->wizard = false;
    p->yearOfBirth = -1;
    p->dateOfBirth.dia = -1;
    p->dateOfBirth.mes = -1;
    p->dateOfBirth.ano = -1;
}

LocalDate ajustarData(char data[]){
    LocalDate localDate;
    sscanf(data, "%d-%02d-%04d", &localDate.dia, &localDate.mes, &localDate.ano);
    return localDate;
}

void setDados(Personagem *p, char *line){
    char str[300];
    char date[11]; 
    char year[5];
    int x = 0; 
    int y = 0;

    strcpy(str,line);

    while(str[x] != ';'){ 
        p->id[y] = str[x]; 
        x++; 
        y++;
    }    
    p->id[y] = '\0'; x++; y = 0;
    
    while(str[x] != ';'){ 
        p->name[y] = str[x]; 
        x++; 
        y++;
    }  
    p->name[y] = '\0'; x++; y = 0;
    
    while(str[x] != ';'){ 
        if(str[x] != '[' && str[x] != ']' && str[x] != 39){ 
            p->alternate_names[y] = str[x]; 
            y++;
        } x++;
    }  
    p->alternate_names[y] = '\0'; x++; y = 0;   
    
    while(str[x] != ';'){ 
        p->house[y] = str[x]; 
        x++; 
        y++;
    } 
    p->house[y] = '\0'; x++; y = 0;
    
    while(str[x] != ';'){ 
        p->ancestry[y] = str[x]; 
        x++; 
        y++;
    }  
    p->ancestry[y] = '\0'; x++; y = 0;
    
    while(str[x] != ';'){ 
        p->species[y] = str[x]; 
        x++; 
        y++;
    }   
    p->species[y] = '\0'; x++; y = 0;
    
    while(str[x] != ';'){ 
        p->patronus[y] = str[x]; 
        x++; 
        y++;
    }  
    p->patronus[y] = '\0'; x++; y = 0;
    
    while(str[x] != ';'){ 
        if(str[x] == 'V'){ 
            p->hogwartsStaff = true; 
            x += 10;
        } else{ 
            p->hogwartsStaff = false; 
            x += 5;
        }
    } x++; y = 0;
    
    while(str[x] != ';'){ 
        if(str[x]=='V'){ 
            p->hogwartsStudent = true; 
            x += 10;
        } else{ 
            p->hogwartsStudent = false; 
            x += 5;
        }
    } 
    x++; y = 0;
    
    while(str[x] != ';'){ 
        p->actorName[y] = str[x]; 
        x++; 
        y++;
    }  
    p->actorName[y] = '\0'; x++; y = 0;
    
    while(str[x] != ';'){ 
        if(str[x] == 'V'){ 
            p->alive = true;
            x += 10;
        } else{ 
            p->alive = false; 
            x += 5;
        }
    } 
    x++; y = 0;
    
    while(str[x] != ';'){ 
        p->alternate_actors[y] = str[x]; 
        x++; 
        y++;
    }  
    p->alternate_actors[y] = '\0'; x++; y = 0;
    
    while(str[x] != ';'){ 
        date[y] = str[x]; 
        x++; 
        y++;
    } 
    LocalDate data = ajustarData(date); 
    p->dateOfBirth = data; x++; y = 0;
    
    while(str[x] != ';'){ 
        year[y] = str[x];
        x++; 
        y++;
    } 
    p->yearOfBirth = atoi(year); x++; y = 0;
    
    while(str[x] != ';'){ 
        p->eyeColour[y] = str[x]; 
        x++; 
        y++;
    }  
    p->eyeColour[y]='\0'; x++; y = 0;
    
    while(str[x] != ';'){ 
        p->gender[y] = str[x]; 
        x++; 
        y++;
    } 
    p->gender[y]='\0'; x++; y = 0;
    
    while(str[x] != ';'){ 
        p->hairColour[y] = str[x]; 
        x++; 
        y++;
    }  
    p->hairColour[y] = '\0'; x++; y = 0;

    if(str[x] == 'V'){ 
        p->wizard = true; 
        x += 10;
    } else{ 
        p->wizard = false; 
        x += 5;
    }
}

void lerDados(){
    char path[100];
    bool header = true;
    char line[500];
    int i = 0;

    strcpy(path, "C:/Users/felip_000/Desktop/AED_2/TP_4/characters.csv");
    FILE *file = fopen(path, "r");
    if(file == NULL){
        perror("Erro ao abrir o arquivo");
        return;
    }

    while(fgets(line, sizeof(line), file)){
        if(header){
            header = false;
        } else{
            initPersonagem(&personagens[i]);
            setDados(&personagens[i], line);
            i++;
        }
    }
    fclose(file);
}

void toString(Personagem *p) {
    printf("[%s ## %s ## {%s} ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %02d-%02d-%d ## %d ## %s ## %s ## %s ## %s]\n", p->id, p->name, p->alternate_names, p->house, 
    p->ancestry, p->species, p->patronus, p->hogwartsStaff ? "true" : "false", p->hogwartsStudent ? "true" : "false", p->actorName, p->alive ? "true" : "false", 
    p->dateOfBirth.dia, p->dateOfBirth.mes, p->dateOfBirth.ano, p->yearOfBirth, p->eyeColour, p->gender, p->hairColour, p->wizard ? "true" : "false");

}

void clonePersonagem(Personagem *p, Personagem *clone){
    strncpy(p->id, clone->id, strlen(p->id));
    strncpy(p->name, clone->name, strlen(p->name));
    strncpy(p->alternate_names, clone->alternate_names, strlen(p->alternate_names));
    strncpy(p->house, clone->house, strlen(p->house));
    strncpy(p->ancestry, clone->ancestry, strlen(p->ancestry));
    strncpy(p->species, clone->species, strlen(p->species));
    strncpy(p->patronus, clone->patronus, strlen(p->patronus));
    p->hogwartsStaff = clone->hogwartsStaff;
    p->hogwartsStudent = clone->hogwartsStudent;
    strncpy(p->actorName, clone->actorName, strlen(p->actorName));
    p->alive = clone->alive;
    strncpy(p->alternate_actors, clone->alternate_actors, strlen(p->alternate_actors));
    p->dateOfBirth = clone->dateOfBirth;
    p->yearOfBirth = clone->yearOfBirth;
    strncpy(p->eyeColour, clone->eyeColour, strlen(p->eyeColour));
    strncpy(p->gender, clone->gender, strlen(p->gender));
    strncpy(p->hairColour, clone->hairColour, strlen(p->hairColour));
    p->wizard = clone->wizard;
}

Personagem procurar(Personagem array[], char *id){
    Personagem personagem;

    if(id[strlen(id) + 2] == '\n'){
        id[strlen(id) + 2] = '\0';
    }

    for(int i = 0; i < 404; i++){
        if (strcmp(array[i].id, id) == 0){
            personagem = array[i];
            i = 404;
        }
    }
    return personagem;
}

void inserirArvore(Personagem array[]){
    char id[40];

    scanf("%s", id);
    while(strcmp(id, "FIM") != 0){
        Personagem x = procurar(array, id);
        inserir(x);
        scanf("%s", id);
    }
}

void procurarNaArvore(){
    char nome[100];

    scanf(" %[^\n\r]", nome);
    inicio = clock();
    while(strcmp(nome, "FIM")!=0){
        pesquisar(nome);
        scanf(" %[^\n\r]", nome);
    }
    fim = clock();
    tempo = ((double)(inicio - fim)) / CLOCKS_PER_SEC;
}

void registroLog(){
    FILE *arquivo;

    arquivo = fopen("821811_avl.txt", "w");

    fprintf(arquivo, "Matrícula: 821811\t Tempo de execução: %.6f segundos\t Número de comparações: %d", tempo, count);

    fclose(arquivo);
}

int main(){
    Personagem array[404];

    lerDados(array); 
    start();
    inserirArvore(array);
    procurarNaArvore();
    registroLog();

  return 0;
}
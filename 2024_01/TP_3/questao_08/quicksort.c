#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int count = 0, movimentacoes = 0;
float tempo = 0.0;
clock_t start;
clock_t end;

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
} Personagem;

typedef struct Celula{
    struct Celula* prox;
    struct Celula* ant;
    Personagem elemento;
}Celula;

Celula* primeiro;
Celula* ultimo;
int tamanho = 0;
Personagem personagens[404];

Celula* novaCelula(Personagem elemento) {
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = NULL; nova->ant = NULL;
   return nova;
}

void initPersonagem(Personagem *p);

void init() {
    Personagem x;
    initPersonagem(&x);
    primeiro = novaCelula(x);
    ultimo = primeiro;
}

void adicionar(Personagem x) {
    if(tamanho < 404){
        ultimo->prox = novaCelula(x);
        ultimo->prox->ant = ultimo;
        ultimo = ultimo->prox;
        tamanho++;
    }   
}

Personagem personagens[404];
Personagem sub[404];
int tamanhoSubList = 0;

void swap(Celula *p1, Celula *p2){
    Personagem tmp = p1->elemento;
    p1->elemento = p2->elemento;
    p2->elemento = tmp;
    movimentacoes += 3;
}

void clone(Personagem *p, Personagem *clone);
LocalDate ajustarData(char data[]);
void setDados(Personagem *p, char *line);
void lerDados();
void Exibir();
void toString(Personagem *p);
bool isFim(char str[]);
void swap(Celula *p1, Celula *p2);
void registroLog();

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

bool isFim(char str[]){
    return str[0] == 'F' && str[1] == 'I' && str[2] == 'M';
}

void lerDados(){
    char path[100];
    bool header = true;
    char line[500];
    int i = 0;

    strcpy(path, "/tmp/characters.csv");
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

bool comparator(Personagem a, Personagem b){
    bool resposta = false;

    if(strcmp(a.house, b.house) < 0){       
        resposta = true; 
        count++;  
    } else if(strcmp(a.house, b.house) > 0){
        resposta = false;
        count++;
    } else{                              
        if(strcmp(a.name, b.name) < 0){
            resposta = true;
            count++;
        } else{
            count++;
            resposta = false;
        }
    }
    return resposta;
}

void Exibir(){
    for(Celula *i = primeiro->prox;i != NULL;i = i->prox){
        toString(&i->elemento);
    }
}

void clone(Personagem *p, Personagem *clone){
    strcpy(clone->id, p->id);
    strcpy(clone->name, p->name);
    strcpy(clone->alternate_names, p->alternate_names);
    strcpy(clone->house, p->house);
    strcpy(clone->ancestry, p->ancestry);
    strcpy(clone->species, p->species);
    strcpy(clone->patronus, p->patronus);    
    strcpy(clone->actorName, p->actorName);
    strcpy(clone->eyeColour, p->eyeColour);
    strcpy(clone->gender, p->gender);
    strcpy(clone->hairColour, p->hairColour);
    strcpy(clone->alternate_actors, p->alternate_actors);
    clone->hogwartsStaff = p->hogwartsStaff;
    clone->hogwartsStudent = p->hogwartsStudent;
    clone->alive = p->alive;
    clone->dateOfBirth.dia = p->dateOfBirth.dia;
    clone->dateOfBirth.mes = p->dateOfBirth.mes;
    clone->dateOfBirth.ano = p->dateOfBirth.ano;
    clone->yearOfBirth = p->yearOfBirth;
    clone->wizard = p->wizard;
}

void subList(){
    char id[40];

    scanf(" %s", id);
    while(!isFim(id)){
        int i = 0;
        while(i < 404){
            if(strcmp(personagens[i].id, id) == 0){
                adicionar(personagens[i]);
                break;
            }
            i++;
        }
        scanf(" %s", id);
    }
}

bool verify(Celula* i, Celula* pro){
    bool resposta = false;

    while(!resposta && i != NULL){
        if(i == pro){
            resposta = true;
        }
        i = i->prox;
    }

  return resposta;
}

void inserir(Celula* esq, Celula* dir){
    if(esq != dir && esq != dir->prox){
        Celula* i = esq; Celula* j = dir;
        Personagem pivo = i->elemento;
        while(verify(i, j)){
            while(comparator(i->elemento, pivo)){ 
                i = i->prox; 
            }
            while(comparator(pivo, j->elemento)){ 
                j = j->ant; 
            }
            if(verify(i, j)){
                swap(i, j);
                i = i->prox; 
                j = j->ant;
            }
        }
        inserir(esq, j);
        inserir(i, dir);
    }
}

void quicksort(){
    start = clock();
    inserir(primeiro->prox, ultimo);
    end = clock();
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC;
}

void registroLog(){
    FILE *arquivo;

    arquivo = fopen("/tmp/821811_quicksort2.txt", "w");

    fprintf(arquivo, "Matrícula: 821811\t Tempo de execução: %.6f segundos\t Número de comparações: %d \t Número de movimentações: %d", tempo, count, movimentacoes);

    fclose(arquivo);
}

int main() {

    lerDados(); 
    init();
    subList();
    quicksort();
    Exibir();
    registroLog();

  return 0;
}
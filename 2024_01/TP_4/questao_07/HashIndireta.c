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

typedef struct Celula{
    Personagem elemento;
    struct Celula* prox;
} Celula;

void start();
Celula* novaCelula(Personagem elemento);
void inserir(Personagem p);
int hash(char *str);
void pesquisar(char* nome);

Personagem p[404];
Celula* array[21];

void start(){
    for(int i = 0; i < 21; i++){
        array[i] = NULL;
    }
}

Celula* novaCelula(Personagem elemento){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = elemento;
    nova->prox = NULL;
    return nova;
}

void inserir(Personagem p){
    int pos = hash(p.name);
    Celula* nova = novaCelula(p);
    nova->prox = array[pos];
    array[pos] = nova;
}

int hash(char *str){
    int resp = 0;
    for(int i = 0; str[i] != '\0'; i++){
        resp += (int)str[i];
    }
    resp = resp % 21;
    return resp;
}

void pesquisar(char* nome){
    int pos = hash(nome);
    Celula* tmp = array[pos];
    bool encontrado = false;

    while(tmp != NULL && !encontrado){
        count++;
        if(strcmp(tmp->elemento.name, nome) == 0){
            encontrado = true;
        }
        tmp = tmp->prox;
    }

    if(encontrado){
        printf("%s (pos: %d) SIM\n", nome, pos);
    } else{
        printf("%s NAO\n", nome);
    }
}

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
            initPersonagem(&p[i]);
            setDados(&p[i], line);
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

void clonePersonagem(Personagem *destino, Personagem *origem) {
    strcpy(destino->id, origem->id);
    strcpy(destino->name, origem->name);
    strcpy(destino->alternate_names, origem->alternate_names);
    strcpy(destino->house, origem->house);
    strcpy(destino->ancestry, origem->ancestry);
    strcpy(destino->species, origem->species);
    strcpy(destino->patronus, origem->patronus);
    destino->hogwartsStaff = origem->hogwartsStaff;
    destino->hogwartsStudent = origem->hogwartsStudent;
    strcpy(destino->actorName, origem->actorName);
    destino->alive = origem->alive;
    strcpy(destino->alternate_actors, origem->alternate_actors);
    destino->dateOfBirth = origem->dateOfBirth;
    destino->yearOfBirth = origem->yearOfBirth;
    strcpy(destino->eyeColour, origem->eyeColour);
    strcpy(destino->gender, origem->gender);
    strcpy(destino->hairColour, origem->hairColour);
    destino->wizard = origem->wizard;
}

Personagem procurar(Personagem array[], char *id){
    for(int i = 0; i < 404; i++){
        if(strcmp(array[i].id, id) == 0){
            return array[i];
        }
    }
    Personagem personagem;
    initPersonagem(&personagem);

    return personagem;
}

Personagem findName(Personagem array[], char* name){
    for(int i = 0; i < 404; i++){
        if(strcmp(array[i].name, name) == 0){
            return array[i];
        }
    }

    Personagem personagem;
    initPersonagem(&personagem);

    return personagem;
}

void inserirHash(Personagem array[]){
    char id[100];

    scanf(" %[^\n\r]", id);
    while(strcmp(id, "FIM") != 0){
        Personagem p = procurar(array, id);
        inserir(p);
        scanf(" %[^\n\r]", id);
    }
}

void procurarHash(){
    char nome[100];

    scanf(" %[^\n\r]", nome);
    inicio = clock();

    while(strcmp(nome, "FIM") != 0){
        pesquisar(nome);
        scanf(" %[^\n\r]", nome);
    }

    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

void registroLog(){
    FILE *arquivo;

    arquivo = fopen("/tmp/821811_HashIndireta.txt", "w");

    fprintf(arquivo, "Matrícula: 821811\t Tempo de execução: %.6f segundos\t Número de comparações: %d", tempo, count);

    fclose(arquivo);
}

int main(){
    Personagem array[404];

    lerDados(array); 
    start();
    inserirHash(array);
    procurarHash();
    registroLog();   
          
    return 0;
}
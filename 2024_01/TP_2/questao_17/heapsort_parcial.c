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

Personagem personagens[404];
Personagem sub[404];
int tamanhoSubArray = 0;

void swap(Personagem *per1, Personagem *per2){
    Personagem tmp = *per1;
    *per1 = *per2;
    *per2 = tmp;
    movimentacoes = movimentacoes + 3;
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
            initPersonagem(&personagens[i]);
            setDados(&personagens[i], line);
            i++;
        }
    }
    fclose(file);
}

void toString(Personagem *personagem){

    printf("[%s ## %s ## {%s} ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %02d-%02d-%d ## %d ## %s ## %s ## %s ## %s]\n", 
    personagem->id, personagem->name, personagem->alternate_names, personagem->house, personagem->ancestry, personagem->species, 
    personagem->patronus, personagem->hogwartsStaff ? "true" : "false", personagem->hogwartsStudent ? "true" : "false", personagem->actorName, 
    personagem->alive ? "true" : "false", personagem->dateOfBirth.dia, personagem->dateOfBirth.mes, personagem->dateOfBirth.ano, 
    personagem->yearOfBirth, personagem->eyeColour, personagem->gender, personagem->hairColour, personagem->wizard ? "true" : "false");

}

bool comparar(Personagem a, Personagem b){
    bool resposta = false;  

    if(strcmp(a.hairColour, b.hairColour) < 0){       
        resposta = true; 
        count++;  
    } else if(strcmp(a.hairColour, b.hairColour) > 0){ 
        resposta = false;
        count++;
    } else{                           
        count += 2;
        if(strcmp(a.name, b.name) < 0){ 
            resposta = true;
            count++;
        } else{               
            resposta = false;
            count++;
        }
    } 
    return resposta;
}

void Exibir(int key){
    for(int i = 0; i < key; i++){
        toString(&sub[i]);
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

void subArray(){
    char id[50];

    scanf(" %s", id);
    while(strcmp(id, "FIM") != 0){
        int i = 0;
        while(i < 404){
            if(strcmp(personagens[i].id, id) == 0){
                clone(&personagens[i], &sub[tamanhoSubArray]);
                tamanhoSubArray++;
                break;
            }
            i++;
        }
        scanf(" %s", id);
    }
}

int getMaiorFilho(Personagem tmp[], int i, int tamanhoHeap){
    int filho = 0;
    if (2*i == tamanhoHeap || !comparar(tmp[2*i], tmp[2*i+1])){
        filho = 2*i;
    } else {
        filho = 2*i + 1;
    }
    return filho;
}

void reconstruir(Personagem tmp[], int tamanhoHeap){
    int i = 1;
    while(i <= (tamanhoHeap/2)){
        int filho = getMaiorFilho(tmp, i, tamanhoHeap);
        if(comparar(tmp[i], tmp[filho])){
            swap(&tmp[i], &tmp[filho]);
            i = filho;
        } else{
            i = tamanhoHeap;
        }
    }
}

void construir(Personagem tmp[], int tamanhoHeap){
    for(int i = tamanhoHeap; i > 1 && !comparar(tmp[i], tmp[i/2]); i /= 2){
        swap(&tmp[i], &tmp[i/2]);
    }
}

void heapsort(){
    int key = 10;
    start = clock();

    Personagem tmp[tamanhoSubArray+1];
    for(int i = 0; i < tamanhoSubArray; i++){
        tmp[i+1] = sub[i];
    }
    for(int tamanhoHeap = 2; tamanhoHeap <= key; tamanhoHeap++){
        construir(tmp, tamanhoHeap);
    }

    for(int i = key+1;i<=tamanhoSubArray; i++){
        if(comparar(tmp[i], tmp[1])){
            swap(&tmp[i], &tmp[1]);
            reconstruir(tmp, key);
        }
    }

    int tamanhoHeap = key;
    while(tamanhoHeap > 1){
        swap(&tmp[1], &tmp[tamanhoHeap--]);
        reconstruir(tmp, tamanhoHeap);
    }
    for(int i = 0; i < tamanhoSubArray; i++){
        sub[i] = tmp[i+1];
    }
    end = clock();
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC;
    Exibir(key);
}

void registroLog(){
    FILE *arquivo;

    arquivo = fopen("/tmp/821811_heapsort.txt", "w");

    fprintf(arquivo, "Matrícula: 821811\t Tempo de execução: %.6f segundos\t Número de comparações: %d \t Número de movimentações: %d", tempo, count, movimentacoes);

    fclose(arquivo);
}

int main() {

    lerDados(); 
    subArray();
    heapsort();
    registroLog();

  return 0;
}
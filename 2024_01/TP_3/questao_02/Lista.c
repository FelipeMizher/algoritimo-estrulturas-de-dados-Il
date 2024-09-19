#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    int dia; 
    int mes; 
    int ano;
} LocalDate;

int tamanho = 0;

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

void lerDados(Personagem p[]){
    char path[100];
    bool header = true;
    char line[500];
    int i = 0;

    strcpy(path, "/tmp/characters.csv");
    FILE *file = fopen(path, "r");
    if (file == NULL) {
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

void toString(Personagem *p, int id){

    printf("[%d ## %s ## %s ## {%s} ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %02d-%02d-%d ## %d ## %s ## %s ## %s ## %s]\n", id, p->id, p->name, p->alternate_names, p->house,
           p->ancestry, p->species, p->patronus, p->hogwartsStaff ? "true" : "false", p->hogwartsStudent ? "true" : "false", p->actorName, p->alive ? "true" : "false",
           p->dateOfBirth.dia, p->dateOfBirth.mes, p->dateOfBirth.ano, p->yearOfBirth, p->eyeColour, p->gender, p->hairColour, p->wizard ? "true" : "false");

}

void Exibir(){
    for (int i = 0; i < tamanho; i++){
        toString(&personagens[i], i);
    }
}

void clonePersonagem(Personagem *clone, Personagem *p){
    strncpy(clone->id, p->id, strlen(clone->id));
    strncpy(clone->name, p->name, strlen(clone->name));
    strncpy(clone->alternate_names, p->alternate_names, strlen(clone->alternate_names));
    strncpy(clone->house, p->house, strlen(clone->house));
    strncpy(clone->ancestry, p->ancestry, strlen(clone->ancestry));
    strncpy(clone->species, p->species, strlen(clone->species));
    strncpy(clone->patronus, p->patronus, strlen(clone->patronus));
    clone->hogwartsStaff = p->hogwartsStaff;
    clone->hogwartsStudent = p->hogwartsStudent;
    strncpy(clone->actorName, p->actorName, strlen(clone->actorName));
    clone->alive = p->alive;
    strncpy(clone->alternate_actors, p->alternate_actors, strlen(clone->alternate_actors));
    clone->dateOfBirth = p->dateOfBirth;
    clone->yearOfBirth = p->yearOfBirth;
    strncpy(clone->eyeColour, p->eyeColour, strlen(clone->eyeColour));
    strncpy(clone->gender, p->gender, strlen(clone->gender));
    strncpy(clone->hairColour, p->hairColour, strlen(clone->hairColour));
    clone->wizard = p->wizard;
}

void inserirInicio(Personagem novo){
    for(int i = tamanho; i > 0; i--){
        personagens[i] = personagens[i - 1];
    }
    personagens[0] = novo;
    tamanho++;
}

void inserirFim(Personagem novo){
    personagens[tamanho] = novo;
    tamanho++;
}

void inserir(Personagem novo, int posicao){
    for(int i = tamanho; i > posicao; i--){
        personagens[i] = personagens[i - 1];
    }
    personagens[posicao] = novo;
    tamanho++;
}

Personagem removerInicio(){
    if(tamanho == 0){
        printf("Lista Vazia");
    }

    Personagem removido = personagens[0];
    tamanho--;
    for(int i = 0; i < tamanho; i++){
        personagens[i] = personagens[i + 1];
    }
    return removido;
}

Personagem removerFim(){
    if(tamanho == 0){
        printf("Lista Vazia");
    }

    return personagens[--tamanho];
}

Personagem remover(int posicao){
    if(tamanho == 0){
        printf("Lista Vazia");
    }

    Personagem removido = personagens[posicao];
    tamanho--;
    for(int i = posicao; i < tamanho; i++){
        personagens[i] = personagens[i + 1];
    }
    return removido;
}

void Array(Personagem array[]){
    char line[50];

    scanf("%s", line);
    while(strcmp(line, "FIM") != 0){
        for(int i = 0; i < 404; i++){
            if(strcmp(array[i].id, line) == 0){
                inserirFim(array[i]);
                i = 404;
            }
        }
        scanf("%s", line);
    }
}

Personagem Procurar(Personagem array[], char *id){
    Personagem personagem;

    if(id[strlen(id) + 2]=='\n'){
       id[strlen(id) + 2] = '\0';
    }

    for(int i = 0; i < 404; i++){
        if(strcmp(array[i].id, id) == 0){
            personagem = array[i];
            i = 404;
        }
    }
    return personagem;
}

void metodos(Personagem array[], int qtd){
    char input[100];

    for(int i = 0; i < qtd; i++){
        scanf(" %[^\n]", input);
        input[strcspn(input, "\n")] = '\0'; 
        Personagem novo;

        if(strncmp(input, "II ", 3) == 0){
            char id[100];
            sscanf(input + 3, "%s", id);
            novo = Procurar(array, id);
            inserirInicio(novo);
        } else if(strncmp(input, "IF ", 3) == 0){
            char id[100];
            sscanf(input + 3, "%s", id);
            novo = Procurar(array, id);
            inserirFim(novo);
        } else if(strncmp(input, "I* ", 3) == 0){
            int posicao;
            char id[100];
            sscanf(input + 3, "%d %s", &posicao, id);
            novo = Procurar(array, id);
            inserir(novo, posicao);
        } else if(strncmp(input, "RI", 2) == 0){
            novo = removerInicio();
            printf("(R) %s\n", novo.name);
        } else if(strncmp(input, "RF", 2) == 0){
            novo = removerFim();
            printf("(R) %s\n", novo.name);
        } else if(strncmp(input, "R* ", 3) == 0){
            int posicao;
            sscanf(input + 3, "%d", &posicao);
            novo = remover(posicao);
            printf("(R) %s\n", novo.name);
        }
    }
    Exibir();
}

int main(){
    Personagem array[404];
    int x = 0;

    lerDados(array); 
    Array(array);
    scanf(" %i", &x);
    metodos(array, x);

  return 0;
}
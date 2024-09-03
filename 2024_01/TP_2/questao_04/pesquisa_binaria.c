#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int count = 0;
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
int tamSubArray = 0;

void swap(Personagem *per1, Personagem *per2){
    Personagem tmp = *per1;
    *per1 = *per2;
    *per2 = tmp;
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
    if (file == NULL) {
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

void procurarId(){

    char id[50];

    scanf("%s", id);
    while(strcmp(id, "FIM") != 0){
        for(int i = 0; i < 405; i++){
            if(strcmp(personagens[i].id, id) == 0){
                toString(&personagens[i]);
                i = 405; 
            }
        }
        scanf("%s", id);
    }
}

void insercao(Personagem *per, int tam){
    for(int i = 0; i < (tam - 1); i++){
        int menor = i;
        for(int j = (i + 1); j < tam; j++){
            if(strcmp(per[menor].name, per[j].name) > 0){
                menor = j;
            }
        }
        swap(&per[menor], &per[i]);
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
                clone(&personagens[i], &sub[tamSubArray]);
                tamSubArray++;
                break;
            }
            i++;
        }
        scanf(" %s", id);
    }
    insercao(sub, tamSubArray);
}

bool isFim(char str[]){
    return str[0] == 'F' && str[1] == 'I' && str[2] == 'M';
}

void BuscarBin(){
    char id[100];

    scanf(" %[^\n\r]", id);
    start = clock();

    while(!isFim(id)){
        bool find = false;
        int left = 0, right = tamSubArray - 1;

        while(left <= right && !find){
            int mid = (left + right) / 2;
            int cmp = strcmp(sub[mid].name, id);

            if(cmp == 0){
                find = true;
                count++;
            } else if(cmp < 0){
                left = mid + 1;
                count++;
            } else{
                right = mid - 1;
                count++;
            }
        }

        if(find){
            printf("SIM\n");
        } else{
            printf("NAO\n");
        }
        scanf(" %[^\n\r]", id);
    }
    end = clock();
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC;
}

void registroLog(){
    FILE *arquivo;

    arquivo = fopen("/tmp/821811_binaria.txt", "w");

    fprintf(arquivo, "Matrícula: 821811\t Tempo de execução: %.6f segundos\t Número de comparações: %d", tempo, count);

    fclose(arquivo);
}

int main() {

    lerDados(); 
    subArray();
    BuscarBin();
    registroLog();

  return 0;
}
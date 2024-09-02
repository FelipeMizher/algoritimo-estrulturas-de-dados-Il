#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void initPersonagem(Personagem *p) {
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

LocalDate ajustarData(char data[]) {
    LocalDate localDate;
    sscanf(data, "%d-%02d-%04d", &localDate.dia, &localDate.mes, &localDate.ano);
    return localDate;
}

void setDados(Personagem *p, char *line){
    char str[300], date[11], year[5];
    int x = 0, y = 0;

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

void lerDados(Personagem personagem[]) {
    char path[100];
    bool header = true;
    char line[500];
    int i = 0;

    strcpy(path, "C:/Users/felip_000/Desktop/exercicos/TP_2/characters.csv");
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    while(fgets(line, sizeof(line), file)){
        if(header){
            header = false;
        } else{
            initPersonagem(&personagem[i]);
            setDados(&personagem[i], line);
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

void procurarId(Personagem personagem[]){
    char id[50];

    scanf("%s", id);
    while(strcmp(id, "FIM") != 0){
        for(int i = 0; i < 405; i++){
            if(strcmp(personagem[i].id, id) == 0){
                toString(&personagem[i]);
                i = 405; 
            }
        }
        scanf("%s", id);
    }
}

int main() {
    Personagem p[405];

    lerDados(p ); 
    procurarId(p);

  return 0;
}
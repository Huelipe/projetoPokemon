#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tipos{
int id;
char nome[10];
int resistencias[8];
int fraquezas[8];
int imunidades[3];
} tipos;

int main(){

    tipos tipos[18];

strcpy(tipos[0].nome, "Inseto");
strcpy(tipos[1].nome, "Normal");
strcpy(tipos[2].nome, "Fogo");
strcpy(tipos[3].nome, "Agua");
strcpy(tipos[4].nome, "Dragao");
strcpy(tipos[5].nome, "Venenoso");
strcpy(tipos[6].nome, "Elétrico");
strcpy(tipos[7].nome, "Voador");
strcpy(tipos[8].nome, "Gelo");
strcpy(tipos[9].nome, "Psiquico");
strcpy(tipos[10].nome, "Obscuro");
strcpy(tipos[11].nome, "Fantasma");
strcpy(tipos[12].nome, "Fada");
strcpy(tipos[13].nome, "Planta");
strcpy(tipos[14].nome, "Terra");
strcpy(tipos[15].nome, "Pedra");
strcpy(tipos[16].nome, "Lutador");
strcpy(tipos[17].nome, "Aço");

for(int i = 0; i < 18; i++){
    tipos[i].id = i;
}

int fraq[] = {2, 7, 15};
for (int i = 0; i < 3; i++) {
    tipos[0].fraquezas[i] = fraq[i];
};



for(int i = 0; i < 6; i++){
tipos[0].fraquezas[i] = fraq[i];

}

int valor = 2;

for(int i = 0; i < 3; i++){
    if(valor == tipos[0].fraquezas[i]){
        printf("deu certo\n");        
    }

}



    return 0;
}
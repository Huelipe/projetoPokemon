#include "estruturas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void vetorDeNatures(struct natureza natures[26]) {

//Define todas as 25 naturezas do jogo
    strcpy(natures[1].nome, "Hardy");
    strcpy(natures[2].nome, "Docile");
    strcpy(natures[3].nome, "Bashful");
    strcpy(natures[4].nome, "Quirky");
    strcpy(natures[5].nome, "Serious");;
    strcpy(natures[6].nome, "Bold");
    strcpy(natures[7].nome, "Modest");
    strcpy(natures[8].nome, "Calm");
    strcpy(natures[9].nome, "Timid");
    strcpy(natures[10].nome, "Lonely");
    strcpy(natures[11].nome, "Mild");
    strcpy(natures[12].nome, "Gentle");
    strcpy(natures[13].nome, "Hasty");
    strcpy(natures[14].nome, "Adamant");
    strcpy(natures[15].nome, "Impish");
    strcpy(natures[16].nome, "Careful");
    strcpy(natures[17].nome, "Jolly");
    strcpy(natures[18].nome, "Naughty");
    strcpy(natures[19].nome, "Lax");
    strcpy(natures[20].nome, "Rash");
    strcpy(natures[21].nome, "Naive");
    strcpy(natures[22].nome, "Brave");
    strcpy(natures[23].nome, "Relaxed");
    strcpy(natures[24].nome, "Quiet");
    strcpy(natures[25].nome, "Sassy");

    float comum = 1;
    float mais = 1.1;
    float menos = 0.9;

    natures[1].modAtk = natures[1].modDef = natures[1].modSpatack = natures[1].modSpdef = natures[1].modSpeed = comum;
    natures[2].modAtk = natures[2].modDef = natures[2].modSpatack = natures[2].modSpdef = natures[2].modSpeed = comum;
    natures[3].modAtk = natures[3].modDef = natures[3].modSpatack = natures[3].modSpdef = natures[3].modSpeed = comum;
    natures[4].modAtk = natures[4].modDef = natures[4].modSpatack = natures[4].modSpdef = natures[4].modSpeed = comum;
    natures[5].modAtk = natures[5].modDef = natures[5].modSpatack = natures[5].modSpdef = natures[5].modSpeed = comum;
        natures[6].modDef = mais;
            natures[6].modAtk = menos;
                natures[6].modSpdef = natures[6].modSpatack = natures[6].modSpeed = comum;
        natures[7].modSpatack = mais;
            natures[7].modAtk = menos;
                natures[7].modSpdef = natures[7].modDef = natures[7].modSpeed = comum;
        natures[8].modSpdef = mais;
            natures[8].modAtk = menos;
                natures[8].modDef = natures[8].modSpatack = natures[8].modSpeed = comum;
        natures[9].modSpeed = mais;
            natures[9].modAtk = menos;
                natures[9].modSpdef = natures[9].modSpatack = natures[9].modDef = comum;
        natures[10].modAtk = mais;
            natures[10].modDef = menos;
                natures[10].modSpdef = natures[10].modSpatack = natures[10].modSpeed = comum;       
        natures[11].modSpatack = mais;
            natures[11].modDef = menos;
                natures[11].modSpdef = natures[11].modAtk = natures[11].modSpeed = comum;
        natures[12].modSpdef = mais;
            natures[12].modDef = menos;
                natures[12].modAtk = natures[12].modSpatack = natures[12].modSpeed = comum;
        natures[13].modSpeed = mais;
            natures[13].modDef = menos;
                natures[13].modSpdef = natures[13].modSpatack = natures[13].modAtk = comum;
        natures[14].modAtk = mais;
            natures[14].modSpatack = menos;
                natures[14].modSpdef = natures[14].modDef = natures[14].modSpeed = comum;
        natures[15].modDef = mais;
            natures[15].modSpatack = menos;
                natures[15].modSpdef = natures[15].modAtk = natures[15].modSpeed = comum;
        natures[16].modSpdef = mais;
            natures[16].modSpatack = menos;
                natures[16].modDef = natures[16].modAtk = natures[16].modSpeed = comum;
        natures[17].modSpeed = mais;
            natures[17].modSpatack = menos;
                natures[17].modSpdef = natures[17].modAtk = natures[17].modDef = comum;
        natures[18].modAtk = mais;
            natures[18].modSpdef = menos;
                natures[18].modDef = natures[18].modSpatack = natures[18].modSpeed = comum;
        natures[19].modDef = mais;
            natures[19].modSpdef = menos;
                natures[19].modAtk = natures[19].modSpatack = natures[19].modSpeed = comum;
        natures[20].modSpatack = mais;
            natures[20].modSpdef = menos;
                natures[20].modAtk = natures[20].modDef = natures[20].modSpeed = comum;
        natures[21].modSpeed = mais;
            natures[21].modSpdef = menos;
                natures[21].modAtk = natures[21].modDef = natures[21].modSpatack = comum;
        natures[22].modAtk = mais;
            natures[22].modSpeed = menos;
                natures[22].modSpdef = natures[22].modSpatack = natures[22].modDef = comum;
        natures[23].modDef = mais;
            natures[23].modSpeed = menos;
                natures[23].modSpdef = natures[23].modSpatack = natures[23].modAtk = comum;
        natures[24].modSpatack = mais;
            natures[24].modSpeed = menos;
                natures[24].modSpdef = natures[24].modAtk = natures[24].modDef = comum;
        natures[25].modSpdef = mais;
            natures[25].modSpeed = menos;
                natures[25].modAtk = natures[25].modSpatack = natures[25].modDef = comum;
}

void vetorDePokebolas(struct Pokebola pokebolas[4]) {

    //Define as pokébolas e seus Catch

    strcpy(pokebolas[0].nome, "Pokebola");
    strcpy(pokebolas[1].nome, "Grande Bola");
    strcpy(pokebolas[2].nome, "Ultra Bola");
    strcpy(pokebolas[3].nome, "Bola mestre");

    pokebolas[0].catchRate = 1;
    pokebolas[1].catchRate = 1.5;
    pokebolas[2].catchRate = 2;
    pokebolas[3].catchRate = 10000;
}

/*void vetorDeTiposDePokemon(struct Tipos tipos[18]) {

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
    tipos[i].idTipo = i;
}

// Tipo inseto
int fraq[] = {2, 7, 15};
int res[] = {13, 14, 16};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[0].fraquezas[i] = fraq[i];
    tipos[0].resistencias[i] = res[i];
    tipos[0].imunidades[i] = imuni[i];
};

// Tipo normal
int fraq[] = {16};
int res[] = {};
int imuni[] = {16};
for (int i = 0; i < 8; i++) {
    tipos[1].fraquezas[i] = fraq[i];
    tipos[1].resistencias[i] = res[i];
    tipos[1].imunidades[i] = imuni[i];
};

// Tipo fogo
int fraq[] = {14, 15, 3};
int res[] = {2, 12, 0, 13, 8, 17};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[2].fraquezas[i] = fraq[i];
    tipos[2].resistencias[i] = res[i];
    tipos[2].imunidades[i] = imuni[i];
};

// Tipo agua
int fraq[] = {13, 6};
int res[] = {17, 8, 2, 3};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[3].fraquezas[i] = fraq[i];
    tipos[3].resistencias[i] = res[i];
    tipos[3].imunidades[i] = imuni[i];
};

// Tipo dragao
int fraq[] = {4, 8, 12};
int res[] = {13, 6, 2, 3};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[4].fraquezas[i] = fraq[i];
    tipos[4].resistencias[i] = res[i];
    tipos[4].imunidades[i] = imuni[i];
};

// Tipo venenoso
int fraq[] = {9, 14};
int res[] = {0, 5, 16, 13, 12};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[5].fraquezas[i] = fraq[i];
    tipos[5].resistencias[i] = res[i];
    tipos[5].imunidades[i] = imuni[i];
};

// Tipo Elétrico
int fraq[] = {14};
int res[] = {17, 7};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[6].fraquezas[i] = fraq[i];
    tipos[6].resistencias[i] = res[i];
    tipos[6].imunidades[i] = imuni[i];
};

// Tipo Voador
int fraq[] = {6, 8, 15};
int res[] = {0, 13, 16};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[7].fraquezas[i] = fraq[i];
    tipos[7].resistencias[i] = res[i];
    tipos[7].imunidades[i] = imuni[i];
};

// Tipo Gelo
int res[] = {6, 8, 15};
int fraq[] = {2,16, 15, 17};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[8].fraquezas[i] = fraq[i];
    tipos[8].resistencias[i] = res[i];
    tipos[8].imunidades[i] = imuni[i];
};

// Tipo Psíquico
int fraq[] = {0, 10, 11};
int res[] = {9, 16};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[9].fraquezas[i] = fraq[i];
    tipos[9].resistencias[i] = res[i];
    tipos[9].imunidades[i] = imuni[i];
};

// Tipo Obscuro
int fraq[] = {0, 7, 16};
int res[] = {10, 11};
int imuni[] = {9};
for (int i = 0; i < 8; i++) {
    tipos[10].fraquezas[i] = fraq[i];
    tipos[10].resistencias[i] = res[i];
    tipos[10].imunidades[i] = imuni[i];
};

// Tipo Fantasma
int fraq[] = {10, 11};
int res[] = {0, 5};
int imuni[] = {1, 16};
for (int i = 0; i < 8; i++) {
    tipos[11].fraquezas[i] = fraq[i];
    tipos[11].resistencias[i] = res[i];
    tipos[11].imunidades[i] = imuni[i];
};

// Tipo Fada
int fraq[] = {5, 17};
int res[] = {0, 16, 10};
int imuni[] = {4};
for (int i = 0; i < 8; i++) {
    tipos[12].fraquezas[i] = fraq[i];
    tipos[12].resistencias[i] = res[i];
    tipos[12].imunidades[i] = imuni[i];
};

// Tipo Planta
int fraq[] = {0, 2, 5, 8, 7};
int res[] = {13, 3, 6, 14};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[13].fraquezas[i] = fraq[i];
    tipos[13].resistencias[i] = res[i];
    tipos[13].imunidades[i] = imuni[i];
};

// Tipo Terra
int fraq[] = {3, 8, 13};
int res[] = {5, 6, 15};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[14].fraquezas[i] = fraq[i];
    tipos[14].resistencias[i] = res[i];
    tipos[14].imunidades[i] = imuni[i];
};

// Tipo Pedra
int fraq[] = {17, 3, 16, 14, 13};
int res[] = {1, 2, 5, 7};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[15].fraquezas[i] = fraq[i];
    tipos[15].resistencias[i] = res[i];
    tipos[15].imunidades[i] = imuni[i];
};

// Tipo Lutador
int fraq[] = {7, 9, 13};
int res[] = {15, 0, 10};
int imuni[] = {};
for (int i = 0; i < 8; i++) {
    tipos[16].fraquezas[i] = fraq[i];
    tipos[16].resistencias[i] = res[i];
    tipos[16].imunidades[i] = imuni[i];
};

// Tipo Aço
int fraq[] = {16, 2, 14};
int res[] = {0, 7, 8, 1, 4, 9, 12, 17, 15, 13};
int imuni[] = {5};
for (int i = 0; i < 8; i++) {
    tipos[17].fraquezas[i] = fraq[i];
    tipos[17].resistencias[i] = res[i];
    tipos[17].imunidades[i] = imuni[i];
};


}
*/
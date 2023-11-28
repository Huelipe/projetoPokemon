#include "estruturas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//void vetorDeTiposDePokemon(struct Tipos tipos[18]) {

/*strcpy(tipos[0].nome, "Inseto");
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
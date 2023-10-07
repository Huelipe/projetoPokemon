#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

typedef struct Pokemon{
    int nPokedex; // Número na pokedex
    char nome[40]; // Nome do pokémon
    char tipo1[10]; // Primeiro tipo do pokémon
    char tipo2[10]; // Segundo tipo do pokémon (deve ser registrado "NULL" caso não tenha)
    int total; // Soma total dos status base
    int hp; // Tanto de vida
    int atk; // Tanto de ataque
    int def; // Tanto de defesa
    int spatack; // Tanto de ataque especial
    int spdef; // Tanto de defesa especial
    int speed; // Tanto de velocidade
    int geracao; // Geração a qual pertence o pokemon
    int lendario; // Define se é lendario ou não a partir de booleano
    char cor[10]; // Cor do pokemon
    float altura; // Altura do pokemon
    float peso; // Peso do pokemon
    float captura; // Taxa de captura
    int preEvo; // Pré evolução
    int prxEvo; // Próxima evolução
    int lvlAtual; // Level atual
    char move1[20]; // Ataque 1
    char move2[20]; // Ataque 2
    char move3[20]; // Ataque 3
    char move4[20]; // Ataque 4
} Pokemon;

#define MAX_POKEMON 722 

typedef struct Pokebola{
float catchRate;
char nome[20];
int id;
} Pokebola;

void capturarPokemon(int idPokebola, float taxaCaptura, int* resultado){
// Ao apertar o botão de tentar capturar
// (( 1 + ( MaxHP x 3 - HP atual x 2 ) x catch rate do pokémon x catch rate da pokéball x status ) / ( MaxHP x 3 )) / 256

float chance = 1 + ();

    return;
}

int main(){



    FILE *arquivo;
    char linha[512]; 
    Pokemon listaPokemon[MAX_POKEMON];
    int contador = 0;

    arquivo = fopen("C:/Users/Huelipe/Documents/GitHub/projetoPokemon/pokedex.csv", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        char *token = strtok(linha, ",");
        if (token != NULL) {
            listaPokemon[contador].nPokedex = atoi(token);
            token = strtok(NULL, ",");
            if (token != NULL) {
                strncpy(listaPokemon[contador].nome, token, sizeof(listaPokemon[contador].nome));
                token = strtok(NULL, ",");
                if (token != NULL) {
                    strncpy(listaPokemon[contador].tipo1, token, sizeof(listaPokemon[contador].tipo1));
                    token = strtok(NULL, ",");
                    if (token != NULL) {
                        strncpy(listaPokemon[contador].tipo2, token, sizeof(listaPokemon[contador].tipo2));
                        token = strtok(NULL, ",");
                        if (token != NULL) {
                            listaPokemon[contador].total = atoi(token);
                            token = strtok(NULL, ",");
                            if (token != NULL) {
                                listaPokemon[contador].hp = atoi(token);
                                token = strtok(NULL, ",");
                                if (token != NULL) {
                                    listaPokemon[contador].atk = atoi(token);
                                    token = strtok(NULL, ",");
                                    if (token != NULL) {
                                        listaPokemon[contador].def = atoi(token);
                                        token = strtok(NULL, ",");
                                        if (token != NULL) {
                                            listaPokemon[contador].spatack = atoi(token);
                                            token = strtok(NULL, ",");
                                            if (token != NULL) {
                                                listaPokemon[contador].spdef = atoi(token);
                                                token = strtok(NULL, ",");
                                                if (token != NULL) {
                                                    listaPokemon[contador].speed = atoi(token);
                                                    token = strtok(NULL, ",");
                                                    if (token != NULL) {
                                                        listaPokemon[contador].geracao = atoi(token);
                                                        token = strtok(NULL, ",");
                                                        if (token != NULL) {
                                                            listaPokemon[contador].lendario = atoi(token);
                                                            token = strtok(NULL, ",");
                                                            if (token != NULL) {
                                                                strncpy(listaPokemon[contador].cor, token, sizeof(listaPokemon[contador].cor));
                                                                token = strtok(NULL, ",");
                                                                if (token != NULL) {
                                                                    listaPokemon[contador].altura = atof(token);
                                                                    token = strtok(NULL, ",");
                                                                    if (token != NULL) {
                                                                        listaPokemon[contador].peso = atof(token);
                                                                        token = strtok(NULL, ",");
                                                                        if (token != NULL) {
                                                                            listaPokemon[contador].captura = atoi(token);
                                                                            token = strtok(NULL, ",");
                                                                            if (token != NULL) {
                                                                                listaPokemon[contador].preEvo = atoi(token);
                                                                                token = strtok(NULL, ",");
                                                                                if (token != NULL) {
                                                                                    listaPokemon[contador].prxEvo = atoi(token);
                                                                                    // Continue para os outros campos da estrutura...
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        contador++;
    }
    fclose(arquivo);

    printf("Nome: %s\n", listaPokemon[6].nome);
    printf("HP: %i\n", listaPokemon[6].hp);
    printf("ATK: %i\n", listaPokemon[6].atk);
    printf("DEF: %i\n", listaPokemon[6].def);
    printf("ATK.SP: %i\n", listaPokemon[6].spatack);
    printf("DEF.SP: %i\n", listaPokemon[6].spdef);
    printf("Speed: %i\n", listaPokemon[6].speed);



    Pokemon mochila[6];


    return 0;
}
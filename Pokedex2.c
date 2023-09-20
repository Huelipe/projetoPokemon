#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

typedef struct Pokemon{
    int nPokedex; // Número na pokedex
    char nome[40]; // Nome do pokémon
    char tipo1[10]; // Primeiro tipo do pokémon
    char tipo2[10]; // Segundo tipo do pokémon (dever ser registrado "NULL" caso não tenha)
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
    int captura; // Taxa de captura
    int preEvo; // Pré evolução
    int prxEvo; // Próxima evolução
} Pokemon;

#define MAX_POKEMON 722 

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
            }
        }
        contador++;
    }
    fclose(arquivo);

printf("%s\n", listaPokemon[6].nome);
    printf("HP: %i\n", listaPokemon[6].hp);
        printf("ATK: %i\n", listaPokemon[6].atk);
            printf("DEF: %i\n", listaPokemon[6].def);
                printf("ATK.SP: %i\n", listaPokemon[6].spatack);
                    printf("DEF.SP: %i\n", listaPokemon[6].spdef);
                        printf("Speed: %i\n", listaPokemon[6].speed);

    return 0;
}







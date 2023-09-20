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

#define MAX_POKEMON 722 // Defina o tamanho máximo da lista de Pokémon

int main() {
    FILE *arquivo;
    char linha[512]; // Assuma que as linhas do arquivo CSV têm no máximo 512 caracteres
    Pokemon listaPokemon[MAX_POKEMON]; // Armazena os Pokémon lidos do arquivo CSV
    int contador = 0; // Contador para rastrear o número de Pokémon lidos

    arquivo = fopen("C:/Users/Huelipe/Documents/GitHub/projetoPokemon/pokedex.csv", "r"); // Substitua pelo caminho correto do seu arquivo CSV

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        // Use strtok ou sscanf para extrair os valores da linha
        char *token = strtok(linha, ",");
        if (token != NULL) {
            listaPokemon[contador].nPokedex = atoi(token);
            // Repita para os outros membros da estrutura, seguindo a ordem dos campos no arquivo CSV
            token = strtok(NULL, ",");
            if (token != NULL) {
                strncpy(listaPokemon[contador].nome, token, sizeof(listaPokemon[contador].nome));
            }
            // Continue para os outros membros...
        }
        // Incrementa o contador
        contador++;
    }
    fclose(arquivo);

    printf("%s", listaPokemon[151].nome);

    return 0;
}







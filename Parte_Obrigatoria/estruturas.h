#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

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
} Pokemon; // Estrutura que define o pokemon na pokedex

typedef struct Dados{  
    int totalMochila;
    int numeroDePokemons;
    int totalPokesNaColecao;
} Dados;

typedef struct Pokebola{
float catchRate;
char nome[20];
} Pokebola;

typedef struct natureza{
char nome[20];
float modAtk;
float modDef;
float modSpatack;
float modSpdef;
float modSpeed;
} nature;

typedef struct Colecao{
int numDoPokemon;
} Colecao;

typedef struct{
    int IdPokeMochila;
}Mochila;

#endif
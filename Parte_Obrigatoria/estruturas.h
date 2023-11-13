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
    int preEvo; // Pré evolução
    int prxEvo; // Próxima evolução
} Pokemon; // Estrutura que define o pokemon na pokedex

typedef struct PokemonCapturado{
    float ivsHP; 
    float ivsAtk;
    float ivsDef;
    float ivsSpatack;
    float ivsSpDef;
    float ivsSpeed;
    float evsHP;
    float evsAtk;
    float evsDef;
    float evsSpatack;
    float evsSpDef;
    float evsSpeed;
    float evstotal; 
    float HP;
    float HPATUAL;
    float Atk;
    float Def;
    float Spatack;
    float SpDef;
    float Speed;
    float LvlAtual; // Level atual
    char move1[20]; // Ataque 1
    char move2[20]; // Ataque 2
    char move3[20]; // Ataque 3
    char move4[20]; // Ataque 4
    char nature[20];
    union{
        char tipo[10];
        int id;
        float atual; // (1 ou 10), (esta com status ou não)
    } Status;
    // Union para definir se um pokémon está paralisado, intoxicado, com sono ou congelado, condições que facilitam na batalha e a capturar
} pokemonCapturado;

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

/*typedef struct tipos{
int idTipo;
char nome[10];
int resistencias[8];
int fraquezas[8];
int imunidades[3];
} tipos;
*/




#endif
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
} Pokemon;

typedef struct PokemonCapturado{
    char apelido[30];
    int ivsHP;
    int ivsAtk;
    int ivsDef;
    int ivsSpatack;
    int ivsSpDef;
    int ivsSpeed;
    int evsHP;
    int evsAtk;
    int evsDef;
    int evsSpatack;
    int evsSpDef;
    int evsSpeed;
    int HP;
    int HPFULL;
    int Atk;
    int Def;
    int Spatack;
    int SpDef;
    int Speed;
    int LvlAtual; // Level atual
    char move1[20]; // Ataque 1
    char move2[20]; // Ataque 2
    char move3[20]; // Ataque 3
    char move4[20]; // Ataque 4
    char nature[20];
    union{
        char tipo[10];
        int id;
        int status; // (1 ou 10), (esta com status ou não)
    } Status;
} pokemonCapturado;
#define MAX_POKEMON 722 

typedef struct Pokebola{
float catchRate;
char nome[20];
int id;
} Pokebola;

typedef struct natureza{
char nome[20];
float modAtk;
float modDef;
float modSpatack;
float modSpdef;
float modSpeed;
} nature;

void criarPokemon(Pokemon pokemonNaDex, pokemonCapturado pselvagem, int lvl){

    pselvagem.ivsHP = rand() % 31;
    pselvagem.ivsAtk = rand() % 31;
    pselvagem.ivsDef = rand() % 31;
    pselvagem.ivsSpatack = rand() % 31;
    pselvagem.ivsSpDef = rand() % 31;
    pselvagem.ivsSpeed = rand() % 31;

    pselvagem.LvlAtual = lvl;

    pselvagem.evsHP = 0;
    pselvagem.evsAtk = 0;
    pselvagem.evsDef = 0;
    pselvagem.evsSpatack = 0;
    pselvagem.evsSpDef = 0;
    pselvagem.evsSpeed = 0;

    pselvagem.HP = ((pselvagem.LvlAtual * ((pokemonNaDex.hp x 2) + pselvagem.ivsHP + (pselvagem.evsHP / 4))) / 100) + 10 + pselvagem.LvlAtual;
    pselvagem.Atk = (((pselvagem.LvlAtual * ((pokemonNaDex.atk x 2) + pselvagem.ivsAtk + (pselvagem.evsAtk/4))) / 100) + 5) * /*nature*/;


}

void capturarPokemon(int idPokebola, float taxaCaptura, int* resultado){
// Ao apertar o botão de tentar capturar
//float chance =  (( 1 + (pokemonSelvagem.HPFULL - pokemonSelvagem.HP * 2 ) * pokemon.captura * pokebola.catchRate * pokemonSelvagem.Status.status) / (pokemonSelvagem.HPFULL x 3 )) / 256

/*float numSorteado = (rand() % 100);

if(numSorteado >= chance){
    resultado = 1;
}else{
    resultado = 0;
}
*/
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

    nature natures[25];
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
                natures[20].modAtk = natures[20].modAtk = natures[20].modSpeed = comum;
        natures[21].modSpeed = mais;
            natures[21].modSpdef = menos;
                natures[21].modAtk = natures[21].modAtk = natures[21].modSpatack = comum;
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

    printf("Digite o nome do pokemon que você está batalhando!");
    char nome[40];
    setbuf(stdin, NULL);
    fgets(nome, 39, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    Pokemon selvagagemNaDex;
    pokemonCapturado selvagem;

    for(int i = 0; i++; i < 722){
        if(strcmp(nome, listaPokemon[i].nome) == 0){

        }
    }

    return 0;
}
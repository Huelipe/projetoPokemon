#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

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
// Ponto 1

typedef struct PokemonCapturado{
    char apelido[30]; // Cada pokémon pode ter um apelido, definido pelo dano após capturar
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
    float HPFULL;
    float HPATUAL;
    float Atk;
    float Def;
    float Spatack;
    float SpDef;
    float Speed;
    float LvlAtual; // Level atual
    char nature[20];
    union{
        char tipo[10];
        int id;
        float atual; // (1 ou 10), (esta com status ou não)
    } Status;
    // Union para definir se um pokémon está paralisado, intoxicado, com sono ou congelado, condições que facilitam na batalha e a capturar
} pokemonCapturado;
// Vai ser utilizado para a mochila

typedef struct natureza{
char nome[20];
float modAtk;
float modDef;
float modSpatack;
float modSpdef;
float modSpeed;
} nature;
// Vai ser utilizado para criar um Pokemon

void criarPokemon(Pokemon pokemonNaDex, pokemonCapturado* pselvagem, int lvl, nature natures[25]) {

    /*
    O Código a seguir cria e randomiza um pokemon
    As ivs do pokemon são aleatorizadas de 0 a 31 e seu lvl é recebido pela função, pois cada área vai ser um nivel maior
    A natureza também é randomizada e zera suas evs
    */

    pselvagem->ivsHP = rand() % 32;
    pselvagem->ivsAtk = rand() % 32;
    pselvagem->ivsDef = rand() % 32;
    pselvagem->ivsSpatack = rand() % 32;
    pselvagem->ivsSpDef = rand() % 32;
    pselvagem->ivsSpeed = rand() % 32;

    pselvagem->LvlAtual = lvl;

    int r = rand() % 26; // randomizador nature
    char nature[20];
    strcpy(nature, natures[r].nome);

    pselvagem->evsHP = 0;
    pselvagem->evsAtk = 0;
    pselvagem->evsDef = 0;
    pselvagem->evsSpatack = 0;
    pselvagem->evsSpDef = 0;
    pselvagem->evsSpeed = 0;

    /*
    Aqui a magia acontece, finalmente os numeros são definidos através dessas formulas tiradas da net
    A vida total do pokemon, seria definida nessa primeira linha ai, utilizando evs, ivs, nvl e etc
    As outras linhas tem um adendo que é o modficador da natureza
    */
    pselvagem->HP = ((pselvagem->LvlAtual * ((pokemonNaDex.hp * 2) + pselvagem->ivsHP + (pselvagem->evsHP / 4))) / 100) + 10 + pselvagem->LvlAtual;
    pselvagem->Atk = (((pselvagem->LvlAtual * ((pokemonNaDex.atk * 2) + pselvagem->ivsAtk + (pselvagem->evsAtk / 4))) / 100) + 5) * natures[r].modAtk;
    pselvagem->Def = (((pselvagem->LvlAtual * ((pokemonNaDex.def * 2) + pselvagem->ivsDef + (pselvagem->evsDef / 4))) / 100) + 5) * natures[r].modDef;
    pselvagem->Spatack = (((pselvagem->LvlAtual * ((pokemonNaDex.spatack * 2) + pselvagem->ivsSpatack + (pselvagem->evsSpatack / 4))) / 100) + 5) * natures[r].modSpatack;
    pselvagem->SpDef = (((pselvagem->LvlAtual * ((pokemonNaDex.spdef * 2) + pselvagem->ivsSpDef + (pselvagem->evsSpDef / 4))) / 100) + 5) * natures[r].modSpdef;
    pselvagem->Speed = (((pselvagem->LvlAtual * ((pokemonNaDex.speed * 2) + pselvagem->ivsSpeed + (pselvagem->evsSpeed / 4))) / 100) + 5) * natures[r].modSpeed;

    pselvagem->HPFULL = pselvagem->HP;
    pselvagem->HPATUAL = pselvagem->HP;
    // HP atual e HP full tão assim aqui só pra testes, tem de ser feito um sistema pra reduzir o hp atual

    pselvagem->Status.atual = 1;
}
// Cria um pokémon que pode ser capturado

int main(){

    int MAX_POKEMON = 722;

    srand(time(NULL));
    // Código necessário para funcionamento do randomizador

    FILE *arquivo;
    Pokemon listaPokemon[MAX_POKEMON];
    int tamanhoPrimeiraLinhaCSV;

    arquivo = fopen("../pokedex.csv", "r+");
    // Sugiro que mudem isso aqui para o caminho .csv no computador de vocês, por enquanto

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    tamanhoPrimeiraLinhaCSV = sizeof("numero ,nome        ,tipo1    ,tipo2    ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura");

    fseek(arquivo, tamanhoPrimeiraLinhaCSV, SEEK_SET);

    for(int i = 1; i < 722; i++){
        fscanf(arquivo, "%d ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%s ,%f ,%f ,%f \n", &listaPokemon[i].nPokedex, listaPokemon[i].nome, listaPokemon[i].tipo1, listaPokemon[i].tipo2, &listaPokemon[i].total, &listaPokemon[i].hp, &listaPokemon[i].atk, &listaPokemon[i].def, &listaPokemon[i].spatack, &listaPokemon[i].spdef, &listaPokemon[i].speed, &listaPokemon[i].geracao, &listaPokemon[i].lendario, listaPokemon[i].cor, &listaPokemon[i].altura, &listaPokemon[i].peso, &listaPokemon[i].captura);
    }//for

    fclose(arquivo);

 nature natures[26];
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

    /*
    Os próximos 3 floats são valores para multiplicar
    A nature timid, por exemplo, define que o modificado de Speed é = mais e o atack = menos
    Isso quer dizer que, quando criar um pokemon, sua speed vai ter um valor de modificar *1.1 e o atack * 0.9
    Ou seja, o pokemon vai ter mais 10% de speed e -10% de atack, assim como na tabela
    O float comum define que os outros atributos não serão modificados, assim, na criação de pokemon, vai multiplicar por 1, deixando inalteravel 
    As 5 primeiras linhas definem as 5 naturezas que não mudam nada, as outras, as naturezas que aumentam um valor e diminuem outra
    */
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
	// Define as naturezas que são necessárias para aleatorizar os pokemons


	pokemonCapturado pokemons[1000];

	printf("Menu");
	int opção
	/*
	Mochila // max 6
	Q
	> Excluir pokemon
	W
	> Adicionar pokemon 
	Coleção // max 1000
	> Adicionar pokemon
	> Excluir pokemon
	// Max 1000
	Visualizar Pokedex
	> Ver Pokemons
	> Gerenciar Pokedex
		> Adicionar pokemon
			pedir nome
			pedir a poha toda
			MAX_POKEMON++;
 			
			
		> Excluir pokemon
			MAX_POKEMON--;

	// Exportar dados para .csv
	// Salvar em binário
	// Sair do jogo

*/

}


/*
    printf("Digite o nome do pokemon que você quer adicionar na mochila: ");
    char nome[13];
    setbuf(stdin, NULL);
    fgets(nome, 12, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    Pokemon selvagagemNaDex;

    for(int i = 1; i < 722; i++){
        if(strcasecmp(nome, listaPokemon[i].nome) == 0){
        printf("Nome do Pokémon encontrado: %s\n", listaPokemon[i].nome);
        selvagagemNaDex = listaPokemon[i];
        break;
        }
    }

    pokemonCapturado pselvagem;
 
   int nivel;
   printf(digite o nivel dele:);
   scanf("%i", &nivel);

    criarPokemon(selvagagemNaDex, &pselvagem, 10, natures);

    exibir pokemons?
    printf(%i, pokemonCapturado.nome);
*/ // Adicionar pokemons na mochila e pra coleção

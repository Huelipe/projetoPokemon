#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*

typedef struct PokemonCapturado{
    char apelido[30]; // Cada pokémon pode ter um apelido, definido pelo dano após capturar
    float ivsHP; 
    float ivsAtk;
    float ivsDef;
    float ivsSpatack;
    float ivsSpDef;
    float ivsSpeed;
    // As ivs são valores que vão de 0 a 31, esse valor é somado ao atributo respectivo do pokémon
    // Por exemplo: Um pokemon com 31 de ivs em Atack vai ter +31 de atack, enquanto um com 0 de ivs, não vai ter nada adicional
    // Isso define, por exemplo, como um pikachu lvl 10 pode ser mais rapido que outro pikachu também nivel 10, é a mesma especie mas sempre há um melhor
    float evsHP;
    float evsAtk;
    float evsDef;
    float evsSpatack;
    float evsSpDef;
    float evsSpeed;
    float evstotal;
    */

   /*
    As evs são valores que vão de 0 a 252, esse valor é dividido por 4 e depois também somado ao atributo respectivo do pokémon
    Todos os pokémons capturados vem com suas EVs zeradas, para ganhar EVs, os pokémons poderão comer as frutas que discutimos ou ganhar em batalha
    No sistema original, um pokemon ganharia as evs em batalha dependendo do pokemon que estivesse contra, por exemplo:
    Ao batalhar contra um pikachu, o pokémon ganharia EVs de speed, pois o atributo mais alto do pikachu é a velocidade, ou seja, o pokémon estaria treinando a sua velocidade
    Então aumentar evs de pokémon é algo que temos definir como fazer, mas é como levar o pokémon pra academia
    Obs: Cada evs pode ir de 0 a 252, mas, um pokemon pode ter, no maximo, somando todas, 508 evs
    Então só da pra maximizar 2 evs e colocar mais uns 4 pontos em qualquer outra (para competitivo)
    
    float HP;
    float HPFULL;
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
*/


/*
#define MAX_POKEMON 722 

typedef struct Pokebola{
float catchRate;
char nome[20];
} Pokebola;
// Estrutura da pokebola, vai ter seu nome e taxa de captura

typedef struct natureza{
char nome[20];
float modAtk;
float modDef;
float modSpatack;
float modSpdef;
float modSpeed;
} nature;
// Estrutura da natureza, explicadas na linha 279 mais ou menos

*/

/*
void criarPokemon(Pokemon pokemonNaDex, pokemonCapturado* pselvagem, int lvl, nature natures[25]) {

    O Código a seguir cria e randomiza um pokemon
    As ivs do pokemon são aleatorizadas de 0 a 31 e seu lvl é recebido pela função, pois cada área vai ser um nivel maior
    A natureza também é randomizada e zera suas evs
    


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

*/    

    /*
    Aqui a magia acontece, finalmente os numeros são definidos através dessas formulas tiradas da net
    A vida total do pokemon, seria definida nessa primeira linha ai, utilizando evs, ivs, nvl e etc
    As outras linhas tem um adendo que é o modficador da natureza
    
   
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
*/

/*
void capturarPokemon(Pokebola pokeball[4], int* resultado, Pokemon pokemonNaDex, pokemonCapturado pselvagem, int qualpokebola){
// Ao apertar o botão de tentar capturar

float chance;

    chance = ((1 + (3 * pselvagem.HPFULL - (2 * pselvagem.HPATUAL)) * (pokemonNaDex.captura * pokeball[qualpokebola].catchRate * pselvagem.Status.atual)) / (3 * pselvagem.HPFULL)) / 2.56;
    // Aqui é feita a tentativa de capturar um pokémon (formula retirada da internet)
    printf("%.5f\n", chance);

float numSorteado = (rand() % 100) + 1;
// A linha acima define um numero de 0 a 100, se o numero for menor que a chance calculada, você captura o pokemon
// Por exemplo, a chance é de 40%, se o numero sorteado foi 40 ou menor você captura, pois a chance de tirar um numero 40 ou menor de 0 a 100 é 40% também

// printf("%.0f\n", numSorteado);

if(numSorteado <= chance){
    (*resultado) = 1;
}else{
    (*resultado) = 0;
}
}
*/

/*
int Listagem(){

    srand(time(NULL));
    // Código necessário para funcionamento do randomizador

    FILE *arquivo;
    char linha[512]; 
    Pokemon listaPokemon[MAX_POKEMON];
    int contador = 0;

    arquivo = fopen("../pokedex.csv", "r+");
    // Sugiro que mudem isso aqui para o caminho .csv no computador de vocês, por enquanto

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

*/


/*
    printf("Nome: %s\n", listaPokemon[6].nome);
    printf("HP: %i\n", listaPokemon[6].hp);
    printf("ATK: %i\n", listaPokemon[6].atk);
    printf("DEF: %i\n", listaPokemon[6].def);
    printf("ATK.SP: %i\n", listaPokemon[6].spatack);
    printf("DEF.SP: %i\n", listaPokemon[6].spdef);
    printf("Speed: %i\n", listaPokemon[6].speed);
    printf("Speed: %i\n", listaPokemon[6].captura);
    // Exemplo de comandos pra ver se ta tudo certin

    
    O parte a seguir que vai até a linha 393 mais ou menos define as naturezas do pokémon
    Como dito anteriormente, um pokemon tem HP, atack, defesa, atack especial, defesa especial e velocidade
    Existe uma tabela que define 25 naturezas, que definem que um pokémon pode ser melhor em um atributo X e pior em um atributo Y
    Por exemplo, a nature "Timid", listada na posição 10 ("9") do vetor faz com que o pokémon tenha 10% a mais de velocidade, mas, em compensação, -10% de atack
    As 5 primeiras naturezas não mudam absolutamente nada no pokemon
    Eis um link com a tabela: https://aminoapps.com/c/pokemon-amino-ptbr/page/blog/natures-certas-para-os-pokemons/wPkB_rMIourbDLoV3Z8Vk3JXvMx5R172xG
    Obs: Nenhuma natureza interfere no HP do pokemon, apenas nos outros 5 atributos
    */


/*
    //Aqui temos um vetor de tamanho 25 com o nome das 25 natures de acordo com a tabela
    
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

*/    

    /*
    Os próximos 3 floats são valores para multiplicar
    A nature timid, por exemplo, define que o modificado de Speed é = mais e o atack = menos
    Isso quer dizer que, quando criar um pokemon, sua speed vai ter um valor de modificar *1.1 e o atack * 0.9
    Ou seja, o pokemon vai ter mais 10% de speed e -10% de atack, assim como na tabela
    O float comum define que os outros atributos não serão modificados, assim, na criação de pokemon, vai multiplicar por 1, deixando inalteravel 
    As 5 primeiras linhas definem as 5 naturezas que não mudam nada, as outras, as naturezas que aumentam um valor e diminuem outra
    */
   /*
    float comum = 1;
    float mais = 1.1;
    float menos = 0.9;
*/
/*
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

    Pokebola pokebolas[4];
    strcpy(pokebolas[0].nome, "Pokebola");
    strcpy(pokebolas[1].nome, "Grande Bola");
    strcpy(pokebolas[2].nome, "Ultra Bola");
    strcpy(pokebolas[3].nome, "Bola mestre");
    */
    /*
    Aqui defino as 4 pokebolas mais comuns do jogo, cada pokebola tem um nome e um catch rate
    A bola mestre tem 100% de chance de captura, por isso seu modificador é 10 mil, mas podemos mudar pra simplesmente um if
    */

/*
    pokebolas[0].catchRate = 1;
    pokebolas[1].catchRate = 1.5;
    pokebolas[2].catchRate = 2;
    pokebolas[3].catchRate = 10000;

    printf("Digite o nome do pokemon que você está batalhando: ");
    char nome[40];
    setbuf(stdin, NULL);
    fgets(nome, 39, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    */
    /*
    Aqui é o começo de um código pra ver se ta tudo certo
    Você digita o nome de um pokemon, ele vai buscar na lista do .csv e pegar os atributos e salvar em selvagemNaDex
    Obs: O código está com erro ao buscar o nome do pokemon porque salvou as barras de espaço
    Então, para testar por enquanto, conte quantas letras tem no nome do pokemon, subtraia de 12
    dai por exemplo charizard tem 9 letras, 12-9 = 3
    Digita charizard e da 3 barras de espaço e vai funcionar
    */

/*
    Pokemon selvagagemNaDex;

    for(int i = 1; i < 722; i++){
        if(strcasecmp(nome, listaPokemon[i].nome) == 0){
        selvagagemNaDex = listaPokemon[i];
        }
    }

    printf("Pokebola que vai utilizar: ");
    char pokebola[20];
    setbuf(stdin, NULL);
    fgets(pokebola, 19, stdin);
    pokebola[strcspn(pokebola, "\n")] = '\0';
    // Aqui digita qual pokebola vai utilizar para tentar capturar

    int qualPokebola;

    if(strcmp(pokebola, "Pokebola") == 0 || strcmp(pokebola, "pokebola") == 0){
        qualPokebola = 0;
    }else if(strcmp(pokebola, "Grande Bola") == 0 || strcmp(pokebola, "grande bola") == 0){
        qualPokebola = 1;
    }else if(strcmp(pokebola, "Ultra Bola") == 0 || strcmp(pokebola, "ultra bola") == 0){
        qualPokebola = 2;
    }else if(strcmp(pokebola, "Bola Mestre") == 0 || strcmp(pokebola, "bola mestre") == 0){
        qualPokebola = 3;
    }
    // Aqui define o valor da pokebola

    int resultado;

    pokemonCapturado pselvagem;

    criarPokemon(selvagagemNaDex, &pselvagem, 10, natures);
    // Cria o pokemon nvl 10 com o código

    capturarPokemon(pokebolas, &resultado, selvagagemNaDex, pselvagem, qualPokebola);
    // Tenta capturar um pokemon 

    if(resultado == 1){
        printf("Parabéns, você capturou o pokémon!\n");
    }else{
        printf("Que pena! Você não conseguiu\n");
    }
    // Retorna o resultado

    

    return 0;
}
*/

//COMECEI A PARTIR DAQUI AMIGOS

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

typedef struct Colecao{
int totalPokemons;    
int *numDoPokemon;
} Colecao;

typedef struct{
    int totalPokemons;
    int idPokeMochila[6];
}Mochila;

void adicionarPokemonNaColecao(Colecao** colecaoDePokemons, int* totalPokesNaColecao, int numeroDePokemons, Pokemon* listaPokemon){
    printf("Digite o nome do Pokémon: ");
    char nome[13];
    setbuf(stdin, NULL);
    fgets(nome, 12, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int idDoPokemon = -1;

    for (int i = 0; i < numeroDePokemons; i++) {
        if(strcasecmp(nome, listaPokemon[i].nome) == 0) {
            printf("Achei\n");
            idDoPokemon = listaPokemon[i-1].nPokedex;
            break;
        }
    }

    if (idDoPokemon == -1) {
        printf("Pokemon nao encontrado\n");
        return;
    }

    for (int i = 0; i < *totalPokesNaColecao; i++) {
        if (idDoPokemon == (*colecaoDePokemons)[i].numDoPokemon) {
            printf("Pokémon já está na coleção\n");
            return;
        }
    }
}

void listaPokemonsNaColecao(Colecao* colecaoDePokemons, int totalPokesNaColecao, Pokemon* listaPokemon){
    for (int i = 0; i < totalPokesNaColecao; i++) {
        printf("| %i | Nome: %-12s | Id: %i\n", i + 1, listaPokemon[colecaoDePokemons[i].numDoPokemon].nome, colecaoDePokemons[i].numDoPokemon);
    }
}    

void pesquisaPorPokemonNaColecao(Colecao* colecaoDePokemons, int totalPokesNaColecao, Pokemon* listaPokemon){
    printf("Digite o nome do Pokémon: ");
    char nome[13];
    setbuf(stdin, NULL);
    fgets(nome, 12, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for(int i = 0; i < totalPokesNaColecao; i++) {
        if(strcasecmp(nome, listaPokemon[colecaoDePokemons[i].numDoPokemon].nome) == 0) {
            printf("O pokémon foi encontrado!\n");
            printf("| %i | Nome: %-12s | Id: %i\n", i + 1, listaPokemon[colecaoDePokemons[i].numDoPokemon].nome, colecaoDePokemons[i].numDoPokemon);
        }
    }
}

void alterarPokemonDaColecao(Colecao* colecaoDePokemons, int totalPokesNaColecao, Pokemon* listaPokemon){
    printf("Digite o nome do Pokémon: ");
    char nome[13];
    setbuf(stdin, NULL);
    fgets(nome, 12, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for(int i = 0; i < totalPokesNaColecao; i++) {
        if(strcasecmp(nome, listaPokemon[colecaoDePokemons[i].numDoPokemon].nome) == 0) {
            printf("O que você deseja alterar?\n");
            printf("1- Nome\n2- Tipo 1\n3- Tipo 2\n4- HP\n5- Ataque\n6- Defesa\n7- Ataque Especial\n8- Defesa Especial\n9- Speed\n10- Lendario\n11- Geracao\n12- Altura\n13- Peso\n14- Captura\n");
            printf("Opcao: ");
            int opcao;
            scanf("%i", &opcao);

        switch (opcao){
            case 1:
            printf("Digite um novo nome para o pokémon: ");
            char novoNome[13];
            setbuf(stdin, NULL);
            fgets(novoNome, 12, stdin);
            novoNome[strcspn(novoNome, "\n")] = '\0';
            strcpy(listaPokemon[colecaoDePokemons[i].numDoPokemon].nome, novoNome);
            break;
        
            case 2:
            printf("Digite um novo tipo para o pokémon: ");
            char novoTipo[10];
            setbuf(stdin, NULL);
            fgets(novoTipo, 9, stdin);
            novoTipo[strcspn(novoNome, "\n")] = '\0';
            strcpy(listaPokemon[colecaoDePokemons[i].numDoPokemon].tipo1, novoTipo);
            break;

            case 3:
            printf("Digite um novo tipo para o pokémon: ");
            char novoTipo1[10];
            setbuf(stdin, NULL);
            fgets(novoTipo, 9, stdin);
            novoTipo[strcspn(novoNome, "\n")] = '\0';
            strcpy(listaPokemon[colecaoDePokemons[i].numDoPokemon].tipo2, novoTipo1);
            break;

            case 4:
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor;
            scanf("%i", &novoValor);
            listaPokemon[colecaoDePokemons[i].numDoPokemon].hp = novoValor;
            break;

            case 5:
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor1;
            scanf("%i", &novoValor1);
            listaPokemon[colecaoDePokemons[i].numDoPokemon].atk = novoValor1;
            break;

            case 6:
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor2;
            scanf("%i", &novoValor2);
            listaPokemon[colecaoDePokemons[i].numDoPokemon].def = novoValor2;
            break;

            case 7:
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor3;
            scanf("%i", &novoValor3);
            listaPokemon[colecaoDePokemons[i].numDoPokemon].spatack = novoValor3;
            break;

            case 8:
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor4;
            scanf("%i", &novoValor4);
            listaPokemon[colecaoDePokemons[i].numDoPokemon].spdef = novoValor4;
            break;

            case 9:
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor5;
            scanf("%i", &novoValor5);
            listaPokemon[colecaoDePokemons[i].numDoPokemon].speed = novoValor5;
            break;

            case 10:
            printf("Digite 1 se quiser que ele seja lendario, 0 se quer que ele deixe de ser: ");
            int novoValor6;
            scanf("%i", &novoValor6);
            listaPokemon[colecaoDePokemons[i].numDoPokemon].lendario = novoValor6;
            break;

            case 11:
            printf("Digite a qual geração ele pertencerá: ");
            int novoValor7;
            scanf("%i", &novoValor7);
            listaPokemon[colecaoDePokemons[i].numDoPokemon].geracao = novoValor7;
            break;

            case 12:
            printf("Digite sua nova altura: ");
            float novoValor8;
            scanf("%f", &novoValor8);
            listaPokemon[colecaoDePokemons[i].numDoPokemon].altura = novoValor8;
            break;

            case 13:
            printf("Digite seu novo peso: ");
            float novoValor9;
            scanf("%f", &novoValor9);
            listaPokemon[colecaoDePokemons[i].numDoPokemon].peso = novoValor9;
            break;

            case 14:
            printf("Digite sua nova taxa de captura: ");
            float novoValor10;
            scanf("%f", &novoValor10);
            listaPokemon[colecaoDePokemons[i].numDoPokemon].captura = novoValor10;
            break;

            default:;
            printf("Opção não encontrada...\n");
            break;
            }

        }
    }
}

void excluirPokemonDaColecao(Colecao** colecaoDePokemons, int* totalPokesNaColecao){
    if (*totalPokesNaColecao == 0) {
        printf("A coleção está vazia. Nenhum Pokémon para excluir.\n");
        return;
    }

    printf("Digite o número do Pokémon que deseja excluir da coleção: ");
    int numDoPokemon;
    scanf("%d", &numDoPokemon);

    int indiceParaExclusao = -1;

    for (int i = 0; i < *totalPokesNaColecao; i++) {
        if ((*colecaoDePokemons)[i].numDoPokemon == numDoPokemon) {
            indiceParaExclusao = i;
            break;
        }
    }

    if (indiceParaExclusao == -1) {
        printf("Pokémon não encontrado na coleção.\n");
        return;
    }

    // Movendo os elementos restantes para preencher o espaço do Pokémon excluído
    for (int i = indiceParaExclusao; i < *totalPokesNaColecao - 1; i++) {
        (*colecaoDePokemons)[i] = (*colecaoDePokemons)[i + 1];
    }

    // Reduzindo o tamanho da coleção após a exclusão
    *totalPokesNaColecao -= 1;
    *colecaoDePokemons = (Colecao*)realloc(*colecaoDePokemons, (*totalPokesNaColecao) * sizeof(Colecao));

    printf("Pokémon removido da coleção com sucesso.\n");
}


void InserirNaMochila(Mochila* mochila, Colecao* colecaoDePokemons, int* totalPokesNaColecao){

    int IdPoke;
    int conferePokeInserido = 0;
    int PosicaoNaMochila;

    printf("Digite a posição que você quer inserir o Pokémon: ");
    scanf("%d", &PosicaoNaMochila);

    switch(PosicaoNaMochila){

        case 1:

            printf("Digite o número do pokemon que você quer inserir na sua mochila: ");
            scanf("%d", &IdPoke);

            for(int i=0;i < *totalPokesNaColecao;i++){

                if(IdPoke == colecaoDePokemons->numDoPokemon){
                    mochila->idPokeMochila[0] = colecaoDePokemons->numDoPokemon[i];
                    totalPokesNaColecao++;
                    conferePokeInserido++;    
                }
            }

            if(conferePokeInserido == 0){

                printf("O Pokémon que você digitou não foi encontrado na Coleção.\n");

            }

        break;

        case 2:

            printf("Digite o número do pokemon que você quer inserir na sua mochila: ");
            scanf("%d", &IdPoke);

            for(int i=0;i < *totalPokesNaColecao;i++){

                if(IdPoke == colecaoDePokemons->numDoPokemon){
                    mochila->IdPokeMochila[1] = colecaoDePokemons->numDoPokemon;
                    totalPokesNaColecao++;
                    conferePokeInserido++;    
                }
            }

            if(conferePokeInserido == 0){

                printf("O Pokémon que você digitou não foi encontrado na Coleção.\n");

            }

        break;

        case 3:

            printf("Digite o número do pokemon que você quer inserir na sua mochila: ");
            scanf("%d", &IdPoke);

            for(int i=0;i < *totalPokesNaColecao;i++){

                if(IdPoke == colecaoDePokemons->numDoPokemon){
                    mochila->IdPokeMochila[2] = colecaoDePokemons->numDoPokemon;
                    totalPokesNaColecao++;
                    conferePokeInserido++;    
                }
            }

            if(conferePokeInserido == 0){

                printf("O Pokémon que você digitou não foi encontrado na Coleção.\n");

            }

        break;

        case 4:

            printf("Digite o número do pokemon que você quer inserir na sua mochila: ");
            scanf("%d", &IdPoke);

            for(int i=0;i < *totalPokesNaColecao;i++){

                if(IdPoke == colecaoDePokemons->numDoPokemon){
                    mochila->IdPokeMochila[3] = colecaoDePokemons->numDoPokemon;
                    totalPokesNaColecao++;
                    conferePokeInserido++;    
                }
            }

            if(conferePokeInserido == 0){

                printf("O Pokémon que você digitou não foi encontrado na Coleção.\n");

            }

        break;

        case 5:

            printf("Digite o número do pokemon que você quer inserir na sua mochila: ");
            scanf("%d", &IdPoke);

            for(int i=0;i < *totalPokesNaColecao;i++){

                if(IdPoke == colecaoDePokemons->numDoPokemon){
                    mochila->IdPokeMochila[4] = colecaoDePokemons->numDoPokemon;
                    totalPokesNaColecao++;
                    conferePokeInserido++;    
                }
            }

            if(conferePokeInserido == 0){

                printf("O Pokémon que você digitou não foi encontrado na Coleção.\n");

            }

        break;

        case 6:

            printf("Digite o número do pokemon que você quer inserir na sua mochila: ");
            scanf("%d", &IdPoke);

            for(int i=0;i < totalPokesNaColecao;i++){

                if(IdPoke == colecaoDePokemons->numDoPokemon){
                    mochila->IdPokeMochila[5] = colecaoDePokemons->numDoPokemon;
                    totalPokesNaColecao++;
                    conferePokeInserido++;    
                }
            }

            if(conferePokeInserido == 0){

                printf("O Pokémon que você digitou não foi encontrado na Coleção.\n");

            }

        break;

        

    }

    return;
}

int main(){

    srand(time(NULL));
    // Código necessário para funcionamento do randomizador

    FILE *arquivo;
    Pokemon* listaPokemon;
    int numeroDePokemons = 721;
    int tamanhoPrimeiraLinhaCSV;
    Colecao* colecaoDePokemons;
    int totalPokesNaColecao = 0;

    arquivo = fopen("../pokedex.csv", "r+");
    // Sugiro que mudem isso aqui para o caminho .csv no computador de vocês, por enquanto

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    tamanhoPrimeiraLinhaCSV = sizeof("numero ,nome        ,tipo1    ,tipo2    ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura");

    listaPokemon = (Pokemon*) malloc(numeroDePokemons * sizeof(Pokemon));

    fseek(arquivo, tamanhoPrimeiraLinhaCSV, SEEK_SET);

    for(int i = 0; i < numeroDePokemons; i++){
        fscanf(arquivo, "%d ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%s ,%f ,%f ,%f \n", &listaPokemon[i].nPokedex, listaPokemon[i].nome, listaPokemon[i].tipo1, listaPokemon[i].tipo2, &listaPokemon[i].total, &listaPokemon[i].hp, &listaPokemon[i].atk, &listaPokemon[i].def, &listaPokemon[i].spatack, &listaPokemon[i].spdef, &listaPokemon[i].speed, &listaPokemon[i].geracao, &listaPokemon[i].lendario, listaPokemon[i].cor, &listaPokemon[i].altura, &listaPokemon[i].peso, &listaPokemon[i].captura);
    }//for

    fclose(arquivo);

    printf("Nome: %s\n", listaPokemon[0].nome);
    printf("HP: %i\n", listaPokemon[0].hp);
    printf("ATK: %i\n", listaPokemon[0].atk);
    printf("DEF: %i\n", listaPokemon[0].def);
    printf("ATK.SP: %i\n", listaPokemon[0].spatack);
    printf("DEF.SP: %i\n", listaPokemon[0].spdef);
    printf("Speed: %i\n", listaPokemon[0].speed);
    printf("Captura: %.2f\n", listaPokemon[0].captura);
    // Exemplo de comandos pra ver se ta tudo certin

    FILE* arquivoPokemonCSV;
    arquivoPokemonCSV = fopen("../pokedex.csv", "r+");
    int EscolheFuncao;
    int EscolheSubFuncao;

    if (arquivoPokemonCSV == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    tamanhoPrimeiraLinhaCSV = sizeof("numero ,nome        ,tipo1    ,tipo2    ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura");

    fseek(arquivoPokemonCSV, tamanhoPrimeiraLinhaCSV, SEEK_SET);

    for(int i = 1; i < 722; i++){
        fscanf(arquivoPokemonCSV, "%d ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%s ,%f ,%f ,%f \n", &listaPokemon[i].nPokedex, listaPokemon[i].nome, listaPokemon[i].tipo1, listaPokemon[i].tipo2, &listaPokemon[i].total, &listaPokemon[i].hp, &listaPokemon[i].atk, &listaPokemon[i].def, &listaPokemon[i].spatack, &listaPokemon[i].spdef, &listaPokemon[i].speed, &listaPokemon[i].geracao, &listaPokemon[i].lendario, listaPokemon[i].cor, &listaPokemon[i].altura, &listaPokemon[i].peso, &listaPokemon[i].captura);
    }//for

    fclose(arquivoPokemonCSV);

    Mochila mochila;

    do{
        printf("\nMENU\n");
        printf("1 -> Pokedex\n2 -> Colecao\n3 -> Mochila\n4 -> Guia\n5 -> Configuracoes\n6 -> Sair do jogo\n");

        printf("Digite uma das opcoes acima: ");
        scanf("%d", &EscolheFuncao);

        switch(EscolheFuncao){
            case 1:
                printf("\n\nSUBMENU POKEDEX\n");
                printf("1 -> Inserir Pokemons\n2 -> Listar Pokemons\n3 -> Pesquisar Pokemons\n4 -> Alterar Pokemons\n5 -> Excluir Pokemons\n");
                scanf("%d", &EscolheSubFuncao);

                switch(EscolheSubFuncao){
                    case 1:
                        printf("Opcao nao encontrada!\n");
                        break;

                    case 2:
                        printf("Opcao nao encontrada!\n");
                        break;

                    case 3:
                        printf("Opcao nao encontrada!\n");
                        break;

                    case 4:
                        printf("Opcao nao encontrada!\n");
                        break;

                    case 5:
                        printf("Opcao nao encontrada!\n");
                        break;

                    default:
                        printf("Opcao nao encontrada!\n");

                        break;    
                    }

            break;        

        case 2:
            printf("\nSUBMENU COLECAO\n");        
            printf("1 -> Inserir Pokemons\n2 -> Listar Pokemons\n3 -> Pesquisar Pokemons\n4 -> Alterar Pokemons\n5 -> Excluir Pokemons\n");
            scanf("%d", &EscolheSubFuncao);

            switch(EscolheSubFuncao){
                case 1:
                    adicionarPokemonNaColecao(&colecaoDePokemons, &totalPokesNaColecao, numeroDePokemons, listaPokemon);
                    break;

                case 2:
                    listaPokemonsNaColecao(colecaoDePokemons, totalPokesNaColecao, listaPokemon);
                    break;

                case 3:
                    pesquisaPorPokemonNaColecao(colecaoDePokemons, totalPokesNaColecao, listaPokemon);
                    break;

                case 4:
                    alterarPokemonDaColecao(colecaoDePokemons, totalPokesNaColecao, listaPokemon);
                    break;

                case 5:;
                    excluirPokemonDaColecao(&colecaoDePokemons, &totalPokesNaColecao);
                    break;

                default:
                    printf("Opcao nao encontrada!\n");

                    break;    
                }
        break;

            case 3:
                printf("\n\nSUBMENU MOCHILA\n");
                printf("1 -> Inserir Pokemon na mochila\n2 -> Trocar Pokemon inserido\n");
                scanf("%d", &EscolheSubFuncao);

                    switch(EscolheSubFuncao){
                        case 1:
                            InserirNaMochila(&mochila, colecaoDePokemons, &totalPokesNaColecao);
                            break;

                        case 2:
                            printf("Opcao nao encontrada!\n");
                            break;

                        default:
                            printf("Opcao nao encontrada!\n");

                            break;        
                    }

                break;

            case 4:
                printf("\n\nSUBMENU GUIA\nOque você quer saber sobre o jogo?\n1 -> Como conseguir moedas?\n2 -> como conseguir Pokemons?\n3 -> Como desbloquear novas áreas?\n");
                scanf("%d", &EscolheSubFuncao);

                    switch(EscolheSubFuncao){
                        case 1:
                            printf("Voce obtera moedas ao vencer batalhas e ao completar missoes!\n");
                            break;

                        case 2:
                            printf("Voce conseguira Pokemons ao captura-los durante suas aventuras!\n");
                            break;

                        case 3:
                            printf("Voce desbloqueara novas areas ao subir de nivel!\n");     
                            break;

                        default:
                            printf("Opcao nao encontrada!\n");      

                    }
                break;

            case 5:
                printf("\n\nSUBMENU CONFIGURACOES\n");
                break;

            case 6:

                break;      

            default:
                printf("Opcao nao encontrada\n");

                break;        
        }

    }while(EscolheFuncao != 6);                       

    free(listaPokemon);

    return 0;
}
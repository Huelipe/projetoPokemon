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
    /*
    As evs são valores que vão de 0 a 252, esse valor é dividido por 4 e depois também somado ao atributo respectivo do pokémon
    Todos os pokémons capturados vem com suas EVs zeradas, para ganhar EVs, os pokémons poderão comer as frutas que discutimos ou ganhar em batalha
    No sistema original, um pokemon ganharia as evs em batalha dependendo do pokemon que estivesse contra, por exemplo:
    Ao batalhar contra um pikachu, o pokémon ganharia EVs de speed, pois o atributo mais alto do pikachu é a velocidade, ou seja, o pokémon estaria treinando a sua velocidade
    Então aumentar evs de pokémon é algo que temos definir como fazer, mas é como levar o pokémon pra academia
    Obs: Cada evs pode ir de 0 a 252, mas, um pokemon pode ter, no maximo, somando todas, 508 evs
    Então só da pra maximizar 2 evs e colocar mais uns 4 pontos em qualquer outra (para competitivo)
    */ 
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

int main(){

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

    // Substituir por fscanf
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
    // Código feito pelo chatgpt para salvar os dados do .csv no struct pokemon

    printf("Nome: %s\n", listaPokemon[6].nome);
    printf("HP: %i\n", listaPokemon[6].hp);
    printf("ATK: %i\n", listaPokemon[6].atk);
    printf("DEF: %i\n", listaPokemon[6].def);
    printf("ATK.SP: %i\n", listaPokemon[6].spatack);
    printf("DEF.SP: %i\n", listaPokemon[6].spdef);
    printf("Speed: %i\n", listaPokemon[6].speed);
    printf("Speed: %i\n", listaPokemon[6].captura);
    // Exemplo de comandos pra ver se ta tudo certin

    /*
    O parte a seguir que vai até a linha 393 mais ou menos define as naturezas do pokémon
    Como dito anteriormente, um pokemon tem HP, atack, defesa, atack especial, defesa especial e velocidade
    Existe uma tabela que define 25 naturezas, que definem que um pokémon pode ser melhor em um atributo X e pior em um atributo Y
    Por exemplo, a nature "Timid", listada na posição 10 ("9") do vetor faz com que o pokémon tenha 10% a mais de velocidade, mas, em compensação, -10% de atack
    As 5 primeiras naturezas não mudam absolutamente nada no pokemon
    Eis um link com a tabela: https://aminoapps.com/c/pokemon-amino-ptbr/page/blog/natures-certas-para-os-pokemons/wPkB_rMIourbDLoV3Z8Vk3JXvMx5R172xG
    Obs: Nenhuma natureza interfere no HP do pokemon, apenas nos outros 5 atributos
    */

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

    Pokebola pokebolas[4];
    strcpy(pokebolas[0].nome, "Pokebola");
    strcpy(pokebolas[1].nome, "Grande Bola");
    strcpy(pokebolas[2].nome, "Ultra Bola");
    strcpy(pokebolas[3].nome, "Bola mestre");
    /*
    Aqui defino as 4 pokebolas mais comuns do jogo, cada pokebola tem um nome e um catch rate
    A bola mestre tem 100% de chance de captura, por isso seu modificador é 10 mil, mas podemos mudar pra simplesmente um if
    */

    pokebolas[0].catchRate = 1;
    pokebolas[1].catchRate = 1.5;
    pokebolas[2].catchRate = 2;
    pokebolas[3].catchRate = 10000;

    printf("Digite o nome do pokemon que você está batalhando: ");
    char nome[40];
    setbuf(stdin, NULL);
    fgets(nome, 39, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    /*
    Aqui é o começo de um código pra ver se ta tudo certo
    Você digita o nome de um pokemon, ele vai buscar na lista do .csv e pegar os atributos e salvar em selvagemNaDex
    Obs: O código está com erro ao buscar o nome do pokemon porque salvou as barras de espaço
    Então, para testar por enquanto, conte quantas letras tem no nome do pokemon, subtraia de 12
    dai por exemplo charizard tem 9 letras, 12-9 = 3
    Digita charizard e da 3 barras de espaço e vai funcionar
    */

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

//COMECEI A PARTIR DAQUI AMIGOS

typedef struct{
    char nome[21];
    char genero[11];
    float nivel;
    float DinheiroAtual;
}JogadorStruct;

typedef struct{
    int Bananinha;
    int Moranguinho;
    int Laranjinha;
}Frutas;

void Jogador(){//so entrara nessa funcao ao iniciar o jogo

    JogadorStruct Jogador;
    Frutas EstoqueFrutas;
    int EscolheGenero;
    int ConfereVitoria = 0;
    int ConfereMinigameVencido = 0; 

    printf("Seja bem vindo(a)! Digite seu nome para começar sua jornada: ");   

    fgets(Jogador.nome, 20, stdin);//o jogador ira digitar o seu nome de exibicao do jogo 
    Jogador.nome[strcspn(Jogador.nome,"\n")]='\0';
    setbuf(stdin,NULL);

    printf("\n");

    printf("Digite seu genero:\n1 -> Masculino\n2 -> Feminino\n");

    scanf("%d", &EscolheGenero);//1 para masculino e 2 para feminino

    switch(EscolheGenero){
        case '1':
            strcpy(Jogador.genero, "masculino");
            break;

        case '2':
            strcpy(Jogador.genero, "feminino");    
            break;

        default:
            //genero nao identificado
            scanf("%d", &EscolheGenero);//escolhe novamente
            break;
    }//switch

    Jogador.nivel = 1;

    Jogador.DinheiroAtual = 0;

    EstoqueFrutas.Bananinha = 0;
    EstoqueFrutas.Moranguinho = 0;
    EstoqueFrutas.Laranjinha = 0;


}//Jogador

float Economia(float DinheiroAtual, int ConfereVitoria, int ConfereMinigameVencido, float GastosPokedoca, float GastosPokecentro, char JogadorNome){//sera executada ao vencer batalha, minigame ou ao gastar

    float Pokemoeda;
    int ConfereIniciante = 1;
    int X;
    int Y;

    if(ConfereIniciante == 1){
        //aqui seria legal se nos mostrassemos algumas das formas de se obter pokemoedas
        printf("Ola %s! Este jogo possui um sistema de economia, aqui estão algumas das formas de se obter Pokemoedas:", JogadorNome);
        printf("\nVencendo Batalhas\nVencendo Minigames\nVendendo Itens");
    }else{
        if(ConfereVitoria == 1){
            Pokemoeda= Pokemoeda + X;//recebe por ter saido vitorioso de uma batalha
        }
        if(ConfereMinigameVencido == 1){
            Pokemoeda = Pokemoeda + Y;//Recebe por ter vencido minigame
        }
        if(GastosPokedoca > 0 || GastosPokecentro > 0){
            Pokemoeda = Pokemoeda - GastosPokedoca - GastosPokecentro;//Analisa todos os gastos e atualiza o dinheiro atual
        }

    }

    //a parte abaixo atualiza as variaveis para nao ocorrer uma mudanca errada na moeda atual
    GastosPokecentro = 0;
    GastosPokedoca = 0;
    ConfereIniciante = 0;
    ConfereMinigameVencido = 0;
    ConfereVitoria = 0;

    return Pokemoeda;
}//Economia


void Pokedoca(float Pokemoeda, int Bananinha, int Moranguinho, int Laranjinha, char genero){

    int EscolheGasto;
    char Escolha;
    char pronome[1];

    if(strcmp(genero, "masculino")==0){
        strcpy(pronome, "o");
    }else{
        strcpy(pronome, "a");
    }
    printf("Seja bem vind%c a Pokedoca! Aqui você pode comprar Pokebolas, Frutas e muitos outros itens!\n", pronome);

    printf("Você está interessado em comprar algo? (Digite 'S' para sim e 'N' para não)\n");

    scanf("%c", &Escolha);

    switch(Escolha){
        case 'S':
        case 's':

            break;

        case 'N':
        case 'n':

            break;

        default:
            printf("escolha não identificada, digite novamente: ('S' para sim e 'N' para não)\n");
            scanf("%c", &Escolha);

    }

    return;
}
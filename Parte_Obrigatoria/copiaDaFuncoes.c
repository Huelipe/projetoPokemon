/*
//bibliotecas utilizadas nas funcoes
#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Início das funções 

//funcao para criar pokemon selvagem
void criarPokemon(Pokemon pokemonNaDex, pokemonCapturado* pselvagem, int lvl, nature natures[25]) {

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

    pselvagem->HP = ((pselvagem->LvlAtual * ((pokemonNaDex.hp * 2) + pselvagem->ivsHP + (pselvagem->evsHP / 4))) / 100) + 10 + pselvagem->LvlAtual;
    pselvagem->Atk = (((pselvagem->LvlAtual * ((pokemonNaDex.atk * 2) + pselvagem->ivsAtk + (pselvagem->evsAtk / 4))) / 100) + 5) * natures[r].modAtk;
    pselvagem->Def = (((pselvagem->LvlAtual * ((pokemonNaDex.def * 2) + pselvagem->ivsDef + (pselvagem->evsDef / 4))) / 100) + 5) * natures[r].modDef;
    pselvagem->Spatack = (((pselvagem->LvlAtual * ((pokemonNaDex.spatack * 2) + pselvagem->ivsSpatack + (pselvagem->evsSpatack / 4))) / 100) + 5) * natures[r].modSpatack;
    pselvagem->SpDef = (((pselvagem->LvlAtual * ((pokemonNaDex.spdef * 2) + pselvagem->ivsSpDef + (pselvagem->evsSpDef / 4))) / 100) + 5) * natures[r].modSpdef;
    pselvagem->Speed = (((pselvagem->LvlAtual * ((pokemonNaDex.speed * 2) + pselvagem->ivsSpeed + (pselvagem->evsSpeed / 4))) / 100) + 5) * natures[r].modSpeed;

    pselvagem->HPATUAL = pselvagem->HP;

    pselvagem->Status.atual = 1;
}

//funcao utilizada para ler string
void leString(char string[], int tamanho){

    setbuf(stdin,NULL);//zera o buffer
    fgets(string, tamanho - 1, stdin);//le a string
    string[strcspn(string, "\n")] = '\0';//troca o ultimo caractere da string pelo \0

    return;
}//leString

//funcao utilizada para adicionar pokemons na colecao do jogo
void adicionarPokemonNaColecao(Colecao** colecaoDePokemons, int* totalPokesNaColecao, int numeroDePokemons, Pokemon* listaPokemon){
    
    //recebe o nome do pokemon a ser adicionado
    printf("Digite o nome do Pokémon: ");
    char nome[13];
    leString(nome, 13);

    //declara a variavel onde sera salva o id do pokemon na pokedex
    int idDoPokemon = -1;

    //procura o pokemon na pokedex, para verificar se ele existe
    for (int i = 0; i < numeroDePokemons; i++) {
        //caso encontre o pokemon na pokedex salva o numero da pokedex dele na variavel idDoPokemon
        if(strcasecmp(nome, listaPokemon[i].nome) == 0) {
            printf("Achei\n");
            idDoPokemon = listaPokemon[i-1].nPokedex;
            break;
        }//if
    }//for

    //se o pokemon nao for encontrado na pokedex, o id nao sera alterado e o usuario sera avisado
    if (idDoPokemon == -1) {
        printf("Pokemon nao encontrado\n");
        return;
    }//if

    //verifica se o pokemon ja esta na colecao, por meio do id
    for (int i = 0; i < *totalPokesNaColecao; i++) {
        //caso o pokemon ja esteja na colecao, avisa o usuario disso
        if (idDoPokemon == (*colecaoDePokemons)[i].numDoPokemon) {
            printf("Pokémon já está na coleção\n");
            return;
        }//if
    }//for

    //adiciona 1 no total de pokemons da colecao
    *totalPokesNaColecao += 1;
    //realoca o vetor dinamico de pokemons da colecao para o novo numero de pokemons
    *colecaoDePokemons = (Colecao*)realloc(*colecaoDePokemons, (*totalPokesNaColecao) * sizeof(Colecao));
    //salva o id do pokemon na variavel numDoPokemon da struct colecao de pokemons
    (*colecaoDePokemons)[*totalPokesNaColecao - 1].numDoPokemon = idDoPokemon;
}//adicionarPokemonNaColecao

//funcao utilizada para listar os pokemons da colecao
void listaPokemonsNaColecao(Colecao* colecaoDePokemons, int totalPokesNaColecao, Pokemon* listaPokemon){
    //mostra o numero do pokemon na colecao, o nome, e o id dele na pokedex ao usuario
    for (int i = 0; i < totalPokesNaColecao; i++) {
        printf("| %i | Nome: %-12s | Id: %i\n", i + 1, listaPokemon[colecaoDePokemons[i].numDoPokemon].nome, colecaoDePokemons[i].numDoPokemon);
    }//for
}//listaPokemonsNaColecao

//funcao utilizada para pesquisar pokemons na colecao
void pesquisaPorPokemonNaColecao(Colecao* colecaoDePokemons, int totalPokesNaColecao, Pokemon* listaPokemon){
    //recebe o nome do pokemon a ser pesquisado na colecao
    printf("Digite o nome do Pokémon: ");
    char nome[13];
    leString(nome, 13);

    //verifica se o nome pesquisado esta na colecao do jogo
    for(int i = 0; i < totalPokesNaColecao; i++) {
        //caso esteja na colecao, avisa o usuario que foi encontrado e mostra o numero na colecao, o nome e o id da pokedex
        if(strcasecmp(nome, listaPokemon[colecaoDePokemons[i].numDoPokemon].nome) == 0) {
            printf("O pokémon foi encontrado!\n");
            printf("| %i | Nome: %-12s | Id: %i\n", i + 1, listaPokemon[colecaoDePokemons[i].numDoPokemon].nome, colecaoDePokemons[i].numDoPokemon);
        }//if
    }//for
}//pesquisaPorPokemonNaColecao

//funcao que altera os pokemons da colecao
void alterarPokemonDaColecao(Colecao* colecaoDePokemons, int totalPokesNaColecao, Pokemon* listaPokemon){
    //recebe o nome do pokemon que vai ser alterado na colecao
    printf("Digite o nome do Pokémon: ");
    char nome[13];
    leString(nome, 13);

    //veirifica se o pokemon esta na colecao
    for(int i = 0; i < totalPokesNaColecao; i++) {
        //caso o pokemon esteja na colecao, mostra um menu ao usuario com as opcoes de atributos que podem ser alterados no pokemon
        if(strcasecmp(nome, listaPokemon[colecaoDePokemons[i].numDoPokemon].nome) == 0) {
            //menu com opcoes de atributos para serem alterados pelo usuario
            printf("O que você deseja alterar?\n");
            printf(" 1- Nome\n 2- Tipo 1\n 3- Tipo 2\n 4- HP\n 5- Ataque\n 6- Defesa\n 7- Ataque Especial\n 8- Defesa Especial\n 9- Speed\n10- Lendario\n11- Geracao\n12- Altura\n13- Peso\n14- Captura\n15- Sair\n");
            printf("Opcao: ");
            int opcao;
            scanf("%i", &opcao);

        //analisa a opcao colocada pelo usuario
        switch (opcao){
            //caso o usuario digite 1, ele poderá alterar o nome do pokemon escolhido na colecao
            case 1:
            //recebe o novo nome do pokemon da colecao do usuario
            printf("Digite um novo nome para o pokémon: ");
            char novoNome[13];
            leString(novoNome, 13);
            //copia o nome novo escrito pelo usuario para o nome do pokemon na colecao
            strcpy(listaPokemon[colecaoDePokemons[i].numDoPokemon].nome, novoNome);
            break;

            //caso o usuario digite 2, ele poderá alterar o tipo 1 do pokemon escolhido na colecao
            case 2:
            //recebe o novo tipo 1 do pokemon da colecao do usuario
            printf("Digite um novo tipo para o pokémon: ");
            char novoTipo[10];
            leString(novoTipo, 10);
            //copia o tipo 1 novo escrito pelo usuario para o tipo 1 do pokemon na colecao
            strcpy(listaPokemon[colecaoDePokemons[i].numDoPokemon].tipo1, novoTipo);
            break;

            //caso o usuario digite 3, ele poderá alterar o tipo 2 do pokemon escolhido na colecao
            case 3:
            //recebe o novo tipo 2 do pokemon da colecao do usuario
            printf("Digite um novo tipo para o pokémon: ");
            char novoTipo1[10];
            leString(novoTipo1, 10);
            //copia o tipo 2 novo escrito pelo usuario para o tipo 2 do pokemon na colecao
            strcpy(listaPokemon[colecaoDePokemons[i].numDoPokemon].tipo2, novoTipo1);
            break;

            //caso o usuario digite 4, ele poderá alterar a vida do pokemon escolhido na colecao
            case 4:
            //recebe a nova vida do pokemon da colecao do usuario
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor;
            scanf("%i", &novoValor);
            //copia a vida nova escrita pelo usuario para a vida do pokemon na colecao
            listaPokemon[colecaoDePokemons[i].numDoPokemon].hp = novoValor;
            break;

            //caso o usuario digite 5, ele poderá alterar o ataque do pokemon escolhido na colecao
            case 5:
            //recebe o novo ataque do pokemon da colecao do usuario
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor1;
            scanf("%i", &novoValor1);
            //copia o ataque novo escrito pelo usuario para o ataque do pokemon na colecao
            listaPokemon[colecaoDePokemons[i].numDoPokemon].atk = novoValor1;
            break;

            //caso o usuario digite 6, ele poderá alterar a defesa do pokemon escolhido na colecao
            case 6:
            //recebe a nova defesa do pokemon da colecao do usuario
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor2;
            scanf("%i", &novoValor2);
            //copia a defesa nova escrita pelo usuario para a defesa do pokemon na colecao
            listaPokemon[colecaoDePokemons[i].numDoPokemon].def = novoValor2;
            break;

            //caso o usuario digite 7, ele poderá alterar o ataque especial do pokemon escolhido na colecao
            case 7:
            //recebe o novo ataque especial do pokemon da colecao do usuario
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor3;
            scanf("%i", &novoValor3);
            //copia o ataque especial novo escrito pelo usuario para o ataque especial do pokemon na colecao
            listaPokemon[colecaoDePokemons[i].numDoPokemon].spatack = novoValor3;
            break;

            //caso o usuario digite 8, ele poderá alterar a defesa especial do pokemon escolhido na colecao
            case 8:
            //recebe a nova defesa especial do pokemon da colecao do usuario
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor4;
            scanf("%i", &novoValor4);
            //copia a defesa especial nova escrita pelo usuario para a defesa especial do pokemon na colecao
            listaPokemon[colecaoDePokemons[i].numDoPokemon].spdef = novoValor4;
            break;

            //caso o usuario digite 9, ele poderá alterar a velocidade do pokemon escolhido na colecao
            case 9:
            //recebe a nova velocidade do pokemon da colecao do usuario
            printf("Digite um novo valor para o Status selecionado: ");
            int novoValor5;
            scanf("%i", &novoValor5);
            //copia a velocidade nova escrita pelo usuario para a velocidade do pokemon na colecao
            listaPokemon[colecaoDePokemons[i].numDoPokemon].speed = novoValor5;
            break;

            //caso o usuario digite 10, ele poderá alterar o lendario do pokemon escolhido na colecao
            case 10:
            //recebe o novo lendario do pokemon da colecao do usuario
            printf("Digite 1 se quiser que ele seja lendario, 0 se quer que ele deixe de ser: ");
            int novoValor6;
            scanf("%i", &novoValor6);
            //copia o lendario novo escrito pelo usuario para o lendario do pokemon na colecao
            listaPokemon[colecaoDePokemons[i].numDoPokemon].lendario = novoValor6;
            break;

            //caso o usuario digite 11, ele poderá alterar a geracao do pokemon escolhido na colecao
            case 11:
            //recebe a nova geracao do pokemon da colecao do usuario
            printf("Digite a qual geração ele pertencerá: ");
            int novoValor7;
            scanf("%i", &novoValor7);
            //copia a geracao nova escrita pelo usuario para a geracao do pokemon na colecao
            listaPokemon[colecaoDePokemons[i].numDoPokemon].geracao = novoValor7;
            break;

            //caso o usuario digite 12, ele poderá alterar a altura do pokemon escolhido na colecao
            case 12:
            //recebe a nova altura do pokemon da colecao do usuario
            printf("Digite sua nova altura: ");
            float novoValor8;
            scanf("%f", &novoValor8);
            //copia a altura nova escrita pelo usuario para a altura do pokemon na colecao
            listaPokemon[colecaoDePokemons[i].numDoPokemon].altura = novoValor8;
            break;

            //caso o usuario digite 13, ele poderá alterar o peso do pokemon escolhido na colecao
            case 13:
            //recebe o novo peso do pokemon da colecao do usuario
            printf("Digite seu novo peso: ");
            float novoValor9;
            scanf("%f", &novoValor9);
            //copia o peso novo escrito pelo usuario para o peso do pokemon na colecao
            listaPokemon[colecaoDePokemons[i].numDoPokemon].peso = novoValor9;
            break;

            //caso o usuario digite 14, ele poderá alterar a taxa de captura do pokemon escolhido na colecao
            case 14:
            //recebe a nova taxa de captura do pokemon da colecao do usuario
            printf("Digite sua nova taxa de captura: ");
            float novoValor10;
            scanf("%f", &novoValor10);
            //copia a taxa de captura nova escrita pelo usuario para a taxa de captura do pokemon na colecao
            listaPokemon[colecaoDePokemons[i].numDoPokemon].captura = novoValor10;
            break;

            //caso o usuario digite 15, ele voltará ao menu principal do jogo
            case 15:
            //recalcula o total do pokemon caso o usuario tenha alterado alguma especificacao que contemple o total do pokemon
            listaPokemon[colecaoDePokemons[i].numDoPokemon].total = listaPokemon[colecaoDePokemons[i].numDoPokemon].hp + listaPokemon[colecaoDePokemons[i].numDoPokemon].atk + listaPokemon[colecaoDePokemons[i].numDoPokemon].def + listaPokemon[colecaoDePokemons[i].numDoPokemon].spatack + listaPokemon[colecaoDePokemons[i].numDoPokemon].spdef + listaPokemon[colecaoDePokemons[i].numDoPokemon].speed;
            return;
            break;

            //caso o usuario nao digite nenhuma das opcoes acima, mostra que a opcao digitada nao foi encontrada 
            default:
            printf("Opção não encontrada...\n");
            break;
            }//switch

        }//if
    }//for
}//alterarPokemonDaColecao

//funcao utilizada para excluir os pokemons da colecao
void excluirPokemonDaColecao(Colecao** colecaoDePokemons, int* totalPokesNaColecao){
    //verifica se existem pokemons na colecao, caso nao exista mostra ao usuario que a colecao ta vazia
    if (*totalPokesNaColecao == 0) {
        printf("A coleção está vazia. Nenhum Pokémon para excluir.\n");
        return;
    }//if

    //solicita ao usuario o id do pokemon na pokedex para excluí-lo da colecao
    printf("Digite o Id do Pokémon que deseja excluir da coleção: ");
    int numDoPokemon;
    scanf("%d", &numDoPokemon);

    //cria a variavel utilizada para salvar o indice do pokemon excluido
    int indiceParaExclusao = -1;

    //verifica se o numero do id do pokemon digitado corresponde a algum pokemon da colecao ou nao
    for (int i = 0; i < *totalPokesNaColecao; i++) {
        if ((*colecaoDePokemons)[i].numDoPokemon == numDoPokemon) {
            indiceParaExclusao = i;//salva o indice do pokemon encontrado a ser excluido
            break;
        }//if
    }//for

    //caso o numero do id do pokemon digitado nao corresponder a nenhum pokemon da colecao, mostra ao usuario que o pokemon nao foi encontrado
    if (indiceParaExclusao == -1) {//verifica se a variavel indiceParaExclusao foi alterada ou nao
        printf("Pokémon não encontrado na coleção.\n");
        return;
    }//if

    // Movendo os elementos restantes para preencher o espaço do Pokémon excluído
    for (int i = indiceParaExclusao; i < *totalPokesNaColecao - 1; i++) {
        (*colecaoDePokemons)[i] = (*colecaoDePokemons)[i + 1];
    }//for

    // Reduzindo o tamanho da coleção após a exclusão
    *totalPokesNaColecao -= 1;
    *colecaoDePokemons = (Colecao*)realloc(*colecaoDePokemons, (*totalPokesNaColecao) * sizeof(Colecao));

    //mostra ao usuario que o pokemon foi removido da colecao
    printf("Pokémon removido da coleção com sucesso.\n");
}//excluirPokemonDaColecao


//funcao utilizada para adicionar pokemons na pokedex
void adicionarPokemonNaPokedex(Pokemon* listaPokemon, int* numeroDePokemons){

    //aumenta o numero de pokemons da pokedex
    (*numeroDePokemons)++;

    //realoca o vetor dinamico de pokemons da pokedex para o novo numero de pokemons
    listaPokemon = (Pokemon*) realloc(listaPokemon, ((*numeroDePokemons) * sizeof(Pokemon)));

    //solicita o nome do novo pokemon da pokedex
    printf("\nDigite o nome do pokémon a ser adicionado:");
    leString(listaPokemon[(*numeroDePokemons) - 1].nome, 40);

    //solicita o tipo 1 do novo pokemon da pokedex
    printf("\nDigite o tipo 1 do pokémon a ser adicionado:");
    leString(listaPokemon[(*numeroDePokemons) - 1].tipo1, 10);

    //solicita o tipo 2 do novo pokemon da pokedex
    printf("\nDigite o tipo 2 do pokémon a ser adicionado:");
    leString(listaPokemon[(*numeroDePokemons) - 1].tipo2, 10);

    //solicita a vida do novo pokemon da pokedex
    printf("\nDigite os pontos de vida (hp) do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].hp);

    //solicita o ataque do novo pokemon da pokedex
    printf("\nDigite os pontos de ataque do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].atk);

    //solicita a defesa do novo pokemon da pokedex
    printf("\nDigite os pontos de defesa do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].def);

    //solicita o ataque especial do novo pokemon da pokedex
    printf("\nDigite os pontos de ataque especial do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].spatack);

    //solicita a defesa especial do novo pokemon da pokedex
    printf("\nDigite os pontos de defesa especial do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].spdef);

    //solicita a velocidade do novo pokemon da pokedex
    printf("\nDigite os pontos de velocidade do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].speed);

    //solicita a geracao do novo pokemon da pokedex
    printf("\nDigite a geração do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].geracao);

    //solicita o lendario do novo pokemon da pokedex
    printf("\nDigite se o pokémon a ser adicionado é lendário(digite 1) ou não(digite 0):");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].lendario);

    //solicita a cor do novo pokemon da pokedex
    printf("\nDigite a cor do pokémon a ser adicionado:");
    leString(listaPokemon[(*numeroDePokemons) - 1].cor, 10);

    //solicita a altura do novo pokemon da pokedex
    printf("\nDigite a altura do pokémon a ser adicionado:");
    scanf("%f", &listaPokemon[(*numeroDePokemons) - 1].altura);

    //solicita o peso do novo pokemon da pokedex
    printf("\nDigite o peso do pokémon a ser adicionado:");
    scanf("%f", &listaPokemon[(*numeroDePokemons) - 1].peso);

    //solicita a taxa de captura do novo pokemon da pokedex
    printf("\nDigite a taxa de captura do pokémon a ser adicionado:");
    scanf("%f", &listaPokemon[(*numeroDePokemons) - 1].captura);

    //solicita a pre-evolucao do novo pokemon da pokedex
    printf("\nDigite a pré-evolução do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].preEvo);

    //solicita a proxima evolucao do novo pokemon da pokedex
    printf("\nDigite a próxima evolução do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].prxEvo);

    //calcula o total do novo pokemon da pokedex
    listaPokemon[(*numeroDePokemons) - 1].total = listaPokemon[(*numeroDePokemons) - 1].hp + listaPokemon[(*numeroDePokemons) - 1].atk + listaPokemon[(*numeroDePokemons) - 1].def + listaPokemon[(*numeroDePokemons) - 1].spdef + listaPokemon[(*numeroDePokemons) - 1].spatack + listaPokemon[(*numeroDePokemons) - 1].speed;

    //salva o numero do pokemon na pokedex de acordo com o numero de pokemons
    listaPokemon[(*numeroDePokemons) - 1].nPokedex = (*numeroDePokemons);

    //mostra ao usuario que o pokemon foi adicionado na pokedex
    printf("\nO Pokémon %s foi adicionado na Pokedex do jogo!\n", listaPokemon[(*numeroDePokemons) - 1].nome);

    return;
}//adicionarPokemonNaPokedex

//funcao utilizada para excluir o pokemon da pokedex
void excluirPokemonDaPokedex(Pokemon* listaPokemon, int* numeroDePokemons){

    //variaveis utilizadas na exclusao do pokemon da pokedex
    char pokemonExcluido[40];//nome do pokemon excluido
    int indiceDoPokemonExcluido;//indice do pokemon excluido
    int confirmaExclusao = 0;//variavel que confirma a exclusao
    char continuarExcluindo;//variavel que verifica se o usuario quer excluir caso nao encontre o pokemon


    do{
        //recebe o nome do pokemon a ser excluido
        printf("\nDigite o nome do pokémon a ser excluido:");
        leString(pokemonExcluido, 40);

        //verifica se o nome digitado corresponde a algum pokemon da pokedex
        for(int i = 0; i < (*numeroDePokemons); i++){
            //caso o nome digitado for igual ao nome de algum pokemon da pokedex, alerta ao usuario que o pokemon foi excluido
            if(strcasecmp(pokemonExcluido, listaPokemon[i].nome) == 0){
                printf("\nO pokémon %s foi excluído!\n", pokemonExcluido);
                confirmaExclusao++;//confirma a exclusao
                indiceDoPokemonExcluido = i;//salva o indice do pokemon excluido
                
                //copia todas as caracteristicas dos pokemons seguintes ao pokemon excluido para o pokemon anterior
                //esse for serve para apagar os dados do pokemon excluido, substituindo-os pelos dados do pokemon seguinte
                for(int j = i; j < (*numeroDePokemons) - 1; j++){
                    listaPokemon[j] = listaPokemon[j + 1];//substitui os dados do pokemon excluido pelos dados do pokemon seguinte
                }//for
                
                //reduz o numero de pokemons da pokedex
                (*numeroDePokemons)--;
                //reduz o tamanho do vetor dinamico para o novo numero de pokemons da pokedex
                listaPokemon = (Pokemon*) realloc(listaPokemon,(*numeroDePokemons) * sizeof(Pokemon));
                
                //ajusta os numeros dos pokemons da pokedex a partir do pokemon excluído
                for(int i = indiceDoPokemonExcluido; i < (*numeroDePokemons); i++){
                    //reduz em uma unidade os numeros da pokedex dos pokemons seguintes ao pokemon excluido
                    listaPokemon[i].nPokedex = listaPokemon[i].nPokedex - 1;
                }//for  
                
                break;
            }//if
        }//for

        //caso o pokemon digitado nao for encontrado na pokedex, mostra ao usuario que nenhum pokemon foi encontrado para ser excluido
        if(confirmaExclusao == 0){//verifica se a variavel confirmaExclusao foi alterada ou nao
            //verifica se o usuario quer digitar outro nome para excluir
            printf("\nNenhum pokémon foi encontrado! Deseja digitar novamente?(digite S ou N):");
            scanf("%c", &continuarExcluindo);
        }//if

    //caso o usuario queira tentar excluir novamente, solicita outro nome para ser excluido
    }while(continuarExcluindo == 's' || continuarExcluindo == 'S');

    return;
}//excluirPokemonDaPokedex

//funcao utilizada para listar os pokemons da pokedex
void listarPokemonsDaPokedex(Pokemon* listaPokemon, int numeroDePokemons){

    //mostra ao usuario que ele escolheu listar os pokemons da pokedex
    printf("\nVocê escolheu listar os pokémons da Pokedex!\nAqui estão todos os pokémons da Pokedex!\n");
    
    //lista os pokemons disponiveis na pokedex, mostrando o nome e o id de cada um
    for(int i = 0; i < numeroDePokemons; i++){
        printf("%d - %s\n", listaPokemon[i].nPokedex, listaPokemon[i].nome);
    }//for

    printf("\n");

    return;
}//listarPokemonsDaPokedex

//funcao utilizada para pesquisar pokemons na pokedex
void pesquisaPokemonNaPokedex(Pokemon* listaPokemon, int numeroDePokemons){

    //variaveis utilizadas para pesquisar o pokemon
    char pokemonPesquisado[40];//nome do pokemon a ser pesquisado
    int pokemonEncontrado = 0;//variavel utilizada para verificar se o pokemon foi encontrado
    char continuarNaProcura;//variavel que verifica se o usuario quer continuar procurando

    do{
    //solicita o nome de um pokemon a ser pesquisado
    printf("\nDigite o nome de um pokémon para pesquisá-lo na Pokedex:");
    leString(pokemonPesquisado, 40);

    //verifica se o pokemon pesquisado esta na pokedex ou nao
    for(int i = 0; i < numeroDePokemons; i++){
        if(strcasecmp(pokemonPesquisado, listaPokemon[i].nome) == 0){
            pokemonEncontrado++;//caso ele esteja na pokedex o contador sera acrescido
        }//if

        //caso o pokemon for encontrado, a variavel pokemonEncontrado terá sido alterada, e o programa mostrará os dados do pokemon pesquisado
        if(pokemonEncontrado > 0){
            //mostra todos os dados do pokemon pesquisado
            printf("\nPokemon encontrado!\n");
            printf("Número na Pokedex:%d\n", listaPokemon[i].nPokedex);
            printf("Nome:%s\n", listaPokemon[i].nome);
            printf("Tipo 1:%s\n", listaPokemon[i].tipo1);
            printf("Tipo 2:%s\n", listaPokemon[i].tipo2);
            printf("Total:%d\n", listaPokemon[i].total);
            printf("HP:%d\n", listaPokemon[i].hp);
            printf("Ataque:%d\n", listaPokemon[i].atk);
            printf("Defesa:%d\n", listaPokemon[i].def);
            printf("Ataque Especial:%d\n", listaPokemon[i].spatack);
            printf("Defesa Especial:%d\n", listaPokemon[i].spdef);
            printf("Velocidade:%d\n", listaPokemon[i].speed);
            printf("Geração:%d\n", listaPokemon[i].geracao);
            printf("Lendário:%d\n", listaPokemon[i].lendario);
            printf("Cor:%s\n", listaPokemon[i].cor);
            printf("Altura:%.2f\n", listaPokemon[i].altura);
            printf("Peso:%.2f\n", listaPokemon[i].peso);
            printf("Taxa de Captura:%.2f%%\n", listaPokemon[i].captura);
            printf("Pré-Evolução:%d\n", listaPokemon[i].preEvo);
            printf("Próxima-Evolução:%d\n", listaPokemon[i].prxEvo);
            break;
        }//if
    }//for

    //caso o pokemon nao for encontrado, mostra ao usuario que o pokemon pesquisado nao esta na pokedex
    if(pokemonEncontrado == 0){//verifica se a variavel pokemonEncontrado foi alterada ou nao
        //verifica se o usuario quer pesquisar novamente na pokedex, caso o pokemon nao tenha sido encontrado
        printf("\nO pokémon não foi encontrado na Pokedex! Deseja procurar novamente?(Digite S ou N):");
        scanf("%c", &continuarNaProcura);
    }//if

    //caso o usuario queira continuar pesquisando, o programa solicita novamente o nome a ser pesquisado
    }while((continuarNaProcura == 'S' || continuarNaProcura == 's') && pokemonEncontrado == 0);

    return;
}//pesquisaPokemonNaPokedex


//funcao utilizada para alterar o pokemon na pokedex
void alteraPokemonNaPokedex(Pokemon* listaPokemon, int numeroDePokemons){

    //variaveis utilizdas para alterar o pokemon na pokedex
    char pokemonPesquisado[40];//nome do pokemon a ser alterado
    Pokemon pokemonAlterado;
    int opcao;//opcao de atributo a ser alterado no pokemon

    //solicita o nome do pokemon a ser alterado na pokedex
    printf("\nVocê escolheu alterar um pokémon na Pokedex.\n");
    printf("Digite o nome do pokémon que você quer alterar:");
    leString(pokemonPesquisado, 40);

    //verifica se o nome pesquisado esta na pokedex
    for(int i = 0; i < numeroDePokemons; i++){
        //caso o pokemon for encontrado na pokedex, mostra ao usuario um menu com os atributos que podem ser alterados
        if(strcasecmp(pokemonPesquisado, listaPokemon[i].nome) == 0){

            //menu que permite ao usuario escolher o que quer alterar no pokemon
            do{
            printf("\nO pokémon %s foi encontrado!\n", pokemonPesquisado);
            printf("Você deseja alterar qual atributo dele?\n");
            printf("Nome - digite 1\n");
            printf("Tipo 1 - digite 2\n");
            printf("Tipo 2 - digite 3\n");
            printf("HP - 5 digite 4\n");
            printf("Ataque - digite 5\n");
            printf("Defesa - digite 6\n");
            printf("Ataque Especial - digite 7\n");
            printf("Defesa Especial - digite 8\n");
            printf("Velocidade - digite 9\n");
            printf("Geração - digite 10\n");
            printf("Lendário - digite 11\n");
            printf("Altura - digite 12\n");
            printf("Peso - digite 13\n");
            printf("Taxa de Captura - digite 14\n");
            printf("Voltar ao menu - digite 15\n");
            printf("Digite o número desejado:");
            scanf("%d", &opcao);
        
            //analisa a opcao inserida pelo usuario
            switch(opcao){

            //caso a opcao digitada pelo usuario for 1, o usuario poderá alterar o nome do pokemon na pokedex
            case 1:
                printf("\nVocê escolheu alterar o nome do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite o nome que você deseja colocar:");
                leString(pokemonAlterado.nome, 40);
                //copia o novo nome digitado pelo usuario para o nome do pokemon na pokedex
                strcpy(listaPokemon[i].nome, pokemonAlterado.nome);
                printf("\nNome alterado!\n");
                break;
            
            //caso a opcao digitada pelo usuario for 2, o usuario poderá alterar o tipo 1 do pokemon na pokedex
            case 2:
                printf("\nVocê escolheu alterar o tipo 1 do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite o tipo 1 que você deseja colocar:");
                leString(pokemonAlterado.tipo1, 10);
                //copia o novo tipo 1 digitado pelo usuario para o tipo 1 do pokemon na pokedex
                strcpy(listaPokemon[i].tipo1, pokemonAlterado.tipo1);
                printf("\nTipo 1 alterado!\n");
            break;

            //caso a opcao digitada pelo usuario for 3, o usuario poderá alterar o tipo 2 do pokemon na pokedex
            case 3:
                printf("\nVocê escolheu alterar o tipo 2 do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite o tipo 2 que você deseja colocar:");
                leString(pokemonAlterado.tipo2, 10);
                //copia o novo tipo 2 digitado pelo usuario para o tipo 2 do pokemon na pokedex
                strcpy(listaPokemon[i].tipo2, pokemonAlterado.tipo2);
                printf("\nTipo 2 alterado!\n");
            break;

            //caso a opcao digitada pelo usuario for 4, o usuario poderá alterar a vida do pokemon na pokedex
            case 4:
                printf("\nVocê escolheu alterar a vida do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite a vida que você deseja colocar:");
                scanf("%d", &pokemonAlterado.hp);
                //copia a nova vida digitada pelo usuario para a vida do pokemon na pokedex
                listaPokemon[i].hp = pokemonAlterado.hp;
                printf("\nVida alterada!\n");
            break;

            //caso a opcao digitada pelo usuario for 5, o usuario poderá alterar o ataque do pokemon na pokedex
            case 5:
                printf("\nVocê escolheu alterar o ataque do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite o ataque que você deseja colocar:");
                scanf("%d", &pokemonAlterado.atk);
                //copia o novo ataque digitado pelo usuario para o ataque do pokemon na pokedex
                listaPokemon[i].atk = pokemonAlterado.atk;
                printf("\nAtaque alterado!\n");
            break;

            //caso a opcao digitada pelo usuario for 6, o usuario poderá alterar a defesa do pokemon na pokedex
            case 6:
                printf("\nVocê escolheu alterar a defesa do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite a defesa que você deseja colocar:");
                scanf("%d", &pokemonAlterado.def);
                //copia a nova defesa digitada pelo usuario para a defesa do pokemon na pokedex
                listaPokemon[i].def = pokemonAlterado.def;
                printf("\nDefesa alterada!\n");
            break;

            //caso a opcao digitada pelo usuario for 7, o usuario poderá alterar o ataque especial do pokemon na pokedex
            case 7:
                printf("\nVocê escolheu alterar o ataque especial do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite o ataque especial que você deseja colocar:");
                scanf("%d", &pokemonAlterado.spatack);
                //copia o novo ataque especial digitado pelo usuario para o ataque especial do pokemon na pokedex
                listaPokemon[i].spatack = pokemonAlterado.spatack;
                printf("\nAtaque especial alterado!\n");
            break;

            //caso a opcao digitada pelo usuario for 8, o usuario poderá alterar a defesa especial do pokemon na pokedex
            case 8:
                printf("\nVocê escolheu alterar a defesa especial do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite a defesa especial que você deseja colocar:");
                scanf("%d", &pokemonAlterado.spdef);
                //copia a nova defesa especial digitada pelo usuario para a defesa especial do pokemon na pokedex
                listaPokemon[i].spdef = pokemonAlterado.spdef;
                printf("\nDefesa especial alterada!\n");
            break;

            //caso a opcao digitada pelo usuario for 9, o usuario poderá alterar a velocidade do pokemon na pokedex
            case 9:
                printf("\nVocê escolheu alterar a velocidade do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite a velocidade que você deseja colocar:");
                scanf("%d", &pokemonAlterado.speed);
                //copia a nova velocidade digitada pelo usuario para a velocidade do pokemon na pokedex
                listaPokemon[i].speed = pokemonAlterado.speed;
                printf("\nVelocidade alterada!\n");
            break;

            //caso a opcao digitada pelo usuario for 10, o usuario poderá alterar a geracao do pokemon na pokedex
            case 10:
                printf("\nVocê escolheu alterar a geração do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite a geração que você deseja colocar:");
                scanf("%d", &pokemonAlterado.geracao);
                //copia a nova geracao digitada pelo usuario para a geracao do pokemon na pokedex
                listaPokemon[i].geracao = pokemonAlterado.geracao;
                printf("\nGeração alterada!\n");
            break;

            //caso a opcao digitada pelo usuario for 11, o usuario poderá alterar o lendario do pokemon na pokedex
            case 11:
                printf("\nVocê escolheu mudar se o pokémon %s é lendário ou não!\n", listaPokemon[i].nome);
                printf("Digite 1 se o pokémon será lendário ou 0 se o pokémon não será lendário:");
                scanf("%d", &pokemonAlterado.lendario);
                //copia o novo lendario digitado pelo usuario para o lendario do pokemon na pokedex
                listaPokemon[i].lendario = pokemonAlterado.lendario;
                if(pokemonAlterado.lendario == 1){
                    //caso o pokemon virar lendario, o usuario sera avisado
                    printf("\nO pokémon %s agora é lendário!\n", listaPokemon[i].nome);
                }else{
                    //caso o pokemon nao for mais lendario, o usuario sera avisado
                    printf("\nO pokémon %s agora não é lendário!\n", listaPokemon[i].nome);
                }//else
            break;

            //caso a opcao digitada pelo usuario for 12, o usuario poderá alterar a altura do pokemon na pokedex
            case 12:
                printf("\nVocê escolheu alterar a altura do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite a altura que você deseja colocar:");
                scanf("%f", &pokemonAlterado.altura);
                //copia a nova altura digitada pelo usuario para a altura do pokemon na pokedex
                listaPokemon[i].altura = pokemonAlterado.altura;
                printf("\nAltura alterada!\n");
            break;

            //caso a opcao digitada pelo usuario for 13, o usuario poderá alterar o peso do pokemon na pokedex
            case 13:
                printf("\nVocê escolheu alterar o peso do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite o peso que você deseja colocar:");
                scanf("%f", &pokemonAlterado.peso);
                //copia o novo peso digitado pelo usuario para o peso do pokemon na pokedex
                listaPokemon[i].peso = pokemonAlterado.peso;
                printf("\nPeso alterado!\n");
            break;

            //caso a opcao digitada pelo usuario for 14, o usuario poderá alterar a taxa de captura do pokemon na pokedex
            case 14:
                printf("\nVocê escolheu alterar a taxa de captura do pokémon %s!\n", listaPokemon[i].nome);
                printf("Digite a taxa de captura que você deseja colocar:");
                scanf("%f", &pokemonAlterado.captura);
                //copia a nova taxa de captura digitada pelo usuario para a taxa de captura do pokemon na pokedex
                listaPokemon[i].captura = pokemonAlterado.captura;
                printf("\nTaxa de captura alterada!\n");
            break;

            //caso a opcao digitada pelo usuario for 15, o usuario voltará ao menu principal do jogo
            case 15:
                //recalcula o total do pokemon na pokedex caso o usuario tenha alterado algum atributo relacionado ao total
                listaPokemon[i].total = listaPokemon[i].hp + listaPokemon[i].atk + listaPokemon[i].def + listaPokemon[i].spdef + listaPokemon[i].spatack + listaPokemon[i].speed;
                printf("\nVoltando para o menu...\n");
                return;
            break;

            //caso o usuario nao digite nenhuma das opcoes acima, ele sera avisado e podera digitar novamente 
            default:
                printf("\nOpção não encontrada! Digite novamente!\n");
                break;
            }//switch
            }while(opcao != 15);//podera alterar enquanto nao digitar 15 para retornar ao menu
        }//if
    }//for

    return;
}//alteraPokemonNaPokedex
*/
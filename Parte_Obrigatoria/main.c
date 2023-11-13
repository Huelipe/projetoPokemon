#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "estruturas.h"
#include "funcoes.h"

int main(){

    srand(time(NULL));
    // Código necessário para funcionamento do randomizador

    FILE *arquivo;//ponteiro para tratar o .csv
    Pokemon* listaPokemon;//lista de pokemons para armazenar os pokemons lidos do .csv
    int numeroDePokemons = 721;//numero total de pokemons
    int tamanhoPrimeiraLinhaCSV;//variavel para o tamanho da primeira linha do .csv, utilizada no fseek para pular a leitura da primeira linha

    Colecao* colecaoDePokemons;//armazena os ids dos pokemons na colecao
    int totalPokesNaColecao = 0;//numero total de pokemons da colecao

    arquivo = fopen("../pokedex.csv", "r+");//abre o arquivo .csv para leitura

    if (arquivo == NULL) {//verifica se houve erro na abertura do arquivo
        perror("Erro ao abrir o arquivo");
        return 1;
    }//if

    //calcula o numero de bytes da primeira linha do .csv para utilizar na funcao fseek
    tamanhoPrimeiraLinhaCSV = sizeof("numero ,nome        ,tipo1    ,tipo2    ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura");

    //aloca dinamicamente a lista de pokemons para o numero de pokemons do jogo
    listaPokemon = (Pokemon*) malloc(numeroDePokemons * sizeof(Pokemon));

    //pula o "ponteiro" da leitura do .csv para a segunda linha, de acordo com o numero de bytes da primeira linha
    fseek(arquivo, tamanhoPrimeiraLinhaCSV, SEEK_SET);

    //le o arquivo .csv
    for(int i = 1; i < 722; i++){
        fscanf(arquivo, "%d ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%s ,%f ,%f ,%f \n", &listaPokemon[i].nPokedex, listaPokemon[i].nome, listaPokemon[i].tipo1, listaPokemon[i].tipo2, &listaPokemon[i].total, &listaPokemon[i].hp, &listaPokemon[i].atk, &listaPokemon[i].def, &listaPokemon[i].spatack, &listaPokemon[i].spdef, &listaPokemon[i].speed, &listaPokemon[i].geracao, &listaPokemon[i].lendario, listaPokemon[i].cor, &listaPokemon[i].altura, &listaPokemon[i].peso, &listaPokemon[i].captura);
    }//for

    //fecha o arquivo .csv
    fclose(arquivo);

    //variaveis utilizadas no menu do jogo
	int EscolheFuncao;
    int EscolheSubFuncao;

    do{
    //menu do jogo
    printf("MENU\n");
    printf("1 -> Pokedex\n2 -> Colecao\n3 -> Mochila\n4 -> Guia\n5 -> Configuracoes\n6 -> Sair do jogo\n");

    //recebe a opcao do menu do usuario
    printf("Digite uma das opcoes acima: ");
    scanf("%d", &EscolheFuncao);

    //caso escolha Pokedex no menu, entra no submenu da Pokedex
    switch(EscolheFuncao){
        case 1:
            //submenu da Pokedex
            printf("\nSUBMENU POKEDEX\n");
            printf("1 -> Inserir Pokemons\n2 -> Listar Pokemons\n3 -> Pesquisar Pokemons\n4 -> Alterar Pokemons\n5 -> Excluir Pokemons\n");
            scanf("%d", &EscolheSubFuncao);

            //analisa a escolha no submenu da pokedex
            switch(EscolheSubFuncao){
                case 1://funcao de adicionar pokemons na pokedex
                    adicionarPokemonNaPokedex(listaPokemon, &numeroDePokemons);
                    printf("\n\nNome:%s\n\n",listaPokemon[numeroDePokemons - 1].nome);
                    break;

                case 2://funcao de listar pokemons da pokedex
                    listarPokemonsDaPokedex(listaPokemon, numeroDePokemons);
                    break;

                case 3://funcao de pesquisar pokemons na pokedex
                    pesquisaPokemonNaPokedex(listaPokemon, numeroDePokemons);
                    break;

                case 4://funcao de alterar pokemons na pokedex
                    alteraPokemonNaPokedex(listaPokemon, numeroDePokemons);
                    break;

                case 5://funcao de excluir pokemons da pokedex
                    excluirPokemonDaPokedex(listaPokemon, &numeroDePokemons);
                    break;

                default://caso o usuario nao digite nenhuma opcao acima
                    printf("Opcao nao encontrada!\n");

                    break;    
                }//switch

        break;        

        case 2://caso o usuario escolha o submenu da colecao, entra no submenu da colecao
            //submenu colecao
            printf("\nSUBMENU COLECAO\n");
            printf("1 -> Inserir Pokemons\n2 -> Listar Pokemons\n3 -> Pesquisar Pokemons\n4 -> Alterar Pokemons\n5 -> Excluir Pokemons\n");
            scanf("%d", &EscolheSubFuncao);

            //analisa a escolha no submenu da colecao
            switch(EscolheSubFuncao){
                case 1://funcao de adicionar pokemons na colecao
                    adicionarPokemonNaColecao(&colecaoDePokemons, &totalPokesNaColecao, numeroDePokemons, listaPokemon);
                    break;

                case 2://funcao de listar pokemons da colecao 
                    listaPokemonsNaColecao(colecaoDePokemons, totalPokesNaColecao, listaPokemon);
                    break;

                case 3://funcao de pesquisar pokemons na colecao
                    pesquisaPorPokemonNaColecao(colecaoDePokemons, totalPokesNaColecao, listaPokemon);
                    break;

                case 4://funcao de alterar pokemons da colecao
                    alterarPokemonDaColecao(colecaoDePokemons, totalPokesNaColecao, listaPokemon);
                    break;

                case 5://funcao de excluir pokemons da colecao
                    excluirPokemonDaColecao(&colecaoDePokemons, &totalPokesNaColecao);
                    break;

                default://caso o usuario nao digite nenhuma das opcoes acima
                    printf("Opcao nao encontrada!\n");

                    break;    
                }//switch
        break;

        case 3://caso o usuario escolha o submenu da mochila, entra no submenu da mochila
            //submenu da mochila
            printf("SUBMENU MOCHILA\n");
            printf("1 -> Inserir Pokemon na mochila\n2 -> Trocar Pokemon inserido\n");
            scanf("%d", &EscolheSubFuncao);

                //analisa a escolha do submenu mochila
                switch(EscolheSubFuncao){
                    case 1://funcao de adicionar pokemon na mochila
                        printf("Opcao nao encontrada!\n");
                        break;

                    case 2://funcao de trocar pokemon da mochila
                        printf("Opcao nao encontrada!\n");
                        break;

                    default://caso o usuario nao digite nenhuma das opcoes acima
                        printf("Opcao nao encontrada!\n");

                        break;        
                }//switch

            break;

        case 4:
            printf("Opcao nao encontrada!\n");
            break;

        case 5:
            printf("SUBMENU CONFIGURACOES\n");
            break;

        //opcao para sair do jogo
        case 6:
            
            break;      

        //caso o usuario nao digite nenhuma das opcoes do menu principal
        default:
            printf("Opcao nao encontrada\n");

            break;        
    }//switch

    }while(EscolheFuncao != 6);//enquanto o usuario nao digitar 6 para sair do jogo, o menu continua rodando                        

    //liberando memoria
    free(listaPokemon);
    free(colecaoDePokemons);

return 0;
}//main
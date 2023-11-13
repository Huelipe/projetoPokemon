#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "estruturas.h"
#include "funcoes.h"

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

	    int EscolheFuncao;
    int EscolheSubFuncao;

    do{
    printf("MENU\n");
    printf("1 -> Pokedex\n2 -> Colecao\n3 -> Mochila\n4 -> Guia\n5 -> Configuracoes\n6 -> Sair do jogo\n");

    printf("Digite uma das opcoes acima: ");
    scanf("%d", &EscolheFuncao);

    switch(EscolheFuncao){
        case 1:
            printf("\nSUBMENU POKEDEX\n");
            printf("1 -> Inserir Pokemons\n2 -> Listar Pokemons\n3 -> Pesquisar Pokemons\n4 -> Alterar Pokemons\n5 -> Excluir Pokemons\n");
            scanf("%d", &EscolheSubFuncao);

            switch(EscolheSubFuncao){
                case 1:
                    adicionarPokemonNaPokedex(listaPokemon, &numeroDePokemons);
                    printf("\n\nNome:%s\n\n",listaPokemon[numeroDePokemons - 1].nome);
                    break;

                case 2:
                    listarPokemonsDaPokedex(listaPokemon, numeroDePokemons);
                    break;

                case 3:
                    pesquisaPokemonNaPokedex(listaPokemon, numeroDePokemons);
                    break;

                case 4:
                    printf("Opcao nao encontrada!\n");
                    break;

                case 5:
                    excluirPokemonDaPokedex(listaPokemon, &numeroDePokemons);
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
            printf("SUBMENU MOCHILA\n");
            printf("1 -> Inserir Pokemon na mochila\n2 -> Trocar Pokemon inserido\n");
            scanf("%d", &EscolheSubFuncao);

                switch(EscolheSubFuncao){
                    case 1:
                        printf("Opcao nao encontrada!\n");
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
            printf("Opcao nao encontrada!\n");
            break;

        case 5:
            printf("SUBMENU CONFIGURACOES\n");
            break;

        case 6:
            
            break;      

        default:
            printf("Opcao nao encontrada\n");

            break;        
    }

    }while(EscolheFuncao != 6);                            

    free(listaPokemon);
    free(colecaoDePokemons);

return 0;
}


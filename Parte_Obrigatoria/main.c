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

    FILE *arquivo; //ponteiro para tratar o .csv
    FILE *arquivoBinarioPokedex;//ponteiro para tratar arquivo binario da pokedex
    FILE *arquivoBinarioColecao;//ponteiro para tratar arquivo binario da colecao
    FILE *arquivoBinarioMochila;//ponteiro para tratar arquivo binario da mochila
    FILE *arquivoBinarioDados;//ponteiro para tratar arquivo binario dos numeros de pokedex, colecao, mochila
    Pokemon* listaPokemon; //lista de pokemons para armazenar os pokemons lidos do .csv
    int tamanhoPrimeiraLinhaCSV;//variavel para salvar o tamanho da primeira linha .csv

    Colecao* colecaoDePokemons; //armazena os ids dos pokemons na colecao

    //variavel para salvar id na mochila
    Mochila mochila[6];

    //variavel para salvar os dados: numero de pokedex, colecoa e mochila
    Dados dadosSalvos;

    //abre os binarios para leitura
    arquivoBinarioPokedex = fopen("Arquivos_Binarios/Pokedex.dat", "rb");
    arquivoBinarioColecao = fopen("Arquivos_Binarios/Colecao.dat", "rb");
    arquivoBinarioMochila = fopen("Arquivos_Binarios/Mochila.dat", "rb");
    arquivoBinarioDados = fopen("Arquivos_Binarios/Dados.dat", "rb");

    if(arquivoBinarioPokedex == NULL && arquivoBinarioColecao == NULL && arquivoBinarioMochila == NULL){
        arquivo = fopen("pokedex.csv", "r+"); //abre o arquivo .csv para leitura
        dadosSalvos.totalMochila = 0;//numero total de pokemons da mochila
        dadosSalvos.numeroDePokemons = 721;//numero total de pokemons da pokedex
        dadosSalvos.totalPokesNaColecao = 0; //numero total de pokemons da colecao

        if (arquivo == NULL) {
            perror("Erro ao abrir o arquivo");
            return 1;
        } //verifica se houve erro na abertura do arquivo

    tamanhoPrimeiraLinhaCSV = sizeof("numero ,nome        ,tipo1    ,tipo2    ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura");
    //calcula o numero de bytes da primeira linha do .csv para utilizar na funcao fseek

    listaPokemon = (Pokemon*) malloc(dadosSalvos.numeroDePokemons * sizeof(Pokemon));
    //aloca dinamicamente a lista de pokemons para o numero de pokemons do jogo
    if(listaPokemon == NULL){
        printf("Erro: Memória Pokedex Insuficiente!\n");
        exit(1);
    }//if

    colecaoDePokemons = (Colecao*) malloc(dadosSalvos.totalPokesNaColecao * sizeof(Colecao));
    //aloca dinamicamente a coleção para o numero de pokemons na colecao
    if(colecaoDePokemons == NULL){
        printf("Erro: Memória Colecao Insuficiente!\n");
        exit(1);
    }//if

    fseek(arquivo, tamanhoPrimeiraLinhaCSV, SEEK_SET);
    //pula o "ponteiro" da leitura do .csv para a segunda linha, de acordo com o numero de bytes da primeira linha

    for(int i = 0; i < dadosSalvos.numeroDePokemons; i++){
        fscanf(arquivo, "%d ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%s ,%f ,%f ,%f \n", &listaPokemon[i].nPokedex, listaPokemon[i].nome, listaPokemon[i].tipo1, listaPokemon[i].tipo2, &listaPokemon[i].total, &listaPokemon[i].hp, &listaPokemon[i].atk, &listaPokemon[i].def, &listaPokemon[i].spatack, &listaPokemon[i].spdef, &listaPokemon[i].speed, &listaPokemon[i].geracao, &listaPokemon[i].lendario, listaPokemon[i].cor, &listaPokemon[i].altura, &listaPokemon[i].peso, &listaPokemon[i].captura);
    }//for
    //le o arquivo .csv

    fclose(arquivo);

    //mensagem de boas vindas na primeira vez
    printf("\n\nBem-vindo ao jogo de Pokémon!\n\n");

    }else{

        //le os arquivos binarios com os dados
        fread(&dadosSalvos, sizeof(Dados), 1, arquivoBinarioDados);

        listaPokemon = (Pokemon*) malloc(dadosSalvos.numeroDePokemons * sizeof(Pokemon));
        //aloca dinamicamente a lista de pokemons para o numero de pokemons do jogo
        if(listaPokemon == NULL){
            printf("Erro: Memória Pokedex Insuficiente!\n");
            exit(1);
        }//if
        
        colecaoDePokemons = (Colecao*) malloc(dadosSalvos.totalPokesNaColecao * sizeof(Colecao));
        //aloca dinamicamente a coleção para o numero de pokemons na colecao
        if(colecaoDePokemons == NULL){
            printf("Erro: Memória Colecao Insuficiente!\n");
            exit(1);
        }//if

        //le os arquivos binarios da pokedex, da colecao e da mochila
        fread(listaPokemon, sizeof(Pokemon), dadosSalvos.numeroDePokemons, arquivoBinarioPokedex);
        fread(colecaoDePokemons, sizeof(Colecao), dadosSalvos.totalPokesNaColecao, arquivoBinarioColecao);
        fread(mochila, sizeof(Mochila), 6, arquivoBinarioMochila);

        fclose(arquivoBinarioDados);
        fclose(arquivoBinarioPokedex);
        fclose(arquivoBinarioColecao);
        fclose(arquivoBinarioMochila);
        //fecha os arquivos

        //mensagem de boas vindas nas demais vezes
        printf("\n\nSeja bem-vindo de volta ao jogo de Pokémon!\n\n");
    }//else

    //variaveis utilizadas no menu do jogo
    int EscolheFuncao;
    int EscolheSubFuncao;

    //variaveis utilizadas para definir os arquivos onde será salvo os dados exportados
    const char *nomeArquivo1 = "DadosCSV/DadosPokedex.csv";
    const char *nomeArquivo2 = "DadosCSV/DadosColecao.csv";
    const char *nomeArquivo3 = "DadosCSV/DadosMochila.csv";

    do{
    //menu do jogo
    printf("MENU POKÉMON\n");
    printf("1 -> Pokedex\n2 -> Coleção\n3 -> Mochila\n4 -> Exportar Dados\n5 -> Sair do jogo\n");

    //recebe a opcao do menu do usuario
    printf("Digite uma das opções acima: ");
    scanf("%d", &EscolheFuncao);

    //caso escolha Pokedex no menu, entra no submenu da Pokedex
    switch(EscolheFuncao){
        case 1:
            //submenu da Pokedex
            printf("\nSUBMENU POKEDEX\n");
            printf("1 -> Inserir Pokémons\n2 -> Listar Pokémons\n3 -> Pesquisar Pokémons\n4 -> Alterar Pokémons\n5 -> Excluir Pokémons\n");
            scanf("%d", &EscolheSubFuncao);

            //analisa a escolha no submenu da pokedex
            switch(EscolheSubFuncao){
                case 1://funcao de adicionar pokemons na pokedex
                    adicionarPokemonNaPokedex(&listaPokemon, &dadosSalvos.numeroDePokemons);
                    break;

                case 2://funcao de listar pokemons da pokedex
                    listarPokemonsDaPokedex(listaPokemon, dadosSalvos.numeroDePokemons);
                    break;

                case 3://funcao de pesquisar pokemons na pokedex
                    pesquisaPokemonNaPokedex(listaPokemon, dadosSalvos.numeroDePokemons);
                    break;

                case 4://funcao de alterar pokemons na pokedex
                    alteraPokemonNaPokedex(listaPokemon, dadosSalvos.numeroDePokemons);
                    break;

                case 5://funcao de excluir pokemons da pokedex
                    excluirPokemonDaPokedex(listaPokemon, &dadosSalvos.numeroDePokemons);
                    break;

                default://caso o usuario nao digite nenhuma opcao acima
                    printf("Opcao nao encontrada!\n");

                    break;    
                }//switch

        break;        

        case 2://caso o usuario escolha o submenu da colecao, entra no submenu da colecao
            //submenu colecao
            printf("\nSUBMENU COLEÇÃO\n");
            printf("1 -> Inserir Pokémons\n2 -> Listar Pokémons\n3 -> Pesquisar Pokémons\n4 -> Alterar Pokémons\n5 -> Excluir Pokémons\n");
            scanf("%d", &EscolheSubFuncao);

            //analisa a escolha no submenu da colecao
            switch(EscolheSubFuncao){
                case 1://funcao de adicionar pokemons na colecao
                    adicionarPokemonNaColecao(&colecaoDePokemons, &dadosSalvos.totalPokesNaColecao, dadosSalvos.numeroDePokemons, listaPokemon);
                    break;

                case 2://funcao de listar pokemons da colecao 
                    listaPokemonsNaColecao(colecaoDePokemons, dadosSalvos.totalPokesNaColecao, listaPokemon, dadosSalvos.numeroDePokemons);
                    break;

                case 3://funcao de pesquisar pokemons na colecao
                    pesquisaPorPokemonNaColecao(colecaoDePokemons, dadosSalvos.totalPokesNaColecao, listaPokemon);
                    break;

                case 4://funcao de alterar pokemons da colecao
                    alterarPokemonDaColecao(&colecaoDePokemons, dadosSalvos.totalPokesNaColecao, &listaPokemon, dadosSalvos.numeroDePokemons);
                    break;

                case 5://funcao de excluir pokemons da colecao
                    excluirPokemonDaColecao(&colecaoDePokemons, &dadosSalvos.totalPokesNaColecao);
                    break;

                default://caso o usuario nao digite nenhuma das opcoes acima
                    printf("Opção não encontrada!\n");

                    break;    
                }//switch
        break;

        case 3://caso o usuario escolha o submenu da mochila, entra no submenu da mochila
            //submenu da mochila
            printf("SUBMENU MOCHILA\n");
            printf("Na mochila só podem conter até 6 Pokémons!\n");
            printf("1 -> Inserir Pokémon na mochila\n2 -> Listar mochila\n3 -> Excluir da mochila\n");
            scanf("%d", &EscolheSubFuncao);

                //analisa a escolha do submenu mochila
                switch(EscolheSubFuncao){
                    case 1://funcao de adicionar pokemon na mochila
                        InserirNaMochila(mochila, colecaoDePokemons, &dadosSalvos.totalPokesNaColecao, listaPokemon, dadosSalvos.numeroDePokemons, &dadosSalvos.totalMochila);

                        break;

                    case 2://funcao de listar pokemon da mochila
                        ListaMochila(dadosSalvos.totalMochila, mochila, listaPokemon, dadosSalvos.numeroDePokemons);
                        break;

                    case 3://funcao de excluir pokemon da mochila
                        ExcluirMochila(mochila, colecaoDePokemons, &dadosSalvos.totalPokesNaColecao, &dadosSalvos.totalMochila, listaPokemon, dadosSalvos.numeroDePokemons);
                        break;    

                    default://caso o usuario nao digite nenhuma das opcoes acima
                        printf("Opção não encontrada!\n");
                        break;        
                }//switch

            break;

        case 4://caso o usuario queira exportar os dados do jogo para um arquivo .csv
            //exporta os arquivos para csv
            exportarPokemonParaCSV(listaPokemon, dadosSalvos.numeroDePokemons, nomeArquivo1); //exporta dados da pokedex para um arquivo .csv
            exportarColecaoParaCSV(colecaoDePokemons, dadosSalvos.totalPokesNaColecao, listaPokemon, nomeArquivo2); //exporta dados da coleção para um arquivo .csv
            exportarMochilaParaCSV(mochila, listaPokemon, dadosSalvos.totalMochila, nomeArquivo3);//exporta dados da mochila para arquivo csv
            break;

        case 5://caso o usuario saia do jogo
            //abre os arquivos binários para escrita
            arquivoBinarioPokedex = fopen("Arquivos_Binarios/Pokedex.dat", "wb");
            if(arquivoBinarioPokedex == NULL){
                printf("Erro ao abrir o arquivo Pokedex!\n");
                exit(1);
            }//if

            arquivoBinarioColecao = fopen("Arquivos_Binarios/Colecao.dat", "wb");
            if(arquivoBinarioColecao == NULL){
                printf("Erro ao abrir o arquivo Colecao!\n");
                exit(1);
            }//if
            
            arquivoBinarioMochila = fopen("Arquivos_Binarios/Mochila.dat", "wb");
            if(arquivoBinarioMochila == NULL){
                printf("Erro ao abrir o arquivo Mochila!\n");
                exit(1);
            }//if
            
            arquivoBinarioDados = fopen("Arquivos_Binarios/Dados.dat", "wb");
            if(arquivoBinarioDados == NULL){
                printf("Erro ao abrir o arquivo Dados!\n");
                exit(1);
            }//if

            //escreve os dados nos arquivos binários
            fwrite(listaPokemon, sizeof(Pokemon), dadosSalvos.numeroDePokemons, arquivoBinarioPokedex);
            fwrite(colecaoDePokemons, sizeof(Colecao), dadosSalvos.totalPokesNaColecao, arquivoBinarioColecao);
            fwrite(mochila, sizeof(Mochila), 6, arquivoBinarioMochila);
            fwrite(&dadosSalvos, sizeof(Dados), 1, arquivoBinarioDados);

            fclose(arquivoBinarioPokedex);
            fclose(arquivoBinarioColecao);
            fclose(arquivoBinarioMochila);
            fclose(arquivoBinarioDados);
            //fecha os arquivos
            break;

        //caso o usuario nao digite nenhuma das opcoes do menu principal
        default:
            printf("Opção não encontrada\n");

            break;        
    }//switch

    }while(EscolheFuncao != 5);//enquanto o usuario nao digitar 5 para sair do jogo, o menu continua rodando                        

    //liberando memoria
    free(listaPokemon);
    free(colecaoDePokemons);

return 0;
}//main
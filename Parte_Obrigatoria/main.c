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
    FILE *arquivoBinarioPokedex;//trata o arquivo binario da pokedex
    FILE *arquivoBinarioColecao;//trata o arquivo binario da colecao
    FILE *arquivoBinarioMochila;//trata o arquivo binario da mochila
    FILE *arquivoBinarioDados;//trata o arquivo binario dos dados
    Pokemon* listaPokemon; //lista de pokemons para armazenar os pokemons lidos do .csv
    int tamanhoPrimeiraLinhaCSV;//variavel que salva o tamanho da linha do csv

    Colecao* colecaoDePokemons; //armazena os ids dos pokemons na colecao

    Mochila mochila[6];//vetor que salva os dados da mochila

    Dados dadosSalvos;//salva os numeros da pokedex, colecao e da mochila

    arquivoBinarioPokedex = fopen("Pokedex.dat", "rb");
    arquivoBinarioColecao = fopen("Colecao.dat", "rb");
    arquivoBinarioMochila = fopen("Mochila.dat", "rb");
    arquivoBinarioDados = fopen("Dados.dat", "rb");

    if(arquivoBinarioPokedex == NULL && arquivoBinarioColecao == NULL && arquivoBinarioMochila == NULL){
            arquivo = fopen("pokedex.csv", "r+"); //abre o arquivo .csv para leitura
            dadosSalvos.totalMochila = 0;
            dadosSalvos.numeroDePokemons = 721;
            dadosSalvos.totalPokesNaColecao = 0;

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    } //verifica se houve erro na abertura do arquivo

    tamanhoPrimeiraLinhaCSV = sizeof("numero ,nome        ,tipo1    ,tipo2    ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura");
    //calcula o numero de bytes da primeira linha do .csv para utilizar na funcao fseek

    listaPokemon = (Pokemon*) malloc(dadosSalvos.numeroDePokemons * sizeof(Pokemon));
    //aloca dinamicamente a lista de pokemons para o numero de pokemons do jogo
    colecaoDePokemons = (Colecao*) malloc(dadosSalvos.totalPokesNaColecao * sizeof(Colecao));
    //aloca dinamicamente a coleção para o numero de pokemons na colecao

    fseek(arquivo, tamanhoPrimeiraLinhaCSV, SEEK_SET);
    //pula o "ponteiro" da leitura do .csv para a segunda linha, de acordo com o numero de bytes da primeira linha

    for(int i = 0; i < dadosSalvos.numeroDePokemons; i++){
        fscanf(arquivo, "%d ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%s ,%f ,%f ,%f \n", &listaPokemon[i].nPokedex, listaPokemon[i].nome, listaPokemon[i].tipo1, listaPokemon[i].tipo2, &listaPokemon[i].total, &listaPokemon[i].hp, &listaPokemon[i].atk, &listaPokemon[i].def, &listaPokemon[i].spatack, &listaPokemon[i].spdef, &listaPokemon[i].speed, &listaPokemon[i].geracao, &listaPokemon[i].lendario, listaPokemon[i].cor, &listaPokemon[i].altura, &listaPokemon[i].peso, &listaPokemon[i].captura);
    }//for
    //le o arquivo .csv

    fclose(arquivo);
    }else{

        fread(&dadosSalvos, sizeof(Dados), 1, arquivoBinarioDados);

        listaPokemon = (Pokemon*) malloc(dadosSalvos.numeroDePokemons * sizeof(Pokemon));
        //aloca dinamicamente a lista de pokemons para o numero de pokemons do jogo
        colecaoDePokemons = (Colecao*) malloc(dadosSalvos.totalPokesNaColecao * sizeof(Colecao));
        //aloca dinamicamente a coleção para o numero de pokemons na colecao

        fread(listaPokemon, sizeof(Pokemon), dadosSalvos.numeroDePokemons, arquivoBinarioPokedex);
        fread(colecaoDePokemons, sizeof(Colecao), dadosSalvos.totalPokesNaColecao, arquivoBinarioColecao);
        fread(mochila, sizeof(Mochila), 6, arquivoBinarioMochila);

        fclose(arquivoBinarioDados);
        fclose(arquivoBinarioPokedex);
        fclose(arquivoBinarioColecao);
        fclose(arquivoBinarioMochila);
        //fecha os arquivos

    }

    //variaveis utilizadas no menu do jogo
    int EscolheFuncao;
    int EscolheSubFuncao;

    //variaveis utilizadas para definir os arquivos onde será salvo os dados exportados
    const char *nomeArquivo1 = "DadosPokedex.csv";
    const char *nomeArquivo2 = "DadosColecao.csv";
    const char *nomeArquivo3 = "DadosMochila.csv";

    do{
    //menu do jogo
    printf("MENU\n");
    printf("1 -> Pokedex\n2 -> Colecao\n3 -> Mochila\n4 -> Exportar Dados\n5 -> Sair do jogo\n");

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
            printf("\nSUBMENU COLECAO\n");
            printf("1 -> Inserir Pokemons\n2 -> Listar Pokemons\n3 -> Pesquisar Pokemons\n4 -> Alterar Pokemons\n5 -> Excluir Pokemons\n");
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
                    alterarPokemonDaColecao(colecaoDePokemons, dadosSalvos.totalPokesNaColecao, listaPokemon);
                    break;

                case 5://funcao de excluir pokemons da colecao
                    excluirPokemonDaColecao(&colecaoDePokemons, &dadosSalvos.totalPokesNaColecao);
                    break;

                default://caso o usuario nao digite nenhuma das opcoes acima
                    printf("Opcao nao encontrada!\n");

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
                        ListaMochila(mochila, listaPokemon, dadosSalvos.numeroDePokemons);
                        break;

                    case 3://funcao que exclui pokemon da mochila
                        ExcluirMochila(mochila, colecaoDePokemons, &dadosSalvos.totalPokesNaColecao, &dadosSalvos.totalMochila, listaPokemon, dadosSalvos.numeroDePokemons);
                        break;    

                    default://caso o usuario nao digite nenhuma das opcoes acima
                        printf("Opção não encontrada.");
                        break;        
                }//switch

            break;

        case 4:
            exportarPokemonParaCSV(listaPokemon, dadosSalvos.numeroDePokemons, nomeArquivo1); //exporta dados da pokedex para um arquivo .csv
            exportarColecaoParaCSV(colecaoDePokemons, dadosSalvos.totalPokesNaColecao, listaPokemon, nomeArquivo2); //expora dados da coleção para um arquivo .csv
            exportarMochilaParaCSV(mochila, listaPokemon, dadosSalvos.totalMochila, nomeArquivo3);
            break;

        case 5:
            //abre os arquivos para escrita binaria
            arquivoBinarioPokedex = fopen("Pokedex.dat", "wb");
            arquivoBinarioColecao = fopen("Colecao.dat", "wb");
            arquivoBinarioMochila = fopen("Mochila.dat", "wb");
            arquivoBinarioDados = fopen("Dados.dat", "wb");

            //escreve os dados do jogo
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
            printf("Opcao nao encontrada\n");

            break;        
    }//switch

    }while(EscolheFuncao != 5);//enquanto o usuario nao digitar 5 para sair do jogo, o menu continua rodando                        

    //liberando memoria
    free(listaPokemon);
    free(colecaoDePokemons);

return 0;
}//main

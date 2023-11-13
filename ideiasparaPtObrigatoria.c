#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

typedef struct{
    int numero;
    char nome[52];
    char tipo1[22];
    char tipo2[22];
    int total;
    int hp;
    int ataque;
    int defesa;
    int ataqueEspecial;
    int defesaEspecial;
    int velocidade;
    int geracao;
    int lendario;
    char cor[22];
    float altura;
    float peso;
    int taxaCaptura;
    int proximaEvolucao;
    int preEvolucao;
} Pokemon;

typedef struct{
    Pokemon* dadosPokemon; 
    int *idPokemonsCapturados;
    int qtdPokemonsCapturados;
} Colecao;

typedef struct{
    //int qtdPokebolas;
    int *idPokemonsMochila;
    int qtdPokemonsMochila;
} Mochila;

void adicionarPokemonColecao(Colecao* colecao, int idPokemonCapturado); 
void adicionarPokemonMochila(Mochila* mochila, int idPokemonCapturado); 
void listarPokemonsCapturados(Colecao* colecao);
void listarPokemonsMochila(Colecao* colecao, Mochila* mochila);
void excluirPokemonCapturado(Colecao* colecao);
void excluirPokemonMochila(Mochila* mochila);
void exibirDadosUltimoPokemonCapturado(Colecao* colecao);
void pesquisarPokemonsCapturados(Colecao* colecao);

int main(){
    FILE* arquivoPokemonCSV;
    arquivoPokemonCSV = fopen("../pokedex.csv", "r");

    if(arquivoPokemonCSV == NULL){
        perror("Erro ao abrir arquivo pokedex");
        exit(1);
    }

    Colecao colecao;
    colecao.dadosPokemom = (Pokemon*) malloc(722 * sizeof(Pokemon));
    colecao.qtdPokemonsCapturados = 0;

    Mochila mochila;
    mochila.qtdPokemonsMochila = 0;

    fscanf(arquivoPokemonCSV, "%*[^\n]\n");
    for(int i = 0; i < 721; i++){
        fscanf(arquivoPokemonCSV, "%d ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%s ,%f ,%f ,%d", &colecao.dadosPokemon[i].numero, colecao.dadosPokemon[i].nome, colecao.dadosPokemon[i].tipo1, colecao.dadosPokemon[i].tipo2, &colecao.dadosPokemon[i].total, &colecao.dadosPokemon[i].hp, &colecao.dadosPokemon[i].ataque, &colecao.dadosPokemon[i].defesa, &colecao.dadosPokemon[i].ataqueEspecial, &colecao.dadosPokemon[i].defesaEspecial, &colecao.dadosPokemon[i].velocidade, &colecao.dadosPokemon[i].geracao, &colecao.dadosPokemon[i].lendario, colecao.dadosPokemon[i].cor, &colecao.dadosPokemon[i].altura, &colecao.dadosPokemon[i].peso, &colecao.dadosPokemon[i].taxaCaptura);
    }//for

    adicionarPokemonColecao(&colecao, 120);
    adicionarPokemonColecao(&colecao, 210);
    adicionarPokemonColecao(&colecao, 115);
    adicionarPokemonColecao(&colecao, 204);
    adicionarPokemonColecao(&colecao, 433);

    int opcao;
    int opcao1;
    int opcao2;

    do{

        printf("##########################\n");
        printf("#      MENU DO JOGO      #\n");
        printf("##########################\n");
        printf("1 - Colecao.\n");
        printf("2 - Mochila.\n");
        printf("3 - Loja.\n");
        printf("4 - Perfil do Usuario.\n");
        printf("5 - Configuracoes.\n");
        printf("6 - Mapa de Niveis.\n");
        printf("7 - Finalizar Programa.\n");
        printf("==========================\n");

        printf("Digite a opcao que voce deseja: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("#######################################\n");
            printf("#           SUBMENU COLECAO           #\n");
            printf("#######################################\n");
            printf("1 - Listar Pokemons Capturados.\n");
            printf("2 - Pesquisar Pokemons Capturados.\n");
            printf("3 - Excluir Pokemons Capturados.\n");
            printf("=======================================\n");
            printf("Digite sua opcao: ");
            scanf("%d", &opcao1);

            switch(opcao1){
                case 1:
                    listarPokemonsCapturados(&colecao);
                    break;
                
                case 2:
                    pesquisarPokemonsCapturados(&colecao);
                    break;
                
                case 3:
                    excluirPokemonCapturado(&colecao);
                    break;
                
                default:
                    printf("Ops, o valor que voce digitou nao coincide com nenhuma das opcoes!\n");
                    break;
                    
            }//switchColecao

            break;
            
        case 2:
            printf("#######################################\n");
            printf("#           SUBMENU MOCHILA           #\n");
            printf("#######################################\n");
            printf("1 - Adicionar Pokemon na Mochila\n");
            printf("2 - Excluir Pokemon da Mochila\n");
            printf("3 - Listar Pokemons da Mochila\n");
            printf("=======================================\n");
            printf("Digite sua opcao: ");
            scanf("%d", &opcao2);

            switch(opcao2){//percebi, inteligente... j� que nada vai ser por input no terminal!
                case 1:
                    adicionarPokemonMochila(&mochila, 120);
                    break;
                    
                case 2:
                    excluirPokemonMochila(&mochila);
                    break;
                    
                case 3:
                    listarPokemonsMochila(&colecao, &mochila);
                    break;
                
                default:
                    printf("Ops, o valor que voce digitou nao coincide com nenhuma das opcoes!\n");
                    break;
                
            }//switchMochila

            break;

        case 3:
            printf("Em breve...\n");
            break;

        case 4:
            printf("Em breve...\n");
            break;

        case 5:
            printf("Em breve...\n");
            break;

        case 6:
            printf("Em breve...\n");
            break;

        case 7:
            printf("Finalizando programa!\n");
            break;

        default:
            printf("Ops, o valor que voce digitou nao coincide com nenhuma das opcoes!\n");
            break;
            
        }//switch final
    }while(opcao != 7);


    fclose(arquivoPokemonCSV);
    
    return 0;
}//main

void adicionarPokemonColecao(Colecao* colecao, int idPokemonCapturado){
    for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
        if(idPokemonCapturado == colecao->idPokemonsCapturados[i]){
            printf("Ops, esse pokemon ja foi capturado!\n");
            return;
        }//if
    }//for

    int* buffer = (int*) malloc((colecao->qtdPokemonsCapturados + 1) * sizeof(int));

    if(buffer == NULL){
        perror("Erro ao alocar buffer");
        exit(1);
    }//if

    for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
        buffer[i] = colecao->idPokemonsCapturados[i];
    }//for

    buffer[colecao->qtdPokemonsCapturados] = idPokemonCapturado;
    colecao->qtdPokemonsCapturados++;

    free(colecao->idPokemonsCapturados);

    colecao->idPokemonsCapturados = buffer;

    //exibirDadosUltimoPokemonCapturado(colecao); 

    return;
}//adicionarPokemonColecao

void exibirDadosUltimoPokemonCapturado(Colecao* colecao){
    Pokemon *pokemonCapturado = &colecao->dadosPokemon[colecao->idPokemonsCapturados[colecao->qtdPokemonsCapturados - 1] - 1];
    
    if (pokemonCapturado == NULL){
        printf("Erro ao exibir dados do Pokemon!\n");
        return;
    }//if
    
    printf("====== DADOS DO POKEMON CAPTURADO ======\n");
    printf("Nome: %s\n", pokemonCapturado->nome);
    printf("Tipo: %s e %s\n", pokemonCapturado->tipo1, pokemonCapturado->tipo2);
    printf("Total: %d\n", pokemonCapturado->total);
    printf("HP: %d\n", pokemonCapturado->hp);
    printf("Ataque: %d\n", pokemonCapturado->ataque);
    printf("Defesa: %d\n", pokemonCapturado->defesa);
    printf("Ataque Especial: %d\n", pokemonCapturado->ataqueEspecial);
    printf("Defesa Especial: %d\n", pokemonCapturado->defesaEspecial);
    printf("Velocidade: %d\n", pokemonCapturado->velocidade);    
    printf("Geracao: %d\n", pokemonCapturado->geracao);
    printf("Lendario: %d\n", pokemonCapturado->lendario);
    printf("Cor: %s\n", pokemonCapturado->cor);
    printf("Altura: %.2fm\n", pokemonCapturado->altura);
    printf("Peso: %.2fKg\n", pokemonCapturado->peso);
    printf("=========================================\n");
    return;
}//exibeDadosPokemon

void listarPokemonsCapturados(Colecao* colecao){
    printf("====== POKEMONS CAPTURADOS ======\n");
    for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
        printf("%d. %s\n", colecao->dadosPokemon[colecao->idPokemonsCapturados[i] - 1].numero, colecao->dadosPokemon[colecao->idPokemonsCapturados[i] - 1].nome);
    }//for
    //Gustavoo

    return;
}

void pesquisarPokemonsCapturados(Colecao* colecao){
    int numero;

    printf("Digite o numero do Pokemon Capturado que deseja buscar:");
    scanf("%d", &numero);

    for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
        if(numero == (colecao->dadosPokemon[colecao->idPokemonsCapturados[i] - 1].numero)){
            Pokemon *pokemonCapturado = &colecao->dadosPokemon[colecao->idPokemonsCapturados[i] - 1];
    
            if (pokemonCapturado == NULL){
                printf("Erro ao exibir dados do Pokemon!\n");
                return;
            }//if
            
            printf("====== DADOS DO POKEMON CAPTURADO ======\n");
            printf("Nome: %s\n", pokemonCapturado->nome);
            printf("Tipo: %s e %s\n", pokemonCapturado->tipo1, pokemonCapturado->tipo2);
            printf("Total: %d\n", pokemonCapturado->total);
            printf("HP: %d\n", pokemonCapturado->hp);
            printf("Ataque: %d\n", pokemonCapturado->ataque);
            printf("Defesa: %d\n", pokemonCapturado->defesa);
            printf("Ataque Especial: %d\n", pokemonCapturado->ataqueEspecial);
            printf("Defesa Especial: %d\n", pokemonCapturado->defesaEspecial);
            printf("Velocidade: %d\n", pokemonCapturado->velocidade);    
            printf("Geracao: %d\n", pokemonCapturado->geracao);
            printf("Lendario: %d\n", pokemonCapturado->lendario);
            printf("Cor: %s\n", pokemonCapturado->cor);
            printf("Altura: %.2fm\n", pokemonCapturado->altura);
            printf("Peso: %.2fKg\n", pokemonCapturado->peso);
            printf("=========================================\n");
            return;
        }//if
    }//for

    printf("O numero buscado nao corresponde a nenhum pokemon capturado!\n");

    return;
}//pesquisarPokemonsCapturados

void excluirPokemonCapturado(Colecao* colecao){
    
    int IDpokemon;
    int contador = 0;
    int novoIndice = 0;

    printf("Digite o numero do Pokemon que voce deseja excluir: ");
    scanf("%d", &IDpokemon);

    for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
        if(IDpokemon == colecao->idPokemonsCapturados[i]){
            contador++;
            break;
        }//if
    }//for

    if(contador == 1){
        int* buffer = (int*) malloc ((colecao->qtdPokemonsCapturados - 1) * sizeof(int));
        
        for(int i = 0; i < colecao->qtdPokemonsCapturados; i++){
            if (IDpokemon != colecao->idPokemonsCapturados[i]){ 
                buffer[novoIndice] = colecao->idPokemonsCapturados[i];
                novoIndice++;
            }//if
        }//for

        colecao->qtdPokemonsCapturados--;
        
        free(colecao->idPokemonsCapturados);

        colecao->idPokemonsCapturados = buffer;

        printf("Pokemon excluido com sucesso!\n");

        return;
    }else{
        printf("Ops! O pokemon selecionado nao pertence a sua colecao.\n");
    }//else

}//excluirPokemonCapturado

void adicionarPokemonMochila(Mochila* mochila, int idPokemonCapturado){

    if(mochila->qtdPokemonsMochila < 6){

        for(int i = 0; i < mochila->qtdPokemonsMochila; i++){
            if(idPokemonCapturado == mochila->idPokemonsMochila[i]){
                printf("Ops, esse pokemon ja foi armazenado!\n");
                return;
            }//if
        }//for

        int* buffer = (int*) malloc((mochila->qtdPokemonsMochila + 1) * sizeof(int));

        if(buffer == NULL){
            perror("Erro ao alocar buffer");
            exit(1);
        }//if

        for(int i = 0; i < mochila->qtdPokemonsMochila; i++){
            buffer[i] = mochila->idPokemonsMochila[i];
        }//for

        buffer[mochila->qtdPokemonsMochila] = idPokemonCapturado;
        mochila->qtdPokemonsMochila++;

        free(mochila->idPokemonsMochila);

        mochila->idPokemonsMochila = buffer;

        return;
    }//if

    printf("Ops, sua mochila esta cheia! Se voce deseja adicionar um novo pokemon, por favor, exclua um de seus mascotes!\n");
    
    return;

}//adicionarPokemonMochila

void excluirPokemonMochila(Mochila* mochila){

    int IDpokemon;
    int contador = 0;
    int novoIndice = 0;

    printf("Digite o numero do Pokemon que voce deseja excluir da mochila: ");
    scanf("%d", &IDpokemon);

    for(int i = 0; i < mochila->qtdPokemonsMochila; i++){
        if(IDpokemon == mochila->idPokemonsMochila[i]){
            contador++;
            break;
        }//if
    }//for

    if(contador == 1){
        int* buffer = (int*) malloc((mochila->qtdPokemonsMochila - 1) * sizeof(int));
        
        for(int i = 0; i < mochila->qtdPokemonsMochila; i++){
            if (IDpokemon != mochila->idPokemonsMochila[i]){ 
                buffer[novoIndice] = mochila->idPokemonsMochila[i];
                novoIndice++;
            }//if
        }//for

        mochila->qtdPokemonsMochila--;
        
        free(mochila->idPokemonsMochila);

        mochila->idPokemonsMochila = buffer;

        return;
    }else{
        printf("Ops! O pokemon selecionado nao pertence a sua mochila.\n");
    }//else

    return;
}//excluirPokemonMochila

void listarPokemonsMochila(Colecao* colecao, Mochila* mochila){
    printf("====== POKEMONS NA MOCHILA ======\n");

    if(mochila->qtdPokemonsMochila == 0){
        printf("Ops, nao ha pokemons na mochila!\n");
        return;
    }//if

    for(int i = 0; i < mochila->qtdPokemonsMochila; i++){
        printf("%d. %s\n", colecao->dadosPokemon[mochila->idPokemonsMochila[i] - 1].numero, colecao->dadosPokemon[mochila->idPokemonsMochila[i] - 1].nome);
    }//for

    return;
}//listarPokemonsMochila

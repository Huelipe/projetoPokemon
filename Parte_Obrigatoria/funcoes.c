#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Início das funções 
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

void leString(char string[], int tamanho){

    setbuf(stdin,NULL);
    fgets(string, tamanho - 1, stdin);
    string[strcspn(string, "\n")] = '\0';

    return;
}//leString

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

    *totalPokesNaColecao += 1;
    *colecaoDePokemons = (Colecao*)realloc(*colecaoDePokemons, (*totalPokesNaColecao) * sizeof(Colecao));
    (*colecaoDePokemons)[*totalPokesNaColecao - 1].numDoPokemon = idDoPokemon;
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
            printf(" 1- Nome\n 2- Tipo 1\n 3- Tipo 2\n 4- HP\n 5- Ataque\n 6- Defesa\n 7- Ataque Especial\n 8- Defesa Especial\n 9- Speed\n10- Lendario\n11- Geracao\n12- Altura\n13- Peso\n14- Captura\n15- Sair\n");
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

            case 15:
            listaPokemon[colecaoDePokemons[i].numDoPokemon].total = listaPokemon[colecaoDePokemons[i].numDoPokemon].hp + listaPokemon[colecaoDePokemons[i].numDoPokemon].atk + listaPokemon[colecaoDePokemons[i].numDoPokemon].def + listaPokemon[colecaoDePokemons[i].numDoPokemon].spatack + listaPokemon[colecaoDePokemons[i].numDoPokemon].spdef + listaPokemon[colecaoDePokemons[i].numDoPokemon].speed;
            return;
            break;

            default:
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

    printf("Digite o Id do Pokémon que deseja excluir da coleção: ");
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

void adicionarPokemonNaPokedex(Pokemon* listaPokemon, int* numeroDePokemons){

    (*numeroDePokemons)++;

    listaPokemon = (Pokemon*) realloc(listaPokemon, ((*numeroDePokemons) * sizeof(Pokemon)));

    printf("\nDigite o nome do pokémon a ser adicionado:");
    leString(listaPokemon[(*numeroDePokemons) - 1].nome, 40);

    printf("\nDigite o tipo 1 do pokémon a ser adicionado:");
    leString(listaPokemon[(*numeroDePokemons) - 1].tipo1, 10);

    printf("\nDigite o tipo 2 do pokémon a ser adicionado:");
    leString(listaPokemon[(*numeroDePokemons) - 1].tipo2, 10);

    printf("\nDigite os pontos de vida (hp) do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].hp);

    printf("\nDigite os pontos de ataque do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].atk);

    printf("\nDigite os pontos de defesa do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].def);

    printf("\nDigite os pontos de ataque especial do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].spatack);

    printf("\nDigite os pontos de defesa especial do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].spdef);

    printf("\nDigite os pontos de velocidade do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].speed);

    printf("\nDigite a geração do pokémon a ser adicionado:");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].geracao);

    printf("\nDigite se o pokémon a ser adicionado é lendário(digite 1) ou não(digite 0):");
    scanf("%d", &listaPokemon[(*numeroDePokemons) - 1].lendario);

    printf("\nDigite a cor do pokémon a ser adicionado:");
    leString(listaPokemon[(*numeroDePokemons) - 1].cor, 10);

    printf("\nDigite a altura do pokémon a ser adicionado:");
    scanf("%f", &listaPokemon[(*numeroDePokemons) - 1].altura);

    printf("\nDigite o peso do pokémon a ser adicionado:");
    scanf("%f", &listaPokemon[(*numeroDePokemons) - 1].peso);

    printf("\nDigite a taxa de captura do pokémon a ser adicionado:");
    scanf("%f", &listaPokemon[(*numeroDePokemons) - 1].captura);

    listaPokemon[(*numeroDePokemons) - 1].total = listaPokemon[(*numeroDePokemons) - 1].hp + listaPokemon[(*numeroDePokemons) - 1].atk + listaPokemon[(*numeroDePokemons) - 1].def + listaPokemon[(*numeroDePokemons) - 1].spdef + listaPokemon[(*numeroDePokemons) - 1].spatack + listaPokemon[(*numeroDePokemons) - 1].speed;

    listaPokemon[(*numeroDePokemons) - 1].nPokedex = (*numeroDePokemons);

    printf("\nO Pokémon %s foi adicionado na Pokedex do jogo!\n", listaPokemon[(*numeroDePokemons) - 1].nome);

    return;
}//adicionarPokemonNaPokedex

void excluirPokemonDaPokedex(Pokemon* listaPokemon, int* numeroDePokemons){

    char pokemonExcluido[40];
    int indiceDoPokemonExcluido;
    int confirmaExclusao = 0;
    char continuarExcluindo;

    do{//nao sei como o usuario sairia caso nao quisesse mais excluir um pokemon
        printf("\nDigite o nome do pokémon a ser excluido:");
        leString(pokemonExcluido, 40);

        for(int i = 0; i < (*numeroDePokemons); i++){
            if(strcasecmp(pokemonExcluido, listaPokemon[i].nome) == 0){
                printf("\nO pokémon %s foi excluído!\n", pokemonExcluido);
                confirmaExclusao++;
                indiceDoPokemonExcluido = i;
                
                for(int j = i; j < (*numeroDePokemons) - 1; j++){
                    listaPokemon[j] = listaPokemon[j + 1];
                }//for
                
                (*numeroDePokemons)--;
                listaPokemon = (Pokemon*) realloc(listaPokemon,(*numeroDePokemons) * sizeof(Pokemon));
                
                for(int i = indiceDoPokemonExcluido; i < (*numeroDePokemons); i++){
                    listaPokemon[i].nPokedex = listaPokemon[i].nPokedex - 1;
                }//for  
                
                break;
            }//if
        }//for

        if(confirmaExclusao == 0){
            printf("\nNenhum pokémon foi encontrado! Deseja digitar novamente?(digite S ou N):");
            scanf("%c", &continuarExcluindo);
        }//if

    }while(continuarExcluindo == 's' || continuarExcluindo == 'S');

    return;
}//excluirPokemonDaPokedex

void listarPokemonsDaPokedex(Pokemon* listaPokemon, int numeroDePokemons){

    printf("\nVocê escolheu listar os pokémons da Pokedex!\nAqui estão todos os pokémons da Pokedex!\n");
    
    for(int i = 0; i < numeroDePokemons; i++){
        printf("%d - %s\n", listaPokemon[i].nPokedex, listaPokemon[i].nome);
    }//for

    printf("\n");

    return;
}//listarPokemonsDaPokedex

void pesquisaPokemonNaPokedex(Pokemon* listaPokemon, int numeroDePokemons){

    char pokemonPesquisado[40];
    int pokemonEncontrado = 0;
    char continuarNaProcura;

    do{

    printf("\nDigite o nome de um pokémon para pesquisá-lo na Pokedex:");
    leString(pokemonPesquisado, 40);

    for(int i = 0; i < numeroDePokemons; i++){
        if(strcasecmp(pokemonPesquisado, listaPokemon[i].nome) == 0){
            pokemonEncontrado++;
        }//if

        if(pokemonEncontrado > 0){
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
            break;
        }//if
    }//for

    if(pokemonEncontrado == 0){
        printf("\nO pokémon não foi encontrado na Pokedex! Deseja procurar novamente?(Digite S ou N):");
        scanf("%c", &continuarNaProcura);
    }//if

    }while((continuarNaProcura == 'S' || continuarNaProcura == 's') && pokemonEncontrado == 0);

    return;
}//pesquisaPokemonNaPokedex

void alteraPokemonNaPokedex(Pokemon* listaPokemon, int numeroDePokemons){

    char pokemonAlterado[40];
    int opcao;

    printf("\nVocê escolheu alterar um pokémon na Pokedex.\n");
    printf("Digite o nome do pokémon que você quer alterar:");
    leString(pokemonAlterado, 40);

    for(int i = 0; i < numeroDePokemons; i++){
        if(strcasecmp(pokemonAlterado, listaPokemon[i].nome) == 0){
            printf("\nO pokémon %s foi encontrado!\n", pokemonAlterado);
            printf("Você deseja alterar qual atributo dele?\n");
            printf("Nome - digite 1\n");
            printf("Tipo 1 - digite 2\n");
            printf("Tipo 2 - digite 3\n");
            printf("Total - digite 4\n");
            printf("HP - 5 digite 5\n");
            printf("Ataque - digite 6\n");
            printf("Defesa - digite 7\n");
            printf("Ataque Especial - digite 8\n");
            printf("Defesa Especial - digite 9\n");
            printf("Velocidade - digite 10\n");
            printf("Geração - digite 11\n");
            printf("Lendário - digite 12\n");
            printf("Cor - digite 13\n");
            printf("Altura - digite 14\n");
            printf("Peso - digite 15\n");
            printf("Taxa de Captura - digite 16\n");
            printf("Pré-Evolução - digite 17\n");
            printf("Próxima Evolução - digite 18\n");
            printf("Digite o número conforme o que você deseja alterar:");
            scanf("%d", &opcao);
        }//if
    }//for

    return;
}//alteraPokemonNaPokedex

void exportarPokemonParaCSV(Pokemon pokemon[], int tamanho, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escreve o cabeçalho no arquivo CSV com os espaçamentos
    fprintf(arquivo, "numero ,nome        ,tipo1    ,tipo2    ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura\n");

    // Escreve os dados no arquivo CSV com os espaçamentos
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%-7d,%-12s,%-9s,%-9s,%-5d,%-3d,%-6d,%-6d,%-15d,%-16d,%-11d,%-7d,%-8d,%-8s,%-8.2f,%-8.2f,%-13.2f\n",
            pokemon[i].nPokedex, pokemon[i].nome, pokemon[i].tipo1, pokemon[i].tipo2,
            pokemon[i].total, pokemon[i].hp, pokemon[i].atk, pokemon[i].def,
            pokemon[i].spatack, pokemon[i].spdef, pokemon[i].speed, pokemon[i].geracao,
            pokemon[i].lendario, pokemon[i].cor, pokemon[i].altura, pokemon[i].peso,
            pokemon[i].captura);
    }

    fclose(arquivo);

    printf("Pokedex exportada para %s com sucesso.\n", nomeArquivo);
}

void exportarColecaoParaCSV(Colecao* colecaoDePokemons, int totalPokesNaColecao, Pokemon* listaPokemon, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escreve o cabeçalho no arquivo CSV com os mesmos espaçamentos da função exportarPokemonParaCSV
    fprintf(arquivo, "numero ,nome        ,tipo1    ,tipo2    ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura\n");

    // Escreve os dados da coleção no arquivo CSV com os mesmos espaçamentos
    for (int i = 0; i < totalPokesNaColecao; i++) {
        int numDoPokemon = colecaoDePokemons[i].numDoPokemon;
        fprintf(arquivo, "%-7d,%-12s,%-9s,%-9s,%-5d,%-3d,%-6d,%-6d,%-15d,%-16d,%-11d,%-7d,%-8d,%-8s,%-8.2f,%-8.2f,%-13.2f\n",
            i + 1, listaPokemon[numDoPokemon].nome, listaPokemon[numDoPokemon].tipo1, listaPokemon[numDoPokemon].tipo2,
            listaPokemon[numDoPokemon].total, listaPokemon[numDoPokemon].hp, listaPokemon[numDoPokemon].atk, listaPokemon[numDoPokemon].def,
            listaPokemon[numDoPokemon].spatack, listaPokemon[numDoPokemon].spdef, listaPokemon[numDoPokemon].speed, listaPokemon[numDoPokemon].geracao,
            listaPokemon[numDoPokemon].lendario, listaPokemon[numDoPokemon].cor, listaPokemon[numDoPokemon].altura, listaPokemon[numDoPokemon].peso,
            listaPokemon[numDoPokemon].captura);
    }

    fclose(arquivo);

    printf("Coleção exportada para %s com sucesso.\n", nomeArquivo);
}


#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "estruturas.h"
#include "funcoes.h"

//gcc -o teste main.c -lraylib -lm

typedef enum GameScreen { MENU, NOVOJOGO1, NOVOJOGO2, NOVOJOGO3, NOVOJOGO4, NOVOJOGO5, NOVOJOGO6, NOVOJOGO7, NOVOJOGO8, NOVOJOGO9, TRANSICAO, CARREGARJOGO, CONFIGURACOES, ESC } GameScreen;
typedef enum GameLoad { CIDADE1 } GameLoad;
#define MAX_CHARS 20 // Tamanho máximo da palavra a ser digitada

#define MAX_POKEMON 722 

int main(){

    srand(time(NULL));

    Pokebola pokebolas[4];
    vetorDePokebolas(pokebolas);

    nature natures[25];
    vetorDeNatures(natures);

    Colecao* colecaoDePokemons; //armazena os ids dos pokemons na colecao

    Mochila mochila[6];
    int IndiceMochila[6];

    Dados dadosSalvos;

    //Carrega a pokedex
    FILE *arquivo;
    Pokemon listaPokemon[MAX_POKEMON];

    arquivo = fopen("pokedex.csv", "r+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    for(int i = 1; i < 722; i++){
        fscanf(arquivo, "%d ,%s ,%s ,%s ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%s ,%f ,%f ,%f \n", &listaPokemon[i].nPokedex, listaPokemon[i].nome, listaPokemon[i].tipo1, listaPokemon[i].tipo2, &listaPokemon[i].total, &listaPokemon[i].hp, &listaPokemon[i].atk, &listaPokemon[i].def, &listaPokemon[i].spatack, &listaPokemon[i].spdef, &listaPokemon[i].speed, &listaPokemon[i].geracao, &listaPokemon[i].lendario, listaPokemon[i].cor, &listaPokemon[i].altura, &listaPokemon[i].peso, &listaPokemon[i].captura);
    }

    fclose(arquivo);

    FILE *arquivoBinarioPokedex;
    FILE *arquivoBinarioColecao;
    FILE *arquivoBinarioMochila;
    FILE *arquivoBinarioDados;

    arquivoBinarioPokedex = fopen("Arquivos_Binarios/Pokedex.dat", "rb");
    arquivoBinarioColecao = fopen("Arquivos_Binarios/Colecao.dat", "rb");
    arquivoBinarioMochila = fopen("Arquivos_Binarios/Mochila.dat", "rb");
    arquivoBinarioDados = fopen("Arquivos_Binarios/Dados.dat", "rb");

    if(arquivoBinarioPokedex == NULL && arquivoBinarioColecao == NULL && arquivoBinarioMochila == NULL){
        printf("Passei 1");
            arquivo = fopen("pokedex.csv", "r+"); //abre o arquivo .csv para leitura
            dadosSalvos.totalMochila = 0;
            dadosSalvos.numeroDePokemons = 721;
            dadosSalvos.totalPokesNaColecao = 0; //numero total de pokemons da colecao

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    } //verifica se houve erro na abertura do arquivo
    }

    int screensAtuais = 0;
    int opcaoGenero;
    int opcaoPokemon;

    char frase[60] = "Então seu nome é ";

    char input[MAX_CHARS + 1] = { 0 }; // String para armazenar a palavra
    int charCount = 0; // Contador de caracteres

    const int screenWidth = 1280;
    const int screenHeight = 720;

    Rectangle profOak = {0, 0, 120, 256};
    Vector2 posicaoOak = {800, 270};
    Vector2 posicaoB = {550, 500};
    Vector2 posicaoS = {750, 500};
    Vector2 posicaoC = {950, 500};
    float scale = 3;
    float scalePersonagem = 0.5;

    InitWindow(screenWidth, screenHeight, "Pokémon");

    RenderTexture2D target = LoadRenderTexture(1280, 720);
    float transitionRadius = 0.0f;
    float maxRadius = sqrt(powf(1280, 2) + powf(720, 2)) / 2;

    Texture2D menu = LoadTexture("imagens/wallpaper.png");
    Texture2D novojogo = LoadTexture("imagens/frenteUtfpr.png");
    Texture2D professor = LoadTexture("imagens/professorOak.png");
    Texture2D bulbassauro = LoadTexture("imagens/imagens_pokedex/001.png");
    Texture2D squirtle = LoadTexture("imagens/imagens_pokedex/007.png");
    Texture2D charmander = LoadTexture("imagens/imagens_pokedex/004.png");
    Texture2D creditos = LoadTexture("imagens/fundoazul.png");

    int targetfps = 60;

    GameScreen currentScreen = MENU;
    SetTargetFPS(targetfps); 

    while(!WindowShouldClose()){

    if(screensAtuais == 0){
    switch(currentScreen){
        case MENU:
        if(IsKeyPressed(KEY_Q) ){
            currentScreen = NOVOJOGO1;
        }else if(IsKeyPressed(KEY_W)){
            currentScreen = CARREGARJOGO;
        }else if(IsKeyPressed(KEY_E)){
            currentScreen = CONFIGURACOES;
        }
        break;

        case NOVOJOGO1:
            if(IsKeyPressed(KEY_ENTER)){
                currentScreen = NOVOJOGO2;
            }
        break;

        case NOVOJOGO2:
                if(IsKeyPressed(KEY_ENTER)){
                    currentScreen = NOVOJOGO3;
                }
        break;

        case NOVOJOGO3:
            if (charCount < MAX_CHARS) {
            // Verifica as teclas pressionadas
            int key = GetKeyPressed();
            if (key > 0 && key != KEY_ENTER && key != KEY_BACKSPACE) {
                // Se uma tecla válida (não enter nem backspace) for pressionada, adicione-a à string
                input[charCount] = (char)key;
                charCount++;
            } else if (key == KEY_BACKSPACE && charCount > 0) {
                // Se a tecla de backspace for pressionada e houver caracteres na string, remova o último caractere
                charCount--;
                input[charCount] = '\0';
            } else if (key == KEY_ENTER) {
                // Se a tecla Enter for pressionada, mostra a palavra digitada e reinicia a entrada
                strcat(frase, input);

                if(IsKeyPressed(KEY_ENTER)){
                    currentScreen = NOVOJOGO4;
                }
            }
        }
        break;

        case NOVOJOGO4:
                if(IsKeyPressed(KEY_Q)){
                    currentScreen = NOVOJOGO5;
                }else if(IsKeyPressed(KEY_W)){
                    memset(input, 0, sizeof(input));
                    charCount = 0;
                    strcpy(frase, "Então seu nome é ");
                    currentScreen = NOVOJOGO3;
                }      
        break;

        case NOVOJOGO5:
            if(IsKeyPressed(KEY_Q)){
                opcaoGenero = 1;
                currentScreen = NOVOJOGO6;
            }else if(IsKeyPressed(KEY_W)){
                opcaoGenero = 2;
                currentScreen = NOVOJOGO6;
            }        
        break;

        case NOVOJOGO6:
                if(IsKeyPressed(KEY_ENTER)){
                    currentScreen = NOVOJOGO7;
                }
        break;

        case NOVOJOGO7:
            if(IsKeyPressed(KEY_Q)){
                opcaoPokemon = 1;
                currentScreen = NOVOJOGO8;
            }else if(IsKeyPressed(KEY_W)){
                opcaoPokemon = 2;
                currentScreen = NOVOJOGO8;
            }else if(IsKeyPressed(KEY_E)){
                opcaoPokemon = 3;
                currentScreen = NOVOJOGO8;
            }
        break;

        case NOVOJOGO8:
            if(IsKeyPressed(KEY_ENTER)){
                currentScreen = NOVOJOGO9;
            }
        break;

        case NOVOJOGO9:
            if(IsKeyPressed(KEY_ENTER)){
                currentScreen = TRANSICAO;
            }
        break;

        case TRANSICAO:
        transitionRadius += 6.0f; // Ajuste o valor conforme necessário

        if (transitionRadius > maxRadius) {
            UnloadRenderTexture(target);
            screensAtuais = 1;

        }

        break;

        case CARREGARJOGO:

        break;

        case CONFIGURACOES:
        if(IsKeyPressed(KEY_Q)){
            if(IsKeyPressed(KEY_Q)){
                //adicionar pokemon
            }else if(IsKeyPressed(KEY_W)){
                //remover pokemon
            }else if(IsKeyPressed(KEY_E)){
                //editar um pokemon
            }
            //Configurar lista de pokémons
        }else if(IsKeyPressed(KEY_W)){
            //Configurar Som
        }
        break;

        case ESC:
        break;

        default:
        break;

    }

    BeginDrawing();
    ClearBackground(WHITE);

    switch(currentScreen){
        case MENU:
        DrawTexture(menu, 0, 0, WHITE);
        DrawText("Pokémon: Caio's Adventure", 120, 130, 65, PINK);
        DrawText("| Q | Começar uma nova aventura", 120, 200, 45, GOLD);
        DrawText("| W | Carregar seu jogo", 120, 270, 45, GOLD);
        DrawText("| E | Configurações", 120, 340, 45, GOLD);
        DrawText("| R | Exportar estruturas", 120, 410, 45, GOLD);
        DrawFPS(10, 10);
        break;

        case NOVOJOGO1:
        DrawTexture(menu, 0, 0, WHITE);
        DrawText("Pressione Enter para avançar a conversa...", 100, 120, 35, GOLD);
        break;

        case NOVOJOGO2:
        DrawTexture(novojogo, 0, 0, WHITE);
        DrawTextureRec(professor, profOak, posicaoOak, WHITE);
        DrawText("- Prof. Oak: Olá, bem vindo ao mundo Pokémon!", 50, 600, 30, GRAY);
        DrawText("- Eu sou o Prof. Oak, e vou te ajudar em sua jornada!", 50, 650, 30, GRAY);
        break;

        case NOVOJOGO3:
        DrawTexture(novojogo, 0, 0, WHITE);
        DrawTextureRec(professor, profOak, posicaoOak, WHITE); 
        DrawText("- Poderia me dizer seu nome?", 50, 600, 30, GRAY);
        DrawText(input, 50, 650, 30, GRAY);
        break;

        case NOVOJOGO4:
        DrawTexture(novojogo, 0, 0, WHITE);
        DrawTextureRec(professor, profOak, posicaoOak, WHITE); 
        DrawText(frase, 50, 600, 30, GRAY);
        DrawText("| Q | - Sim!", 50, 650, 30, GRAY);
        DrawText("| W | - Não!", 50, 685, 30, GRAY);
        break;
        
        case NOVOJOGO5:
        DrawTexture(novojogo, 0, 0, WHITE);
        DrawTextureRec(professor, profOak, posicaoOak, WHITE);
        DrawText("E você é Menino ou Menina?", 50, 600, 30, GRAY);
        DrawText("| Q | Menino", 50, 650, 30, GRAY);
        DrawText("| W | Menina", 50, 685, 30, GRAY);
        break;

        case NOVOJOGO6:
        DrawTexture(novojogo, 0, 0, WHITE);
        DrawTextureRec(professor, profOak, posicaoOak, WHITE);
        DrawText("Muito bem!", 50, 600, 30, GRAY);
        DrawText("Agora, para iniciar sua jornada, voce precisa escolher um Pokémon...", 50, 650, 30, GRAY);
        break;

        case NOVOJOGO7:
        DrawTexture(novojogo, 0, 0, WHITE);
        DrawTextureRec(professor, profOak, posicaoOak, WHITE);
        DrawText("Qual desses três mais lhe agrada?", 50, 650, 30, GRAY);
        DrawTextureEx(squirtle, posicaoS, 0.0f, scale, WHITE);
        DrawTextureEx(bulbassauro, posicaoB, 0.0f, scale, WHITE);
        DrawTextureEx(charmander, posicaoC, 0.0f, scale, WHITE);
        DrawText("| Q |            | W |            | E |", 570, 600, 30, GRAY);
        break;

        case NOVOJOGO8:
        DrawTexture(novojogo, 0, 0, WHITE);
        DrawTextureRec(professor, profOak, posicaoOak, WHITE);
        DrawText("Beleza! Agora, não perca tempo, vá se aventurar!", 50, 600, 30, GRAY);
        DrawText("Se precisar de ajuda em algo, venha me visitar aqui na universidade!", 50, 650, 30, GRAY);
        break;

        case NOVOJOGO9:
        DrawTexture(creditos, 0, 0, WHITE);
        DrawText("- Projeto de Fundamentos de Programação 2 - ", 50, 200, 50, DARKBLUE);
        DrawText("> Pokémon: Uma aventura por Apucarana", 50, 270, 50, DARKBLUE);
        DrawText("> Prof. Muriel de Souza Godoi", 50, 340, 35, DARKBLUE);
        DrawText("> Alunos:", 50, 380, 35, DARKBLUE);
        DrawText("> Caio Vinícius Maciel Delgado", 50, 420, 35, DARKBLUE);
        DrawText("> Felipe Ferrer Sorrilha", 50, 460, 35, DARKBLUE);
        DrawText("> João Pedro Garcia Bronharo", 50, 500, 35, DARKBLUE);
        break;

        case TRANSICAO:
        BeginTextureMode(target);
        ClearBackground(RAYWHITE);

        DrawTexture(creditos, 0, 0, WHITE);

        // DrawCircle com a cor verde claro (RGBA: 144, 238, 144, 255)
        DrawCircle(screenWidth / 2, screenHeight / 2, transitionRadius, (Color){144, 238, 144, 255});
        DrawText("Carregando...", 500, 300, 40, DARKBLUE);

        EndTextureMode();

        DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);


        break;

        case CARREGARJOGO:

        break;

        case CONFIGURACOES:
        DrawTexture(menu, 0, 0, WHITE);
        DrawText("| Q | Editar lista de pokémons", 120, 130, 45, GOLD);
        DrawText("| W | Configurar Som", 120, 200, 45, GOLD);
        DrawText("| E | Voltar", 120, 270, 45, GOLD);
        break;

        case ESC:
        break;

        default:
        break;

    }

    EndDrawing();
    }


    if(screensAtuais == 1){

    Vector2 posicaoPersonagem = {550, 320};

    GameLoad screenLoad = CIDADE1;
    Texture2D cidade1 = LoadTexture("imagens/palletTown.png");
    Texture2D opcoes = LoadTexture("imagens/opcoesInGame.png");
    Texture2D personagem;
    if(opcaoGenero == 1){
        personagem = LoadTexture("imagens/ash.png");
    }else{
        personagem = LoadTexture("imagens/amy.png");
    }
    
pokemonCapturado pokemonInicial;
    if(opcaoPokemon == 1){
        criarPokemon(listaPokemon[0], &pokemonInicial, 5, natures);
        InserirNaMochila(mochila, colecaoDePokemons, &dadosSalvos.totalPokesNaColecao, listaPokemon, dadosSalvos.numeroDePokemons, &dadosSalvos.totalMochila, pokemonInicial);
    }else if(opcaoPokemon == 2){
        criarPokemon(listaPokemon[3], &pokemonInicial, 5, natures);
        InserirNaMochila(mochila, colecaoDePokemons, &dadosSalvos.totalPokesNaColecao, listaPokemon, dadosSalvos.numeroDePokemons, &dadosSalvos.totalMochila, pokemonInicial);
    }else if(opcaoPokemon == 3){
        criarPokemon(listaPokemon[6], &pokemonInicial, 5, natures);
        InserirNaMochila(mochila, colecaoDePokemons, &dadosSalvos.totalPokesNaColecao, listaPokemon, dadosSalvos.numeroDePokemons, &dadosSalvos.totalMochila, pokemonInicial);
    }


    switch(screenLoad){

    case CIDADE1:
        if(IsKeyPressed(KEY_KP_1)){

        }else if(IsKeyPressed(KEY_KP_2)){

        }else if(IsKeyPressed(KEY_KP_3)){

        }else if(IsKeyPressed(KEY_KP_4)){

        }else if(IsKeyPressed(KEY_KP_5)){
            //bolsa
        }else if(IsKeyPressed(KEY_KP_6)){
            //...
        }
    break;

    }

    BeginDrawing();
    ClearBackground(WHITE);

    switch(screenLoad){

    case CIDADE1:
        DrawTexture(cidade1, 0, 0, WHITE);
        DrawTexture(opcoes, 1024, 0, WHITE);
        DrawTextureEx(personagem, posicaoPersonagem, 0.0f, scalePersonagem, WHITE);
        DrawText("1-Batalhar", 1080, 60, 20, DARKGRAY);
        DrawText("2-Caçar Pokémons", 1050, 165, 20, DARKGRAY);
        DrawText("3-Visitar o Prof.", 1060, 280, 20, DARKGRAY);
        DrawText("4-Visitar Pokedoca", 1047, 400, 20, DARKGRAY);
        DrawText("5-Acessar bolsa", 1055, 515, 20, DARKGRAY);
        DrawText("6-Próxima região", 1055, 635, 20, DARKGRAY);
    break;

    }

    EndDrawing();

    }

}
    return 0;

}

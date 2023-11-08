#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

typedef enum GameScreen { MENU, NOVOJOGO1, NOVOJOGO2, NOVOJOGO3, NOVOJOGO4, NOVOJOGO5, NOVOJOGO6, NOVOJOGO7, NOVOJOGO8, CARREGARJOGO, CONFIGURACOES, ESC } GameScreen;
typedef enum GameLoad { LOADGAME, BATALHA, AVENTURA, POKEDOCA, CENTRO, CIDADE1 } GameLoad;
#define MAX_CHARS 20 // Tamanho máximo da palavra a ser digitada

int main(){

    int screensAtuais = 0;

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

    InitWindow(screenWidth, screenHeight, "Pokémon");
    Texture2D menu = LoadTexture("imagens/wallpaper.png");
    Texture2D novojogo = LoadTexture("imagens/frenteUtfpr.png");
    Texture2D professor = LoadTexture("imagens/professorOak.png");
    Texture2D bulbassauro = LoadTexture("imagens/imagens_pokedex/001.png");
    Texture2D squirtle = LoadTexture("imagens/imagens_pokedex/007.png");
    Texture2D charmander = LoadTexture("imagens/imagens_pokedex/004.png");

    int targetfps = 60;

    GameScreen currentScreen = MENU;
    SetTargetFPS(targetfps); 

    while(!WindowShouldClose()){

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
        int opcaoGenero;
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
            int opcaoPokemon;
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
        DrawText("E você é menina ou Menino?", 50, 600, 30, GRAY);
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

    if(screensAtuais == 1){
        break;
    }
    }

    GameLoad screenLoad = CIDADE1;
    Texture2D cidade1 = LoadTexture("imagens/palletTown.png");

    while(!WindowShouldClose()){

    switch(screenLoad){

    case CIDADE1:
    break;

    }

    BeginDrawing();
    ClearBackground(WHITE);

    switch(screenLoad){

    case CIDADE1:
        DrawTexture(cidade1, 0, 0, WHITE);
    break;

    }

    EndDrawing();
    }

    return 0;

}
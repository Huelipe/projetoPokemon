#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

typedef enum GameScreen { MENU, NOVOJOGO1, NOVOJOGO2, NOVOJOGO3, CARREGARJOGO, CONFIGURACOES, ESC } GameScreen;

#define MAX_CHARS 20

int main(){

    const int screenWidth = 1280;
    const int screenHeight = 720;

    char input[MAX_CHARS + 1] = { 0 }; // String para armazenar a palavra
    int charCount = 0; // Contador de caracteres

    Rectangle profOak = {0, 0, 180, 384};
    Vector2 posicaoOak = {800, 280};

    InitWindow(screenWidth, screenHeight, "Pokémon");
    Texture2D menu = LoadTexture("imagens/wallpaper.png");
    Texture2D novojogo = LoadTexture("imagens/frenteUtfpr.png");
    Texture2D professor = LoadTexture("imagens/professorOak.png");
    int targetfps = 60;

    GameScreen currentScreen = MENU;

    while(!WindowShouldClose()){
    SetTargetFPS(targetfps); 

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
            currentScreen = NOVOJOGO2;
        break;

        case NOVOJOGO2:
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
                printf("Palavra digitada: %s\n", input);
                memset(input, 0, sizeof(input));
                charCount = 0;
            }
        }
            currentScreen = NOVOJOGO3;
        break;

        case NOVOJOGO3:
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
        DrawTexture(novojogo, 0, 0, WHITE);
        DrawTextureRec(professor, profOak, posicaoOak, WHITE);
        DrawText("- Prof. Oak: Olá, bem vindo ao mundo Pokémon!", 100, 70, 35, GOLD);
        DrawText("- Eu sou o Professor Oak, e vou te ajudar em sua jornada!", 100, 120, 35, GOLD);
        break;

        case NOVOJOGO2:
        DrawTexture(novojogo, 0, 0, WHITE);
        DrawTextureRec(professor, profOak, posicaoOak, WHITE); 
        DrawText("- Poderia me dizer seu nome?", 100, 70, 35, GOLD);
        break;

        case NOVOJOGO3:
        DrawTexture(novojogo, 0, 0, WHITE);
        DrawTextureRec(professor, profOak, posicaoOak, WHITE);
        DrawText(input, 100, 220, 35, GOLD);
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

    return 0;

}

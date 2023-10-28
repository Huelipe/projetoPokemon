#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

typedef enum GameScreen { MENU, NOVOJOGO, CARREGARJOGO, CONFIGURACOES, ESC } GameScreen;

int main(){

    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Pokémon");
    Texture2D menu = LoadTexture("imagens/wallpaper.png");
    Texture2D novojogo = LoadTexture("imagens/campusApucarana.png");
    Texture2D professor = LoadTexture("imagens/professorOak");
    int targetfps = 60;

    GameScreen currentScreen = MENU;

    while(!WindowShouldClose()){
    SetTargetFPS(targetfps); 

    switch(currentScreen){
        case MENU:
        if(IsKeyPressed(KEY_Q) ){
            currentScreen = NOVOJOGO;
        }else if(IsKeyPressed(KEY_W)){
            currentScreen = CARREGARJOGO;
        }else if(IsKeyPressed(KEY_E)){
            currentScreen = CONFIGURACOES;
        }
        break;

        case NOVOJOGO:
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

    switch(currentScreen){
        case MENU:
        ClearBackground(WHITE);
        DrawTexture(menu, 0, 0, WHITE);
        
        DrawText("Pokémon: Caio's Adventure", 120, 130, 65, PINK);
        DrawText("| Q | Começar uma nova aventura", 120, 200, 45, GOLD);
        DrawText("| W | Carregar seu jogo", 120, 270, 45, GOLD);
        DrawText("| E | Configurações", 120, 340, 45, GOLD);
        DrawFPS(10, 10);
        break;

        case NOVOJOGO:
        DrawTexture(novojogo, 0, 0, WHITE);
        DrawTexture(professor, 600, 400, WHITE);
        DrawText("Olá, bem vindo ao mundo Pokémon!", 100, 100, 50, BLACK);
        sleep(2);
        break;

        case CARREGARJOGO:
        break;

        case CONFIGURACOES:
        DrawTexture(menu, 0, 0, WHITE);
        DrawText("| Q | Editar lista de pokémons", 120, 130, 45, GOLD);
        DrawText("| W | Configurar Som", 120, 200, 45, GOLD);
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

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef enum GameScreen { MENU, NOVOJOGO, CARREGARJOGO, CONFIGURACOES, ESC } GameScreen;

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Pokémon");
    int targetfps = 60;

    GameScreen currentScreen = MENU;

    while(!WindowShouldClose()){
    SetTargetFPS(targetfps); 

    switch(currentScreen){
        case MENU:

        if(IsKeyPressed(KEY_N) ){
            GameScreen currentScreen = NOVOJOGO;
        }else if(IsKeyPressed(KEY_S)){
            // carrega o jogo
        }else if(IsKeyPressed(KEY_C)){
            // acessa configurações
            // -> mudar fps, lista dos pokémons, etc
        }
        break;

        case NOVOJOGO:
        // novoJogo();
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
        }else if(IsKeyPressed(KEY_E)){
            //Configurar FPS
            scanf("%i", &targetfps);
        }
        break;


    }







    BeginDrawing();
        ClearBackground(SKYBLUE);

        DrawText("Pokémon: Caio's Adventure", 200, 230, 65, VIOLET);
        DrawText("| N |Começar uma nova aventura", 200, 300, 45, LIME);
        DrawText("| S |Carregar seu jogo", 200, 370, 45, LIME);
        DrawText("| C |Configurações", 200, 440, 45, LIME);
        DrawFPS(10, 10);
        
    EndDrawing();

    }

    return 0;

}

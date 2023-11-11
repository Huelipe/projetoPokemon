#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Troca de Textura na Raylib");
    SetTargetFPS(60);

    Texture2D texture1 = LoadTexture("imagens/transicao.gif");
    Texture2D texture2 = LoadTexture("imagens/campusApucarana.png");

    // Variáveis para controlar a transição
    float timer = 0.0f;
    bool transition = false;

    while (!WindowShouldClose()) {
        // Atualizar o timer com o tempo entre frames
        timer += GetFrameTime();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Desenhar a textura atual
        if (!transition) {
            DrawTexture(texture1, screenWidth / 2 - texture1.width / 2, screenHeight / 2 - texture1.height / 2, WHITE);
        } else {
            DrawTexture(texture2, screenWidth / 2 - texture2.width / 2, screenHeight / 2 - texture2.height / 2, WHITE);
        }

        EndDrawing();

        // Verificar se passaram 2 segundos para mudar a textura
        if (timer >= 2.0f) {
            // Iniciar a transição
            transition = !transition;
            timer = 0.0f; // Reiniciar o timer para a próxima transição
        }
    }

    UnloadTexture(texture1);
    UnloadTexture(texture2);
    CloseWindow();

    return 0;
}

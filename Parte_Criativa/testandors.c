#include <raylib.h>
#include <math.h>

int main(void) {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Texture Transition Example");

    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);
    SetTargetFPS(60);

    Texture2D texture1 = LoadTexture("path/to/texture1.png");
    Texture2D texture2 = LoadTexture("path/to/texture2.png");

    float transitionRadius = 0.0f;
    float maxRadius = sqrt(powf(screenWidth, 2) + powf(screenHeight, 2)) / 2;

    while (!WindowShouldClose()) {
        BeginDrawing();

        // Update: Aumentando a velocidade
        transitionRadius += 6.0f; // Ajuste o valor conforme necessário

        if (transitionRadius > maxRadius) {
            transitionRadius = 0.0f;
        }

        // Draw to the render texture
        BeginTextureMode(target);
        ClearBackground(RAYWHITE);

        DrawTexture(texture1, 0, 0, WHITE);
        
        // DrawCircle com a cor verde claro (RGBA: 144, 238, 144, 255)
        DrawCircle(screenWidth / 2, screenHeight / 2, transitionRadius, (Color){144, 238, 144, 255});

        EndTextureMode();

        // Draw the render texture
        DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);

        EndDrawing();
    }

    // Cleanup
    UnloadRenderTexture(target);
    UnloadTexture(texture1);
    UnloadTexture(texture2);

    CloseWindow();

    return 0;
}


#include <raylib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 20 // Tamanho máximo da palavra a ser digitada

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Digite uma palavra");

    char input[MAX_CHARS + 1] = { 0 }; // String para armazenar a palavra
    int charCount = 0; // Contador de caracteres

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Digite uma palavra e pressione Enter:", 100, 180, 20, DARKGRAY);
        DrawText(input, 100, 220, 20, DARKGRAY);

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

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

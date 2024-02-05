#include "raylib.h"

constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 720;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "[TANK NAME HERE] Controller");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);

        DrawText("It's a work in progress, oK?", 5, 5, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

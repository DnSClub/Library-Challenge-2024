#include "raylib_mini.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib Mini Example");

    SetTargetFPS(60);

    // main gameloop
    while (!WindowShouldClose()) {
        if (IsKeyPressed(VK_ESCAPE)) {
            CloseWindow();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 120, 200, 20, LIGHTGRAY);
        DrawText("Press ESC to close the window.", 120, 240, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

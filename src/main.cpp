#include "Grid.h"
#include "raylib.h"
#include "GridRenderer.h"
#include "Solver.h"

int main() {
    Grid grid(21, 21);
    grid.initialize();

    Solver solver(grid, 0.1f, 1.0f);
    GridRenderer renderer(grid, 40);

    #ifdef __APPLE__
        SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    #endif
    InitWindow(840, 840, "Heat Equation");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        solver.step();
        BeginDrawing();
        ClearBackground(WHITE);
        renderer.draw();
        EndDrawing();
    }

    CloseWindow();
}
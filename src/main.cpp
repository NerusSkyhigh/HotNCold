#include "Grid.h"
#include "raylib.h"
#include "GridRenderer.h"
#include "Solver.h"

int main() {
    Grid grid(10, 10);
    grid.initialize();

    Solver solver(grid, 0.1f, 1.0f);
    GridRenderer renderer(grid, 80);

    InitWindow(800, 800, "Heat Equation");
    SetTargetFPS(12000);

    while (!WindowShouldClose()) {
        solver.step();
        BeginDrawing();
        ClearBackground(WHITE);
        renderer.draw();
        EndDrawing();
    }

    CloseWindow();
}
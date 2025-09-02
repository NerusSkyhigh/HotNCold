//
// Created by Gugli on 02/09/2025.
//

#include "../include/GridRenderer.h"
#include "raylib.h"
#include <format>
#include <string>

GridRenderer::GridRenderer(Grid& grid, int pixelSize) : grid(grid), pixelSize(pixelSize) {}

void GridRenderer::draw() {
    float Tmin = 0.0;
    float Tmax = 18.0;
    for (int row = 0; row < grid.Ny(); row++) {
        for (int col = 0; col < grid.Nx(); col++) {
            float T = grid.T_at(col, row); // or whatever returns temperature
            float normalized = (T - Tmin) / (Tmax - Tmin);
            if (normalized < 0) normalized = 0;
            if (normalized > 1) normalized = 1;
            Color color = {(unsigned char)(normalized * 255), 0, (unsigned char)((1 - normalized) * 255), 255};

            if ((fabsf(grid.alpha_at(col, row) - 0.0) < 0.001) &&
                !(col == grid.Nx() / 2 && row == grid.Ny() / 2)
            )
                color = BLACK;

            drawPixel(pixelSize * col, pixelSize * row, color);
        }
    }
}

void GridRenderer::drawPixel(int cx, int cy, Color color) {
    int ox = cx; // - pixelSize / 2; // Origin on x
    int oy = cy; // - pixelSize / 2;
    DrawRectangle(ox, oy, pixelSize, pixelSize, color);

    std::string temp;
    float T = (grid.T_at(cx / pixelSize, cy / pixelSize) * 100);
    T = static_cast<int>(T) / 100.f;
    temp = std::to_string(T);
    DrawText(temp.c_str(), ox + pixelSize / 4, cy + pixelSize / 2, 9, WHITE);
}
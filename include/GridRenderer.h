//
// Created by Gugli on 02/09/2025.
//
#pragma once

#include "Grid.h"
#include "raylib.h"

class GridRenderer {
public:
    GridRenderer(Grid& grid, int pixelSize);

    void draw();

private:
    Grid& grid;
    int pixelSize;

    void drawPixel(int cx, int cy, Color color);
};
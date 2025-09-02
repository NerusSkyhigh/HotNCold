//
// Created by Gugli on 02/09/2025.
//
#pragma once
#include "Grid.h"

class Solver {
public:
    Solver(Grid& grid, float dt, float dx);

    void step();

private:
    Grid& grid;
    float dt;
    float dx;
};
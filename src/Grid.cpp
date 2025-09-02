//
// Created by Gugli on 27/08/2025.
//

#include "../include/Grid.h"

Grid::Grid(int nx_, int ny_) : ncols(nx_), nrows(ny_) {
    for (auto& v : T) {
        v.assign(ncols * nrows, 0.1f);
    }
    alpha.assign(ncols * nrows, 0.0f);
}


void Grid::initialize() {
    for (int row = 0; row < nrows; row++) {
        for (int col = 0; col < ncols; col++) {
            /* Set perfect insulating walls on the border of the house */
            if (!(row == 1 || row == nrows - 2 || col == 1 || col == ncols - 2)) {
                alpha_at(col, row) = 1;
            }
        }
    }

    int center_x = ncols / 2;
    int center_y = nrows / 2;

    alpha_at(center_x, center_y) = 0; // It's cold. Let's place a heater in the center of the house
    T_at(center_x, center_y) = 18; // Don't waster energy, put a sweater
    swap(); //Writing is finished
}
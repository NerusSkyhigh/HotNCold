//
// Created by Gugli on 27/08/2025.
//

#pragma once
#include <vector>


class Grid {
public:
    Grid(int nx, int ny);

    void initialize();

    inline float& T_at(int col, int row) { return T[1 - current_read][row * ncols + col]; }
    inline const float& T_at(int col, int row) const { return T[current_read][row * ncols + col]; }

    inline float& alpha_at(int col, int row) { return alpha[row * ncols + col]; }
    inline const float& alpha_at(int col, int row) const { return alpha[row * ncols + col]; }

    int Nx() const { return ncols; }
    int Ny() const { return nrows; }

    void swap() { current_read = 1 - current_read; }

    inline const float* get_ptr_read() const { return T[current_read].data(); }
    inline float* get_ptr_write() { return T[1 - current_read].data(); }

private:
    int ncols, nrows;

    // Buffers for temperature
    std::vector<float> T[2];
    int current_read = 0;

    std::vector<float> alpha; // Thermal diffusivity
};
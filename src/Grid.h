//
// Created by Gugli on 27/08/2025.
//

#pragma once
#include <vector>


class Grid {
public:
    Grid(int nx, int ny);

    void initialize();

    float& at(int i, int j);
    const float& at(int i, int j) const;

    float& alpha(int i, int j);
    const float& alpha(int i, int j) const;

    int Nx() const;
    int Ny() const;

private:
    int nx, ny;

    std::vector<float> T;
    std::vector<float> T_next;

    std::vector<float> k; // Thermal diffusivity

    inline int idx(int i, int j) const;
};

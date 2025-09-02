#include "Solver.h"
#include "Grid.h"

Solver::Solver(Grid& grid, float dt, float dx)
    : grid(grid), dt(dt), dx(dx) {}

void Solver::step() {
    const float* curr = grid.get_ptr_read();
    float* next = grid.get_ptr_write();

    int nx = grid.Nx();
    int ny = grid.Ny();
    float inv_dx2 = 1.0f / (dx * dx);

    for (int row = 1; row < ny - 1; row++) {
        int base = row * nx;
        for (int col = 1; col < nx - 1; col++) {
            int idx = base + col;
            float a = grid.alpha_at(col, row);

            float laplacian = curr[idx - 1] + curr[idx + 1] +
                curr[idx - nx] + curr[idx + nx] -
                4.0f * curr[idx];
            next[idx] = curr[idx] + dt * a * inv_dx2 * laplacian;
        }
    }

    grid.swap();
}
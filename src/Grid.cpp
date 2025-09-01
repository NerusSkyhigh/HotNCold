//
// Created by Gugli on 27/08/2025.
//

#include "grid.h"

Grid::Grid(int nx_, ny_) : nx(nx_), ny(ny_) {
    T.resize(nx * ny);
    T_next.resize(nx * ny);
    k.resize(nx * ny);
}


void Grid::initialize() {
    for(int j=0; j<ny; j++) {
        for(int i=0; i<nx; i++) {
			if(j==0 || j==nx-1 || i==0 || i==nx-1) {
			}
        }
    }
}
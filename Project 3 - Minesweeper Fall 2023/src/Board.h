#pragma once
#include "Tile.h"
#include <vector>

class Board{

    int total_mines;
    int counter;

    std::vector<std::vector<Tile>> tile_vector; // tile_vector[row][col]

public:

    Board();
    void setup_tiles(int rows, int cols);

};


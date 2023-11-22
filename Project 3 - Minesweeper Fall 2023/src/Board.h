#pragma once
#include "Tile.h"
#include <vector>

class Board{

    int _mines, _rows, _cols;
    int counter; // how many flags placed

    std::vector<std::vector<Tile>> tile_vector; // tile_vector[row][col]


    // helpers
    void init_board(int rows, int cols);
    void init_mines(int mines);

public:

    Board();
    void setup_tiles(int rows, int cols, int mines);
    
    bool board_won(); // returns of board was won
    void show_board(); // reveal every tile on board
    void draw_board(); // draw board?

};


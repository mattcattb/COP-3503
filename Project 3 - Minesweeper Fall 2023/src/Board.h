#pragma once
#include "Tile.h"
#include <vector>
#include <SFML/Graphics.hpp>

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
    
    bool board_won(); // determines if board won
    void reveal_all(); // set every tile to revealed
    void draw_tiles(sf::RenderWindow &window); // draw each tile in board

};


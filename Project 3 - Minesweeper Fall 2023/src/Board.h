#pragma once
#include "Tile.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Texture_Manager.h"

class Board{

    int _mines, _rows, _cols;
    int counter; // how many flags placed

    std::vector<std::vector<Tile>> tile_vector; // tile_vector[row][col]

    // initialize board and place mines
    void init_board(Texture_Manager &manager);
    void init_board_neighbors();

    void randomize_mines(int mines);

public:

    Board(int rows, int cols, int mines, Texture_Manager &manager);
    
    // get information on board
    bool board_won(); // determines if board won
    
    // change board state
    void reveal_all(); // set every tile to revealed

    // draw board
    void draw_tiles(sf::RenderWindow &window); // draw each tile in board

};


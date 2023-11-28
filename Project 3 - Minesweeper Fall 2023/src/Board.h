#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <random>

#include "Tile.h"
#include "Texture_Manager.h"


//Todo
/*

    - randomly place mines
    - maybe smarter updating of each tiles sprite loader

*/


class Board{

    int _mines, _rows, _cols;
    int counter; // what counter should display (starts at num mines)

    std::vector<std::vector<Tile>> tile_vector; // tile_vector[row][col]

    // initialize board and place mines
    void create_empty_board(Texture_Manager &manager);
    void set_board_neighbors();
    void randomize_mines(int mines);

public:

    Board(int rows, int cols, int mines, Texture_Manager &manager);
    
    // update each tiles states?
    void update_board(sf::Vector2i mouse_pos, bool left_click);

    // get information on board
    bool board_won(); // determines if board won
    
    // change board state
    void reveal_all(); // set every tile to revealed

    // draw board
    void draw_tiles(sf::RenderWindow &window); // draw each tile in board

    // debugging
    void print_board(); // print all tiles in board

};


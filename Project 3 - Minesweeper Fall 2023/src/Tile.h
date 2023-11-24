#pragma once
#include <vector>
#include "Texture_Manager.h"

class Tile{

    bool _revealed, _is_mine, _has_flag;

    int _row, _col; // row,col location of tile

    Tile* neighbors[8];


    Texture_Manager * texture_manager;
    sf::Sprite tile_sprite;

    void init_variables(int row, int col); // setup all variables
    void init_neighbors(); // set all neighbors null
    void set_sprite();

public:

    Tile(int row, int col, Texture_Manager &manager);

    void setup_neighbors(std::vector<std::vector<Tile>> board);

    // state changers
    void become_mine(){_is_mine = true;}; // turns tile into a mine
    void reveal(); // set tile state to reveal

    // getters 
    bool is_mine(){return _is_mine;};
    int get_adjacent_mines(); // returns number of hidden mines
    int get_draw_state(); // returns state to be drawn

};


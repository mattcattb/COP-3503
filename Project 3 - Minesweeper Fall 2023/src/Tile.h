#pragma once
#include <vector>
#include "Texture_Manager.h"
#include <iostream>

class Tile{

    bool _revealed, _is_mine, _has_flag;

    int _row, _col; // row,col location of tile
    int _xpos, _ypos; // x and y position of tile

    Tile* neighbors[8];

    Texture_Manager * texture_manager;
    
    std::vector<sf::Sprite*> sprite_loader;

    void init_variables(int row, int col); // setup all variables
    void set_neighbors_null(); // set all neighbors null
    void calculate_position(); // find the x and y position of tile 

    // set sprite loader according to state
    void set_loader();

    // helper to get drawing state
    void add_sprite(std::string texture_name);

public:

    Tile(int row, int col, Texture_Manager &manager);

    void setup_neighbors(std::vector<std::vector<Tile>> board);

    void draw(sf::RenderWindow &window); // draw all loaded sprites

    // state changers
    void become_mine(){_is_mine = true;}; // turns tile into a mine
    void reveal(){_revealed = true;}; // set tile state to reveal
    void toggle_flag(){_has_flag = !_has_flag;}; // add or remove flag

    // getters 
    bool is_mine(){return _is_mine;};
    int get_adjacent_mines(); // returns number of hidden mines

    // debugging
    void print_tile();

};


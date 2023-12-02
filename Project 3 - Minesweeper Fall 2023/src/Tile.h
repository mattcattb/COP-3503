#pragma once
#include <vector>
#include "Texture_Manager.h"
#include <iostream>


//Todo
/*

    //- make tiles with flags unrevealable
    // - not let revealed tiles to be flag placed
    - recursively reveal all other tiles if no mines surround tile
    //- randomly place mines
    - reveal if game is won 
    //- make left and right clicked actions to better organize stuff
    - draw mine on top of flag if mine revealed

*/


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

    // helper to get drawing state
    void add_sprite(std::string texture_name);

public:

    Tile(int row, int col, Texture_Manager &manager);
    void setup_neighbors(std::vector<std::vector<Tile>> &board);
    void draw(sf::RenderWindow &window); // draw all loaded sprites

    // state changers
    int left_click(); // reveal
    int right_click(); // toggle flag

    void become_mine(); // turns tile into a mine
    void reveal(); // set tile state to reveal
    void hide(); // hide tile

    void mask();
    void unmask();

    // getters 
    bool is_mine(){return _is_mine;};
    bool flag_placed(){return _has_flag;};
    int get_adjacent_mines(); // returns number of hidden mines

    // debugging
    void print_tile();
    void print_neighbors();

    // set sprite loader according to state
    void set_loader();

};


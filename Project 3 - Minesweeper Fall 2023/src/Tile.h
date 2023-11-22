#pragma once
#include <vector>

class Tile{

    bool _revealed, _is_mine, _has_flag;

    int _row, _col; // row,col location of tile

    Tile* neighbors[8];

    void init_variables(int row, int col, bool mine); // setup all variables
    void init_neighbors(); // set all neighbors null

public:

    Tile(int row, int col, bool mine = false);
    int setup_neighbors(std::vector<std::vector<Tile>> board);

    // getters 
    bool is_mine(){return _is_mine;};
    int get_adjacent_mines(); // returns number of hidden mines
    int get_draw_state(); // returns state to be drawn

    void reveal(); // set tile state to reveal

};


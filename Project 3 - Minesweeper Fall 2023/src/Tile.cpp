#include "Tile.h"


Tile::Tile(int row, int col, bool mine){

    // set the row, col of that tile 
    this->row = row;
    this->col = col;
    
    // set variables
    revealed = false;
    is_mine = mine;
    adjacent_tiles = 0;
    adjacent_mines = 0;
    
    // set all surrounding tiles to null (for now)
    for(int i = 0; i < 8; i += 1){
        neighbors[i] = nullptr;
    }
}
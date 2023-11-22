#include "Tile.h"

Tile::Tile(int row, int col, bool mine){

    init_variables(row, col, mine);
    init_neighbors();

}

int Tile::get_adjacent_mines(){
    // returns number of hidden mines by cycling through neighbords
    int num_adjacent = 0;
    for(int i = 0; i < 8; i += 1){
        if (neighbors[i] != nullptr && )
    }
}

int Tile::setup_neighbors(std::vector<std::vector<Tile>> board){
    // using board and current location, setup 
    int max_rows = board.size();
    int max_cols = board[0].size();

    int placement = 0;

    for(int i = -1; i <= 1; i += 1 ){
        for(int j = -1; i <= 1; j += 1){
            if (i == 0 && j == 0){
                // skip the case where we look at our own tile
                continue;
            }
            int cur_row = _row + i;
            int cur_col = _col + j;
            
            if(cur_row < 0 || cur_row >= max_rows){
                // check if row out of bounds
                neighbors[placement] = nullptr;

            }else if (cur_col < 0 || cur_col >= max_cols){
                // check if col out of bounds
                neighbors[placement] = nullptr;
            }else{
                // still in board bounds, so point to it
                neighbors[placement] = &board[cur_row][cur_col];
            }

            // incriment placement
            placement += 1;
        }
    }
}


// init functions

void Tile::init_variables(int row, int col, bool mine){

    // set the row, col of that tile 
    _row = row;
    _col = col;
    
    // set variables
    _revealed = false;
    _is_mine = mine;
    _has_flag = false;
    adjacent_tiles = 0;
    adjacent_mines = 0;

}

void Tile::init_neighbors(){
    // set all surrounding tiles to null (for now)
    for(int i = 0; i < 8; i += 1){
        neighbors[i] = nullptr;
    }
}
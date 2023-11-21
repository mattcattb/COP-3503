#include "Board.h"

Board::Board(int rows, int cols){
    
    for(int r = 0; r < rows; r += 1){
        for(int c = 0; c < cols; c += 1){
            //! need to determine if the tile is a mine or not!
            tile_vector[r][c] = Tile(r, c);
        }
    } 

    // now need to go through each tile and set its neighbors array, and if its a pointer or not

}
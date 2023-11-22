#include "Board.h"

Board::Board(){
    // now need to go through each tile and set its neighbors array, and if its a pointer or not

}



void Board::setup_tiles(int rows, int cols, int mines){
    
    // sets up board
    init_board(rows, cols);
    init_mines(mines);

}
bool Board::board_won(){ 
    // returns of board was won
}

void Board::show_board(){ // reveal every tile on board

}

void Board::draw_board(){ 
    // draw board?
}

// init functions

void Board::init_board(int rows, int cols){
    // inits each tile in board, not yet setting mines 
    for(int r = 0; r < rows; r += 1){
        for(int c = 0; c < cols; c += 1){
            // initially set all times to no mine
            tile_vector[r][c] = Tile(r, c);
        }
    } 
}

void Board::init_mines(int mines){
    // places mines upon actual board.. HOW DO I DO THIS!!
}

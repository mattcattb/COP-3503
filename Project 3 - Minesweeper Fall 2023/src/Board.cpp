#include "Board.h"

Board::Board(int rows, int cols, int mines, Texture_Manager &manager){
    // now need to go through each tile and set its neighbors array, and if its a pointer or not
    
    // create mineless board 
    _rows = rows;
    _cols = cols;

    // set 2D vector of tiles (no mines) 
    init_board(manager);

    // set boards neighbords
    init_board_neighbors();

    // place all mines on board
    randomize_mines(mines);

}

// init functions

void Board::init_board(Texture_Manager &manager){
    // inits each tile in board, not yet setting mines 
    for(int r = 0; r < _rows; r += 1){
        for(int c = 0; c < _cols; c += 1){
            // initially set all times to no mine
            tile_vector[r][c] = Tile(r, c, manager);
        }
    } 
}

void Board::randomize_mines(int mines){
    //! places mines upon actual board.. HOW DO I DO THIS!!
}

void Board::init_board_neighbors(){
    // set each tiles neighbors
    for(int r = 0; r < _rows; r += 1){
        for (int c = 0; c < _cols; c += 1){
            tile_vector[r][c].setup_neighbors(tile_vector);
        }
    }
}


// getters 

bool Board::board_won(){ 
    //! returns of board was won
    
    return true;
}


// change board state

void Board::reveal_all(){ 
    // reveal every tile on board
    for(int row = 0; row < _rows; row += 1){
        for(int col = 0; col < _cols; col += 1){
            tile_vector[row][col].reveal();
        }
    }

}

void Board::draw_tiles(sf::RenderWindow &window){ 
    // draw each tile in board

    for(int row = 0; row < _rows; row += 1){
        for(int col = 0; col < _cols; col += 1){

            tile_vector[row][col].draw(window);

        }
    }
}


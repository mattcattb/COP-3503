#include "Board.h"

Board::Board(){
    // now need to go through each tile and set its neighbors array, and if its a pointer or not
    

}



void Board::setup_tiles(int rows, int cols, int mines, Texture_Manager &manager){
    
    // sets up board

    // create mineless board 
    _rows = rows;
    _cols = cols;
    init_board(Texture_Manager &manager);

    // place all mines on board
    init_mines(mines);

}
bool Board::board_won(){ 
    //? returns of board was won
    
    return true;
}

void Board::reveal_all(){ 
    // reveal every tile on board
    for(int row = 0; row < _rows; row += 1){
        for(int col = 0; col < _cols; col += 1){
            tile_vector[row][col].reveal();
        }
    }

}

void Board::draw_tiles(sf::RenderWindow &window, Texture_Manager &manger){ 
    // draw each tile in board

    int side_len = side_length(window);
    float cur_x, cur_y;

    for(int row = 0; row < _rows; row += 1){
        for(int col = 0; col < _cols; col += 1){

            cur_x = side_len*col + 0.5*side_len;
            cur_y = side_len*row + 0.5*side_len;

            //! we have the position, now we must draw tile according to its state


        }
    }
}

int Board::side_length(sf::RenderWindow &window){
    // calculate x and y of an orgin

    sf::Vector2u windowSize = window.getSize();

    unsigned int windowWidth = windowSize.x;
    unsigned int windowHeight = windowSize.y;

    int side_len = windowWidth/_cols;
    return side_len; 

}

// init functions

void Board::init_board(int rows, int cols, Texture_Manager &manager){
    // inits each tile in board, not yet setting mines 
    for(int r = 0; r < rows; r += 1){
        for(int c = 0; c < cols; c += 1){
            // initially set all times to no mine
            tile_vector[r][c] = Tile(r, c, manager);
        }
    } 
}

void Board::init_mines(int mines){
    //! places mines upon actual board.. HOW DO I DO THIS!!
}

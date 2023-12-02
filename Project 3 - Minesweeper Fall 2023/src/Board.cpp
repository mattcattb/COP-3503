#include "Board.h"

Board::Board(int rows, int cols, int mines, Texture_Manager &manager){
    // now need to go through each tile and set its neighbors array, and if its a pointer or not
    
    // create mineless board 
    _rows = rows;
    _cols = cols;
    _mines = mines;
    counter = mines;
    _state = 0; // -1: defeat, 0 still playing, 1: victory

    texture_manager = &manager;

    // set 2D vector of tiles (no mines) 
    create_empty_board();

    // place all mines on board
    randomize_mines(mines);

    // set boards neighbors
    set_board_neighbors();
    
}

// init functions

void Board::create_empty_board(){

    tile_vector.clear();

    // first, push back each row
    for (int r = 0; r < _rows; r++) {
        tile_vector.push_back(std::vector<Tile>()); // Add an empty row
    }

    // now, add columns  
    for(int r = 0; r < _rows; r += 1){
        for(int c = 0; c < _cols; c += 1){
            // initially set all times to no mine
            tile_vector[r].push_back(Tile(r, c, *texture_manager));
        }
    } 
}

void Board::randomize_mines(int mines){

        // Create a random number generator engine
    std::random_device rd; // Obtain a random seed from the hardware
    std::mt19937 gen(rd()); // Mersenne Twister 19937 generator

    // Define a distribution (e.g., uniform integer distribution)
    std::uniform_int_distribution<int> cols_distribution(0, _cols - 1); // Range from 1 to 6 (inclusive)
    std::uniform_int_distribution<int> rows_distribution(0, _rows - 1);

    
    for(int i = 0; i < mines; i += 1){

        int rand_col, rand_row;

        do{
            rand_col = cols_distribution(gen);
            rand_row = rows_distribution(gen);
        }while(tile_vector[rand_row][rand_col].is_mine());
        // now, rand_col and rand_row are not a mine, so make it into a mine
        tile_vector[rand_row][rand_col].become_mine();
    }

}

void Board::set_board_neighbors(){
    // set each tiles neighbors
    for(int r = 0; r < _rows; r += 1){
        for (int c = 0; c < _cols; c += 1){
            tile_vector[r][c].setup_neighbors(tile_vector);
        }
    }
}


// getters 

int Board::board_state(){ 
    //TODO -1 board lost, 0 still playing, 1 board solved
    // checks board for an update to the state.
    return _state;
}


// change board state

void Board::reveal_all(){ 
    // reveal every tile on board
    for(int row = 0; row < _rows; row += 1){
        for(int col = 0; col < _cols; col += 1){
            tile_vector[row][col].reveal();
            tile_vector[row][col].set_loader();
        }
    }

}

void Board::reveal_mines(){
    // reveals all mines in board
    for(int r = 0; r < _rows; r += 1){
        for (int c = 0; c < _cols; c += 1){
            if (tile_vector[r][c].is_mine()){
                tile_vector[r][c].reveal();
                tile_vector[r][c].set_loader();
            }
        }
    }
}

void Board::hide_mines(){
    // hides all mines in board

    for(int r = 0; r < _rows; r += 1){
        for (int c = 0; c < _cols; c += 1){
            if (tile_vector[r][c].is_mine()){
                tile_vector[r][c].hide();
                tile_vector[r][c].set_loader();
            }
        }
    }

}

void Board::reset_board(){
    std::cout << "resetting board!" << std::endl;

    counter = _mines;
    _state = 0; // -1: defeat, 0 still playing, 1: victory

    create_empty_board();
    randomize_mines(_mines);
    set_board_neighbors();
} 

void Board::mask(){ 
    // adds empty tile to each tile
    for(int r = 0; r < _rows; r += 1){
        for(int c = 0; c < _cols; c += 1){
            tile_vector[r][c].mask();
        }
    }
}

void Board::unmask(){ 
    // removes empty tile mask
    for(int r = 0; r < _rows; r += 1){
        for(int c = 0; c < _cols; c += 1){
            tile_vector[r][c].unmask();
        }
    }
}

void Board::draw_tiles(sf::RenderWindow &window){ 
    // draw each tile in board

    for(int row = 0; row < _rows; row += 1){
        for(int col = 0; col < _cols; col += 1){
            // draw tile!
            tile_vector[row][col].draw(window);

        }
    }
}

void Board::update_board(sf::Vector2i mouse_pos, bool left_click){
    // TODO determine if game state is changed by these updates!
    
    // updates board with mouse position and left/right click
    int col_clicked = mouse_pos.x/32;
    int row_clicked = mouse_pos.y/32;

    if (left_click){
        // left click: reveal
        if (tile_vector[row_clicked][col_clicked].is_mine()){
            _state = -1; // state is now lost!
        }
        tile_vector[row_clicked][col_clicked].left_click();

    }else{
        // right click: place/remove flag and also change counter
        counter -= tile_vector[row_clicked][col_clicked].right_click();
    }
}


// debuggings stuff

void Board::print_board(){
    for(int r = 0; r < _rows; r += 1){
        for(int c = 0; c < _cols; c += 1){
            tile_vector[r][c].print_tile();
        }
    }
}
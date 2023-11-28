#include "Board.h"

Board::Board(int rows, int cols, int mines, Texture_Manager &manager){
    // now need to go through each tile and set its neighbors array, and if its a pointer or not
    
    // create mineless board 
    _rows = rows;
    _cols = cols;
    _mines = mines;
    counter = mines;

    // set 2D vector of tiles (no mines) 
    std::cout <<"creating empty board\n";
    create_empty_board(manager);

    // set boards neighbors
    std::cout << "setting board neighbors\n";
    set_board_neighbors();

    // place all mines on board
    std::cout << "placing mines on board\n";
    randomize_mines(mines);

}

// init functions

void Board::create_empty_board(Texture_Manager &manager){

    // first, push back each row
    for (int r = 0; r < _rows; r++) {
        tile_vector.push_back(std::vector<Tile>()); // Add an empty row
    }

    // now, add columns  
    for(int r = 0; r < _rows; r += 1){
        for(int c = 0; c < _cols; c += 1){
            // initially set all times to no mine
            tile_vector[r].push_back(Tile(r, c, manager));
        }
    } 
}

void Board::randomize_mines(int mines){

        // Create a random number generator engine
    std::random_device rd; // Obtain a random seed from the hardware
    std::mt19937 gen(rd()); // Mersenne Twister 19937 generator

    // Define a distribution (e.g., uniform integer distribution)
    std::uniform_int_distribution<int> cols_distribution(0, _cols); // Range from 1 to 6 (inclusive)
    std::uniform_int_distribution<int> rows_distribution(0, _rows);

    
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
            // draw tile!
            tile_vector[row][col].draw(window);

        }
    }
}

void Board::update_board(sf::Vector2i mouse_pos, bool left_click){
    // updates board with mouse position and left/right click
    int col_clicked = mouse_pos.x/32;
    int row_clicked = mouse_pos.y/32;

    std::cout << "tile clicked! row " << row_clicked << " col " << col_clicked << std::endl;
    
    if (left_click){
        // left click: reveal
        tile_vector[row_clicked][col_clicked].reveal();
    }else{
        // right click: place/remove flag and also change counter
        counter += tile_vector[row_clicked][col_clicked].toggle_flag();
    }
    tile_vector[row_clicked][col_clicked].set_loader();
}


// debuggings stuff

void Board::print_board(){
    for(int r = 0; r < _rows; r += 1){
        for(int c = 0; c < _cols; c += 1){
            tile_vector[r][c].print_tile();
        }
    }
}
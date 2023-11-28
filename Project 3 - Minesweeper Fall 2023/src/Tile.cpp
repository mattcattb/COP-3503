#include "Tile.h"

Tile::Tile(int row, int col, Texture_Manager &manager){

    init_variables(row, col); // init tiles variables
    set_neighbors_null(); // set all neighbors to nullptr first
    texture_manager = &manager; // set texture manager

    // set loader (should be empty tile)
    set_loader();

}

// init functions

void Tile::init_variables(int row, int col){

    // set the row, col of that tile 
    _row = row;
    _col = col;

    _is_mine = false;
    
    // set variables
    _revealed = false;
    _has_flag = false;

    // find the x and y position of tile 
    _xpos = 32*(_col);
    _ypos = 32*(_row);

}

void Tile::set_neighbors_null(){
    // set all surrounding tiles to null (for now)
    for(int i = 0; i < 8; i += 1){
        neighbors[i] = nullptr;
    }
}

// information getters

int Tile::get_adjacent_mines(){
    // returns number of hidden mines by cycling through neighbords
    int num_adjacent = 0;

    for(int i = 0; i < 8; i += 1){
        if (neighbors[i] != nullptr && neighbors[i]->is_mine()){
            num_adjacent += 1;
        }
    }

    return num_adjacent;
}

void Tile::setup_neighbors(std::vector<std::vector<Tile>> board){
    // using board and current location, setup 
    int max_rows = board.size();
    int max_cols = board[0].size();

    int placement = 0;
    
    for(int i = -1; i <= 1; i += 1 ){
        for(int j = -1; j <= 1; j += 1){
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

// sprite loading

void Tile::set_loader(){
    // setup sprite loader vector according to state

    // first, clear previous sprite loader
    sprite_loader.clear(); 

    // store tile position on board
    sf::Vector2f tile_position(_xpos, _ypos);

    if (!_revealed){
        // if hidden, just add a hidden tile sprite (and flag if needed) 
        add_sprite("tile_hidden");
        
        if (_has_flag){
            // if tile has a flag, also add this flag on top too
            add_sprite("flag");
        }

        // finished adding all, leave
        return;

    }else if (_revealed){
        // if revealed, add a shown tile
        add_sprite("tile_revealed");
    }
    
    if (_is_mine){
        // put a mine on top!
        add_sprite("mine");

    }else {
        // tile is not a mine, so must display its number. 
        int neighbors = get_adjacent_mines();
        
        if (neighbors > 0){
            // draw the number on top!
            std::string image_location = "number_" + neighbors;
            add_sprite(image_location);
        }
    }

}

void Tile::draw(sf::RenderWindow &window){
    // draw each sprite in sprite_loader
    set_loader(); // set vector of sprites to draw
    for(int i = 0; i < sprite_loader.size(); i += 1){
        sf::Sprite *cur_sprite = sprite_loader[i];
        window.draw(*cur_sprite);
    }

}

// ============ helpers I guess

void Tile::add_sprite(std::string texture_name){
    // creates and adds sprite to sprite_loader, setting position 
    sf::Sprite * new_sprite = new sf::Sprite();
    new_sprite->setTexture(texture_manager->getTexture(texture_name));
    new_sprite->setPosition(sf::Vector2f(_xpos, _ypos)); 
    sprite_loader.push_back(new_sprite);
}

// ============ debugging

void Tile::print_tile(){
    std::cout << std::endl;
    std::cout << "revealed: " << _revealed << " is_mine: " << _is_mine << " has_flag: " << _has_flag << std::endl;
    std::cout << "_row, _col: (" << _row << ", " << _col << ")\n";
    std::cout << "_xpos, _ypos: (" << _xpos << ", " << _ypos << ")\n";   
    std::cout << std::endl;
}

// ============ State Changers ============

int Tile::toggle_flag(){
    // toggle flag maybe?

    // remember, if revealed we CANNOT add a flag
    if (_revealed){
        return 0;
    }

    int return_val = 0;
    if (_has_flag == true){
        // we are removing a flag, add to mine counter
        return_val = 1;
    }else if (_has_flag == false){
        // we are adding a flag, so subtract from mine counter
        return_val = -1;
    }
    _has_flag = !_has_flag;

    return return_val;
}

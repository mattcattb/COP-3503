#pragma once

class Tile{

    bool revealed, is_mine;

    int adjacent_tiles, adjacent_mines;
    int row, col;

    sf::Sprite tile_sprite; 

    Tile* neighbors[8];

public:

    Tile(int row, int col, bool mine = false);
    void show(); // set tile to show 
    void draw(); // draw tile

};


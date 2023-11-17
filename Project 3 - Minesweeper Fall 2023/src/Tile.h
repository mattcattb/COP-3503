#pragma once

class Tile{

    bool revealed;
    bool is_mine;

    int adjacent_tiles;
    int adjacent_mines;

    Tile* neighbors[8];

public:


};
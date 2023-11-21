#pragma once

class Tile{

    bool revealed, is_mine;

    int adjacent_tiles, adjacent_mines;
    int row, col;

    Tile* neighbors[8];

public:

    Tile(int row, int col, bool mine = false);

};


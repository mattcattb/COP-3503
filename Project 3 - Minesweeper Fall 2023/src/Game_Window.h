#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Texture_Manager.h"
#include <string>
#include <iostream>

//Todo
/*

    - setup digits counter
    - integrate timer counter
    - have leaderboard show everything

*/


class Game_Window{


    // variables
    int _height, _width, _mines;
    int _cols, _rows;
    bool paused;

    std::string _username;

    Board *board;

    Texture_Manager* texture_manager;

    // happy face button
    sf::Sprite happy_button;
    // counter
    sf::Sprite counter;
    // debug button
    sf::Sprite debug_button;
    // pause/play button
    sf::Sprite pause_play_button;
    // leaderboard button
    sf::Sprite leaderboard_button;

    // timer
    sf::RenderWindow render_window;

    // init functions
    void init_board();
    void init_window();
    void init_variables(int rows, int cols, int mines, std::string username);
    void init_displays();
    void init_buttons();

    // update functions 
    void update_clickable_buttons(sf::Vector2i mouse_position);

    // draw functions
    void draw_all();
    void draw_buttons();
    void draw_displays();
    void draw_board();

    // helpers
    bool tile_clicked(sf::Vector2i mouse_pos); // bool if tile clicked

public:

    Game_Window(int rows, int cols, int mines, std::string username);
    ~Game_Window();

    int event_loop(); // returns -1 to say the window is closed, 1 to say to switch to game view

    void show_leaderboard(); // have leaderboard pop up

};
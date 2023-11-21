#include <SFML/Graphics.hpp>
#include "Board.h"

class Game_Window{


    // variables
    int _height, _width, _mines;
    int _cols, _rows;

    
    // game states
    bool paused;

    std::string character_name;
    Board board;

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
    void init_fonts();
    void init_window();
    void init_variables(int cols, int rows);
    void init_text();
    void init_buttons();

public:

    Game_Window(int cols, int rows, int mines);
    int event_loop(); // returns -1 to say the window is closed, 1 to say to switch to game view

    void show_leaderboard(); // have leaderboard pop up

};
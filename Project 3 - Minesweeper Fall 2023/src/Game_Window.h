#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>
#include <iostream>

#include "Board.h"
#include "Texture_Manager.h"
#include "Display.h"


//Todo
/*

    - make all share the same texture pointer, making speedup significantly
    //- setup digits counter
    - integrate timer counter
    - impliment leaderboard button
    //- toggle pause button
    //- debug button impliment

*/


class Game_Window{


    // === game and window variables
    int _height, _width, _mines;
    int _cols, _rows;
    bool paused;
    bool debugging;

    std::string _username;

    // === time variables
    std::chrono::system_clock::time_point prev; // prev time point
    std::chrono::system_clock::time_point now; // past time point
    std::chrono::seconds total_seconds_elapsed_time; // stored to be displayed as time passes
    // = std::chrono::seconds(0);


    // === game objects
    Board *board;
    Texture_Manager* texture_manager;
    sf::RenderWindow render_window;


    // === Buttons

    // happy face button
    sf::Sprite happy_button;
    // debug button
    sf::Sprite debug_button;
    // pause/play button
    sf::Sprite pause_play_button;
    // leaderboard button
    sf::Sprite leaderboard_button;
    
    // === Displays
    Display * counter;
    Display * minutes_timer;
    Display * seconds_timer;
    
    // === init functions
    void init_board();
    void init_window();
    void init_variables(int rows, int cols, int mines, std::string username);
    void init_displays();
    void init_buttons();

    // === update functions 
    void update_pause_button();
    void update_leaderboard();
    void update_debug_button();
    void update_happy_face_button();

    void update_time();

    // === draw functions
    void draw_all();
    void draw_buttons();
    void draw_displays();
    void draw_board();

    // === helpers
    bool tile_clicked(sf::Vector2i &mouse_pos); // bool if tile clicked
    bool pause_button_clicked(sf::Vector2i &mouse_pos); 
    bool leaderboard_button_clicked(sf::Vector2i &mouse_pos);
    bool debug_button_clicked(sf::Vector2i &mouse_pos);
    bool happy_face_button_clicked(sf::Vector2i &mouse_pos);

public:

    Game_Window(int rows, int cols, int mines, std::string username);
    ~Game_Window();

    int event_loop(); // returns -1 to say the window is closed, 1 to say to switch to game view

    void show_leaderboard(); // have leaderboard pop up

};
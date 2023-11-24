#include "Game_Window.h"


Game_Window::Game_Window(int rows, int cols, int mines, std::string username){

    // setup board!
    // initialize parts of display
    init_variables(rows, cols, mines, username);
    init_buttons();
    init_window();
    init_displays();
    init_board();
    
}

int Game_Window::event_loop(){

    // returns -1 to say the window is closed, 1 to say to switch to game view

    while (render_window.isOpen())
    {
        sf::Event event;
        
        while(render_window.pollEvent(event)){
            switch (event.type)
            {
            
            case sf::Event::Closed:
                // window closed!
                render_window.close();
                
                return -1;
                            
            case sf::Event::MouseButtonPressed:
                switch (event.key.code)
                {
                case sf::Mouse::Left:
                    // left key pressed
                    break;
                
                case sf::Mouse::Right:
                    // right key pressed
                    break;

                default:
                    break;
                }

            default:
                break;
            }
        }

        // update everything (buttons, board, etc)

        render_window.clear(sf::Color::White);

        // draw everything
        draw_all();

        render_window.display();

    }

    return 0;
} 

void Game_Window::show_leaderboard(){ 
    // have leaderboard pop up

}

void Game_Window::set_texture_manager(Texture_Manager &manager){
    texture_manager = &manager;
}


// =========== init functions ===========

void Game_Window::init_board(){
    // initialized stored board class
}

void Game_Window::init_window(){
    render_window.create(sf::VideoMode(_width, _height), "game", sf::Style::Close);
}

void Game_Window::init_variables(int rows, int cols, int mines, std::string username){
    _username = username;
    _cols = cols;
    _rows = rows;
    _mines = mines;
    _height = _rows*32 + 100;
    _width = _cols*32;
    paused = false;
}

void Game_Window::init_displays(){
    // initialize display elements (timer, number of mines left)
}

void Game_Window::init_buttons(){

    // happy face button (cols/2.0 *32) - 32, 32*(rows+0.5)
    happy_button.setTexture(texture_manager->getTexture("face_happy"));
    happy_button.setPosition((_cols/2.0 * 32)-32, 32*(_rows+0.5));

    // debug button
    debug_button.setTexture(texture_manager->getTexture("debug"));
    debug_button.setPosition((_cols*32)-304, 32*(_rows+0.5));

    // leaderboard_texture
    leaderboard_button.setTexture(texture_manager->getTexture("leaderboard"));
    leaderboard_button.setPosition(_cols*32-176,(_rows+0.5)*32);

    // pause play button
    pause_play_button.setTexture(texture_manager->getTexture("pause"));
    pause_play_button.setPosition(_cols*32-240, (_rows+0.5)*32);

}

// =========== draw functions ===========

void Game_Window::draw_all(){

    draw_buttons();
    draw_board();
    draw_displays();

}

void Game_Window::draw_buttons(){

    render_window.draw(happy_button);
    render_window.draw(counter);
    render_window.draw(debug_button);
    render_window.draw(pause_play_button);
    render_window.draw(leaderboard_button);

}
void Game_Window::draw_displays(){

}

void Game_Window::draw_board(){
    board.draw_tiles(render_window);
}

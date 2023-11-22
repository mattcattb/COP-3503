#include "Game_Window.h"


Game_Window::Game_Window(int cols, int rows, int mines, std::string username){

    // setup board!


    // initialize parts of display
    init_variables(cols, rows, mines, username);
    init_buttons();
    init_window();
    init_text();
    

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
        render_window.clear(sf::Color::White);

        // draw everything
        draw_all();

        render_window.display();

    }

} 

void Game_Window::show_leaderboard(){ 
    // have leaderboard pop up

}


// =========== init functions ===========

void Game_Window::init_fonts(){

}
void Game_Window::init_window(){
    render_window.create(sf::VideoMode(_width, _height), "game", sf::Style::Close);
}
void Game_Window::init_variables(int cols, int rows, int mines, std::string username){
    _username = username;
    _cols = cols;
    _rows = rows;
    _mines = mines;
    _height = _rows*32 + 100;
    _width = _cols*32;
    paused = false;
} 
void Game_Window::init_text(){

}
void Game_Window::init_buttons(){

}

// =========== draw functions ===========

void Game_Window::draw_all(){
    draw_fonts();
    draw_buttons();
    draw_text();

}
void Game_Window::draw_fonts(){

}
void Game_Window::draw_buttons(){

}
void Game_Window::draw_text(){

}
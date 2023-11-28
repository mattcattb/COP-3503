#include "Game_Window.h"


Game_Window::Game_Window(int rows, int cols, int mines, std::string username){

    // setup board!
    // initialize parts of display
    init_variables(rows, cols, mines, username);
    init_buttons();
    init_window();
    init_displays();
    std::cout << "init board\n";
    init_board();
    std::cout << "finished all\n";
    
}

Game_Window::~Game_Window(){
    delete board;
}

int Game_Window::event_loop(){

    // returns -1 to say the window is closed, 1 to say to switch to game view

    std::cout << "In game loop!\n";

    while (render_window.isOpen())
    {
        sf::Event event;
        
        while(render_window.pollEvent(event)){
            bool left_click;
            sf::Vector2i mouse_pos;

            switch (event.type)
            {
            
            case sf::Event::Closed:
                // window closed!
                render_window.close();
                
                return -1;

                break;
                            
            case sf::Event::MouseButtonPressed:
                
                // get mouse position of pressed mouse
                mouse_pos = sf::Mouse::getPosition(render_window);
                
                std::cout << mouse_pos.x << " " << mouse_pos.y << std::endl;

                // get if left or right click
                left_click = (event.mouseButton.button == sf::Mouse::Left);

                // if tile clicked, update board
                if (tile_clicked(mouse_pos)){
                    board->update_board(mouse_pos, left_click);
                }

                break;

            default:
                break;
            }
        }

        update_all();

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

// =========== init functions ===========

void Game_Window::init_board(){
    // initialized stored board class
    board = new Board(_rows, _cols, _mines, *texture_manager);
    std::cout << "CREATED BOARD!\n";
    
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

// =========== update functions =========

void Game_Window::update_all(){

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
    board->draw_tiles(render_window);
}


// ======== helpers ==========

bool Game_Window::tile_clicked(sf::Vector2i mouse_pos){
    int x = mouse_pos.x;
    int y = mouse_pos.y;

    if (x <= _cols*32 && y <= _rows*32){
        return true;
    }else{
        return false;
    }    

}
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
                    // only update board if not paused
                    if (!paused){
                        board->update_board(mouse_pos, left_click);
                    }

                }else if (pause_button_clicked(mouse_pos)){
                    update_pause_button();
                    
                }else if(leaderboard_button_clicked(mouse_pos)){
                    update_pause_button();

                }else if(debug_button_clicked(mouse_pos)){
                    update_debug_button();

                }

                break;

            default:
                break;
            }
        }

        // see if game won!

        // if mine pressed (loss state) reveal all tiles with mines + end game

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

void Game_Window::update_pause_button(){
    // toggle pause state
    paused = !paused;

    // change pause sprite
    if (paused){
        pause_play_button.setTexture(texture_manager->getTexture("pause"));
    }else{
        pause_play_button.setTexture(texture_manager->getTexture("play"));
    }
}

void Game_Window::update_leaderboard(){
    // pause game
    
    // reveal all tiles 
    
    // display leaderboard window

    // when leaderboard window closed, all tiles go to pevious state, resume timer

}

void Game_Window::update_debug_button(){
    // toggle debug state, either showing all mines or hiding all mines
    debugging = !debugging;

    if (debugging){
        // show all mines
        board->reveal_mines();
    }else{
        // hide all mines
        board->hide_mines();
    }

    // button should not work when game ends (victory/loss)
}

void Game_Window::update_happy_face_button(){

    // happyface button was clicked!
    // restart and re-randomize board
    board->reset_board(); 
    
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

    if (mouse_pos.x <= _cols*32 && mouse_pos.y <= _rows*32){
        return true;
    }else{
        return false;
    }    

}

bool Game_Window::pause_button_clicked(sf::Vector2i mouse_pos){
    sf::FloatRect pause_bounds = pause_play_button.getLocalBounds();
    float spriteWidth = pause_bounds.width; // x
    float spriteHeight = pause_bounds.height; // y 
    sf::Vector2f sprite_pos = pause_play_button.getPosition(); // top left 
    if (mouse_pos.x >= sprite_pos.x && mouse_pos.x <= (sprite_pos.x + spriteWidth) 
        && mouse_pos.y >= sprite_pos.y && mouse_pos.y <= (sprite_pos.y + spriteHeight)){
        return true;
    }else{
        return false;
    }
}

bool Game_Window::leaderboard_button_clicked(sf::Vector2i mouse_pos){
    sf::FloatRect leaderboard_bounds = leaderboard_button.getLocalBounds();
    float spriteWidth = leaderboard_bounds.width; // x
    float spriteHeight = leaderboard_bounds.height; // y 
    sf::Vector2f sprite_pos = pause_play_button.getPosition(); // top left 
    if (mouse_pos.x >= sprite_pos.x && mouse_pos.x <= (sprite_pos.x + spriteWidth) 
        && mouse_pos.y >= sprite_pos.y && mouse_pos.y <= (sprite_pos.y + spriteHeight)){
        return true;
    }else{
        return false;
    }
}

bool Game_Window::debug_button_clicked(sf::Vector2i mouse_pos){
    sf::FloatRect debug_bounds = debug_button.getLocalBounds();
    float spriteWidth = debug_bounds.width; // x
    float spriteHeight = debug_bounds.height; // y 
    sf::Vector2f sprite_pos = pause_play_button.getPosition(); // top left 
    if (mouse_pos.x >= sprite_pos.x && mouse_pos.x <= (sprite_pos.x + spriteWidth) 
        && mouse_pos.y >= sprite_pos.y && mouse_pos.y <= (sprite_pos.y + spriteHeight)){
        return true;
    }else{
        return false;
    }
}

bool Game_Window::happy_face_button_clicked(sf::Vector2i mouse_pos){
    sf::FloatRect debug_bounds = happy_button.getLocalBounds();
    float spriteWidth = debug_bounds.width; // x
    float spriteHeight = debug_bounds.height; // y 
    sf::Vector2f sprite_pos = pause_play_button.getPosition(); // top left 
    if (mouse_pos.x >= sprite_pos.x && mouse_pos.x <= (sprite_pos.x + spriteWidth) 
        && mouse_pos.y >= sprite_pos.y && mouse_pos.y <= (sprite_pos.y + spriteHeight)){
        return true;
    }else{
        return false;
    }
}

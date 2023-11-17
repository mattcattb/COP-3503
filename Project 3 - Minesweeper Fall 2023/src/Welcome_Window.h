#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

class Welcome_Window{

    int height, width;
    int cols, rows;

    
    sf::RenderWindow render_window;

    void parse_size();

public:

    Welcome_Window();
    void event_loop();

};

void Welcome_Window::event_loop(){
    
}


Welcome_Window::Welcome_Window(){
    parse_size();
    height = rows*32 + 100;
    width = cols*32;

    render_window.create(sf::VideoMode(height, width));

}

void Welcome_Window::parse_size(){
    std::ifstream config_fin("files/board_config.cfg");
    std::string buffer;
    
    config_fin >> buffer;
    cols = stoi(buffer);
    
    config_fin >> buffer; 
    rows = stoi(buffer);

    config_fin.close();
}

void setText(sf::Text &text, float x, float y){
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                    textRect.top+textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x,y));
}
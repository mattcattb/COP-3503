#include "Leaderboard_Window.h"

// ====== Initialization ======

Leaderboard_Window::Leaderboard_Window(int r, int c){
    
    _leaderboard_filename = "files/leaderboard.txt";
    _rows = r;
    _cols = c;

    init_fonts();
    init_window();
    init_leaderboard_scores();
    init_text();
}

void Leaderboard_Window::init_fonts(){
    if (! _text_font.loadFromFile("files/font.ttf")){
        std::cout << "error loading font\n";
    }
}

void Leaderboard_Window::init_window(){
    render_window.create(sf::VideoMode((_rows*16)+50,_cols*16), "leaderboard", sf::Style::Close);
}

void Leaderboard_Window::init_leaderboard_scores(){
    // scan in scores vector from leaderboard.txt
    // min:sec, user_name
    
}

void Leaderboard_Window::init_text(){
    // sets up text!

    // set leaderboard title
    int windowWidth = render_window.getSize().x;
    int windowHeight = render_window.getSize().y;
    sf::Vector2f title_pos(windowWidth/2, (windowHeight/2) - 120);
    setup_text(_title, "LEADERBOARD", _text_font, true, true, sf::Color::White, 20, title_pos);

    // TODO init leaderboard contents
    // get a string top 5 scores in leaderboard(seperated by \n\n), then draw?


}

// ===== Display Loops =====

void Leaderboard_Window::display_leaderboard(){
    while (render_window.isOpen()){
        // draw board, and then poll event
        sf::Event event;

        while(render_window.pollEvent(event)){
            switch (event.type)
            {

            case sf::Event::Closed:
                // close window but first write leaderboard contents to leaderboard.txt
                write_leaderboard();
                render_window.close();
                
                return;

            default:
                break;
            }
        }

        // clear all 
        render_window.clear(sf::Color::Blue);

        // draw and display all!
        draw_all();

        // display all!
        render_window.display();
    }

    return;

}

// ====== Drawing ======

void Leaderboard_Window::draw_all(){
    render_window.draw(_title);
    render_window.draw(_leaderboard_text);
}

// ====== Helpers ======

void Leaderboard_Window::setup_text(sf::Text &text, std::string message, sf::Font &font, bool bold, bool underlined, sf::Color color, int size, sf::Vector2f position){
    // helper for quickly setting up text

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString(message);

    // set the character size
    text.setCharacterSize(size); // in pixels, not points!

    // set the color
    text.setFillColor(color);

    // set bold or underlined if needed
    if (bold){text.setStyle(sf::Text::Bold);};
    if (underlined){text.setStyle(sf::Text::Underlined);};

    // move position
    setTextPos(text, position.x, position.y);

}

void Leaderboard_Window::setTextPos(sf::Text &text, float x, float y){
    // set the text position of text
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                    textRect.top+textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x,y));
}


void Leaderboard_Window::read_leaderboard(){
    // read in from csv leaderboard.txt
}

void Leaderboard_Window::write_leaderboard(){

}

void Leaderboard_Window::add_score(std::string name, int min, int sec){
    // adds user to leaderboard (make sure theyre marked as new)

    Score new_score(name, min, sec, true);

    // add new_score to leaderboard vector 
}


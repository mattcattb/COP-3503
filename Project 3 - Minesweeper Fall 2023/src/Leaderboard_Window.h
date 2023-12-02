#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>


struct Score{

    std::string name;
    int min;
    int sec;
    bool new_score;

    Score(std::string n, int m, int s, bool ns = false){
        name = n;
        min = m;
        sec = s;

        // store if value was added from game (use to add star)
        new_score = ns;
    }
};

class Leaderboard_Window{

    // Variables
    std::string _leaderboard_filename;
    std::vector<Score> _scores_leaderboard;

    int _rows;
    int _cols;

    // SFML Variables
    sf::Font _text_font;
    sf::Text _title;
    sf::Text _leaderboard_text;
    sf::RenderWindow render_window;

    // init welcome window objects
    void init_fonts();
    void init_window();
    void init_leaderboard_scores();
    void init_text();

    // drawing
    void draw_all();
    void draw_leaderboard();

    // helpers
    void setup_text(sf::Text &text, std::string message, sf::Font &font, bool bold, bool underlined, sf::Color color, int size, sf::Vector2f position);
    void setTextPos(sf::Text &text, float x, float y);

    // Read and Write
    void read_leaderboard();
    void write_leaderboard();

public:


    Leaderboard_Window(int r, int c);
    void display_leaderboard();

    void add_score(std::string name, int min, int sec); // adds user to leaderboard

};


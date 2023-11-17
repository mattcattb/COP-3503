#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <map>
#include <vector>

sf::RenderWindow * create_windows(int cols, int rows);
void read_config(int &cols, int &rows, int &mines);

int main(int argc, char ** argv){

    int cols, rows, mines;
    read_config(cols, rows, mines); // read in config info from file 

    sf::RenderWindow *windows_array = create_windows(cols, rows);
    sf::Event event;

    int state = 0; // states are welcome, game, leaderboard

    while (windows_array[state].isOpen()){
         

        while(windows_array[state].pollEvent(event)){
            

        }
    }

    windows_map.at("welcome");


}

sf::RenderWindow * create_windows(int cols, int rows){
    // create a map of all 3 windows

    sf::RenderWindow *windows_arr = new sf::RenderWindow[3];

    windows_arr[0].create(sf::VideoMode(rows*32 + 100, cols*32), "welcome", sf::Style::Close);
    windows_arr[1].create(sf::VideoMode(rows*32 + 100, cols*32), "game", sf::Style::Close);
    windows_arr[2].create(sf::VideoMode(rows*16 + 50, cols*16), "leaderboard", sf::Style::Close);

    return windows_arr;
}  

void read_config(int &cols, int &rows, int &mines){
    
    std::ifstream config_fin("files/board_config.cfg");
    std::string buffer;
    
    config_fin >> buffer;
    cols = stoi(buffer);
    
    config_fin >> buffer; 
    rows = stoi(buffer);

    config_fin >> buffer;
    mines = stoi(buffer);

}
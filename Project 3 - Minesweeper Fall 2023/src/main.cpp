#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>



int main(int argc, char ** argv){

    sf::RenderWindow window(sf::VideoMode(800,600), "SFML window", sf::Style::Close);

    int cols, rows, mines;
    read_config(cols, rows, mines); // read in config info from file 

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
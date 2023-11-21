#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>

#include "Welcome_Window.h"

void read_config(int &cols, int &rows, int &mines);

int main(int argc, char ** argv){

    int cols, rows, mines;
    read_config(cols, rows, mines); // read in config info from file 

    Welcome_Window welcome_window(cols, rows);

    int state = 0;

    while(state == 0){
        state = welcome_window.event_loop();
    }

    return 0;
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


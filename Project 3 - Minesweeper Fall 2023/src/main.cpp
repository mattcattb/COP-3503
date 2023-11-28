#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Welcome_Window.h"
#include "Game_Window.h"
#include "Texture_Manager.h"

void read_config(int &cols, int &rows, int &mines);

int main(int argc, char ** argv){

    int cols, rows, mines;
    read_config(rows, cols, mines); // read in config info from file 

    int state = 0;
    std::string username; // username of this character

    Welcome_Window welcome_window(rows, cols);

    // welcome window
    state = welcome_window.event_loop(); 

    if (state == -1){
        // immediatly end program
        return 0;
    }
    
    // go into game part now
    username = welcome_window.get_character_name();
 
    Game_Window game_window(rows, cols, mines, username);

    state = game_window.event_loop();


    // game loop
    return 0;
}


void read_config(int &rows, int &cols, int &mines){
    
    std::ifstream config_fin("files/board_config.cfg");
    std::string buffer;
    
    config_fin >> buffer;
    cols = stoi(buffer);
    
    config_fin >> buffer; 
    rows = stoi(buffer);

    config_fin >> buffer;
    mines = stoi(buffer);

}


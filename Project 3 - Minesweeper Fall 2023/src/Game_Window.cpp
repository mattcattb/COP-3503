#include "Game_Window.h"


    Game_Window(int cols, int rows, int mines);
    int event_loop(); // returns -1 to say the window is closed, 1 to say to switch to game view

    void show_leaderboard(); // have leaderboard pop up
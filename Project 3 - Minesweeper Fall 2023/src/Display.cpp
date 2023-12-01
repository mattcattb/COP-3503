#include "Display.h"

Display::Display(int digits, int x, int y, sf::Texture * digits_texture){
    
    
    std::cout << "Constructing a display!\n";

    display_size = digits;
    left_x = x;
    left_y = y;

    // dynamic array of sprite pointers
    display_array = new sf::Sprite[digits];

    for(int i = 0; i < display_size; i += 1){
        // i is the digits place (2,1,0)
        display_array[i] = sf::Sprite(*digits_texture);
        // set position of sprite (i=0 is right most)
        int cur_x = x + (display_size - 1 - i)*21;
        std::cout << "cur_x of sprite i:" << i << " is " << cur_x << std::endl;
        display_array[i].setPosition(cur_x, y);
        // set digit to 0 
        set_digit(display_array[i], 0); 
    }

    // all digits are initialized to 0
}

void Display::set_digit(sf::Sprite &digit, int num){
    // offsets texture based on the num making it show the proper digit
    
    int Lx = 21*num; // left x value
    
    if (num == -1){
        // make negative symbol (last "digit")
        Lx = 21 * 10;
    }

    digit.setTextureRect(sf::IntRect(Lx, 0, 21, 32));
}

void Display::set_display(int val){
    // set counter to number (remember LSD is index 0)
    
    std::cout << "Setting display to " << val << std::endl; 

    if (val < 0){
        // negative number! set sprite [size-1] to -1
        set_digit(display_array[display_size - 1], -1);
        val = val*(-1);
    }else {
        // number is positive, make MSD 0
        set_digit(display_array[display_size - 1], 0);
    }
    
    int i = 0;
    while(i < display_size - 1 ){
        std::cout << "i:" << i << " to digit" << val%10 << std::endl; 
        set_digit(display_array[i], val%10);
        val = val/10;
        i += 1;
    }
}

void Display::draw(sf::RenderWindow &window){
    // draw each digit in window
    for(int i = 0; i < display_size; i += 1){
        window.draw(display_array[i]);
    }

} 

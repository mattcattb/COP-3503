#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include "Image.h"

using namespace std;

const string method_names[] = {"multiply", "subtract", "overlay", "screen", "combine", "flip", "onlyred", "onlygreen", "onlyblue", "addred", "addgreen", "addblue", "scalered", "scalegreen", "scaleblue"};

const int args[] = {1, 1, 1, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1}; // number of arguments used not including method name itself

Image multiply(Image top, Image bottom);
Image subtract(Image top, Image bottom);
Image overlay(Image top, Image bottom);
Image screen(Image top, Image bottom);
Image combine(Image top, Image red, Image green, Image blue);
Image flip(Image top);

Image onlyred(Image top);
Image onlyblue(Image top);
Image onlygreen(Image top);

Image addred(Image top, int val);
Image addgreen(Image top, int val);
Image addblue(Image top, int val);

Image scalered(Image top, int scale);
Image scalegreen(Image top, int scale);
Image scaleblue(Image top, int scale);

void display_help_message();

bool is_tga(string filename);
bool file_exists(string filename);
int method_type(string method_name);

//! move this outside of src directory!
int main(int argc, char** argv) {

    if (argv[0] == "--help" || argc == 0){
        // print help message if argv[0] is --help or there are no arguements provided
        display_help_message();
    }

    // check if argv[0] is tga filename

    string output_file = argv[0];

    if (is_tga(output_file) == false){
        // stop if tga is not a file
        cout << "Invalid file name."<< endl;
        
    }

    string source_file = argv[1];
    
    if(is_tga(source_file) == false){
        cout << "Invalid file name." << endl;
    
    } else if(file_exists(source_file) == false){
        cout << "File does not exist." << endl;
    }  

    Image tracking(source_file);

    int i = 2; // start at 2 for output_file and source_file

    while (i < argc){
        string cur_method = argv[i]; // current method


        // after everything done, incriment according to which method used
    }

    return 0;
}

void display_help_message(){
    // display all commands and usage for script
    cout << "Project 2: Image Processing, Fall 2023\n\n";
    cout << "Usage:\n";
    cout << "\t./project2.out [output] [firstImage] [method] [...]";

}

bool is_tga(string filename){
    // determines if filename ends in .tga
}

bool file_exists(string filename){
    // determines if filename is real file
}

int method_type(string method_name){
    // return number corresponding to method ID, or -1 if method_name is not valid method
    for (int i = 0; i < method_names->size(); i += 1){
        if (method_names[i] == method_name){
            return i;
        }
    }
    return -1;
}

Image multiply(Image top, Image bottom){
    return (top * bottom);
}

Image subtract(Image top, Image bottom){
    return (top - bottom);
}

Image overlay(Image top, Image bottom){
    return (top.overlay(bottom));
}

Image screen(Image top, Image bottom){
    return (top.screen(bottom));
}

Image combine(Image top, Image green, Image blue){
    Image entwined(top,green,blue);
    return entwined;
}

Image flip(Image top){
    return top.rotate_180();
}


Image onlyred(Image top){
    return top.get_red_channel();
}

Image onlyblue(Image top){
    return top.get_blue_channel();
}

Image onlygreen(Image top){
    return top.get_green_channel();
}


Image addred(Image top, int val){
    Pixel addpix(val,0,0);
    return (top + addpix);
}

Image addgreen(Image top, int val){
    Pixel addpix(0, val, 0);
    return (top + addpix);
}

Image addblue(Image top, int val){
    Pixel addpix(0, 0, val);
    return (top + addpix);
}


Image scalered(Image top, int scale){
    float scale_arr[] = {(float)scale,1,1}; // scale red by 4, green by 1 (none), blue by 0
    return (top*scale_arr);

}

Image scalegreen(Image top, int scale){
    const float scale_arr[] = {1.0, (float)scale, 1.0}; // scale red by 4, green by 1 (none), blue by 0
    return (top*scale_arr);

}

Image scaleblue(Image top, int scale){
    float scale_arr[] = {1, 1, (float)scale}; // scale red by 4, green by 1 (none), blue by 0
    return (top * scale_arr);
}


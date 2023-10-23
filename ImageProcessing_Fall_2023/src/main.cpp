#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include "Image.h"

using namespace std;

const string method_names[] = {"multiply", "subtract", "overlay", "screen", "combine", "flip", "onlyred", "onlygreen", "onlyblue", "addred", "addgreen", "addblue", "scalered", "scalegreen", "scaleblue"};

const int num_args_method[] = {1, 1, 1, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1}; // number of arguments used not including method name itself

Image multiply(Image top, string * args);
Image subtract(Image top, string * args);
Image overlay(Image top, string * args);
Image screen(Image top, string * args);
Image combine(Image top, string * args);
Image flip(Image top, string * args);

Image onlyred(Image top, string * args);
Image onlyblue(Image top, string * args);
Image onlygreen(Image top, string * args);

Image addred(Image top, string * args);
Image addgreen(Image top, string * args);
Image addblue(Image top, string * args);

Image scalered(Image top, string * args);
Image scalegreen(Image top, string * args);
Image scaleblue(Image top, string * args);

void display_help_message();

bool is_tga(string filename);
bool file_exists(string filename);
int get_method_id(string method_name);

void function_multiplexer(int method_id, string * args, Image &tracking);
string * parse_args(int method_id, int index, char** argv);

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
        return 0;
    }

    string source_file = argv[1];
    
    if(is_tga(source_file) == false){
        cout << "Invalid file name." << endl;
        return 0;
    
    } else if(file_exists(source_file) == false){
        cout << "File does not exist." << endl;
        return 0;
    }  

    Image tracking_img(source_file);
    tracking_img.read();

    int i = 2; // start at 2 for output_file and source_file

    while (i < argc){
        string cur_method = argv[i]; // current method
        int method_id = get_method_id(cur_method);
        int num_args = num_args_method[method_id];
        
        if (method_id == -1){
            //! wrong method ID!!!
            cout << "Wrong method ID" << endl;
            
        }        

        // get string of args for the function 
        string *method_args = parse_args(method_id, i, argv);

        // apply that function and arguement to the function multiplexer!
        function_multiplexer(method_id, method_args, tracking_img);

        // after everything done, incriment according to which method used
        i += (1 + num_args);
    }

    tracking_img.write(output_file);

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
    int len = filename.length();

    string filetype = filename.substr(len-5, 4);
    if (filetype != ".tga"){
        return false;
    }
    return true;
    
}

bool file_exists(string filename){
    // determines if filename is real file
    
    ifstream stream = ifstream(filename, ios_base::binary);
    bool exists = stream.is_open();
    stream.close();
    return exists;
}

int get_method_id(string method_name){
    // return number corresponding to method ID, or -1 if method_name is not valid method
    for (int i = 0; i < method_names->size(); i += 1){
        if (method_names[i] == method_name){
            return i;
        }
    }
    return -1;
}

void function_multiplexer(int method_id, string * args, Image &tracking){
    // using string of args and tracking image, apply specific function and change track_img

    Image new_img;

    if (method_id == 0) {
        // multiply 
        string bottom_fname = args[0];
        Image bottom(bottom_fname);
        bottom.write();
        new_img = multiply(tracking, bottom);
    } else if (method_id == 1) {
        // subtract
        string bottom_fname = args[0];
        Image bottom(bottom_fname);
        bottom.write();
        new_img = subtract(tracking, bottom);
    } else if (method_id == 2) {
        // overlay
        string bottom_fname = args[0];
        Image bottom(bottom_fname);
        bottom.write();
        new_img = overlay(tracking, bottom);
    } else if (method_id == 3) {
        // screen
        string bottom_fname = args[0];
        Image bottom(bottom_fname);
        bottom.write();
        new_img = screen(tracking, bottom);
    } else if (method_id == 4) {
        // combine
        string green_fname = args[0];
        string blue_fname = args[1];
        Image green(green_fname);
        Image blue(blue_fname);
        green.write();
        blue.write();
        new_img = combine(tracking, green, blue);
    } else if (method_id == 5) {
        // flip
        new_img = flip(tracking);
    } else if (method_id == 6) {
        // onlyred
        new_img = onlyred(tracking);
    } else if (method_id == 7) {
        // onlygreen
        new_img = onlygreen(tracking);
    } else if (method_id == 8) {
        // onlyblue
        new_img = onlyblue(tracking);
    } else if (method_id == 9) {
        // addred
        int val = stoi(args[0]);
        new_img = addred(tracking, val);
    } else if (method_id == 10) {
        // addgreen
        int val = stoi(args[0]);
        new_img = addgreen(tracking, val);
    } else if (method_id == 11) {
        // addblue
        int val = stoi(args[0]);
        new_img = addblue(tracking, val);
    } else if (method_id == 12) {
        // scalered
        int scale = stoi(args[0]);
        new_img = scalered(tracking, scale);
    } else if (method_id == 13) {
        // scalegreen
        int scale = stoi(args[0]);
        new_img = scalegreen(tracking, scale);
    } else if (method_id == 14) {
        // scaleblue
        int scale = stoi(args[0]);
        new_img = scaleblue(tracking, scale);
    } else {
        // Default case
    }
    
    tracking.pixelVec = new_img.pixelVec;

}

string * parse_args(int method_id, int index, char** argv){
    // return a string of the arguements to a specfic arg to be parsed
    // index: index currently on (function itself)
    int num_args = num_args_method[method_id];

    string arguements[num_args];

    for (int i = 0; i < num_args; i += 1){
        arguements[i] = argv[index + i + 1];
    }

    return arguements;
}

//!!!!! CHANGE EACH OF THESE FUNCTIONS TO TAKE A STRING* OF ARGS!!!

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


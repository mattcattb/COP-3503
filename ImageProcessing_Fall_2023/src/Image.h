#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//(1) Declare a Header struct
struct Header {

    //(2) Declare each Header element
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;

    void print();
};

//(3) Declare a Pixel struct
struct Pixel {
    //(4) Declare each Pixel element
    unsigned char blue;
    unsigned char green;
    unsigned char red;

    Pixel();
    Pixel(unsigned char r, unsigned char g, unsigned char b);

};



//(5) Declare an Image class
class Image {
    //(6) Declare private data member of the Image class

private:
    //(7) Declare a name
    string name;
    //(8) Declare a stream (ifstream)
    ifstream stream;

public:
    //(9) Declare a header for the Image
    Header header;

    //(10) Declare a vector of pixels
    vector<Pixel> pixelVec;

    //(11) Declare an Image constructor
    Image();
    Image(const string& name);
    // construct image using 3 images, one for each color channel
    Image(Image &img_r, Image &img_g, Image &img_b); 

    //(12) Declare a read function
    void read();
    void read(const string& new_name);

    //(13) Declare a write function
    void write();
    void write(const string& new_name);
    
    void print(); // print to terminal info on picture

    // multiply blend top*bottom layer
    Image operator*(const Image &img_b); 
    Image operator*(const Pixel &pix);
    Image operator*(const float arr[3]);
    
    // screen blend
    Image screen(const Image &img_b);

    // subtract blend
    Image operator-(const Image &img_b);

    // add blend
    Image operator+(const Image &img_b);
    Image operator+(const Pixel &pix);

    // overlay blend
    Image overlay(const Image &img_b);

    Image rotate_180();

    Image get_red_channel();
    Image get_green_channel();
    Image get_blue_channel();

};


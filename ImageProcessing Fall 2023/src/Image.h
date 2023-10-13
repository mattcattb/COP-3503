#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "functions.h"

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

    //(12) Declare a read function
    void read();
    void read(const string& name);

    //(13) Declare a write function
    void write();
    void write(const string& name);
    
    // multiply blend
    Image operator*(const Image &img_b); 

    // screen blend
    Image screen(const Image &img_b);

    // subtract blend
    Image operator-(const Image &img_b);

    // add blend
    Image operator+(const Image &img_b);

    // overlay blend
    Image overlay(const Image &img_b);
};


#include "Image.h"

using namespace std;

Image::Image(const string& name) {
    this->name = name;
}

Image::Image(){
    this->name = "unnamed";
}

void Image::read() {
    //(14) Read in the .tga file
    this->stream = ifstream(this->name, ios_base::binary);

    //(15) Check if the file is opening
    if (!stream.is_open()) {
        throw runtime_error("Could not open file.");
    }

    //(16) Read in each element of the .tga file
    stream.read(&header.idLength, sizeof(header.idLength));
    stream.read(&header.colorMapType, sizeof(header.colorMapType));
    stream.read((char*)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
    stream.read((char*)&header.colorMapLength, sizeof(header.colorMapLength));
    stream.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
    stream.read((char*)&header.xOrigin, sizeof(header.xOrigin));
    stream.read((char*)&header.yOrigin, sizeof(header.yOrigin));
    stream.read((char*)&header.width, sizeof(header.width));
    stream.read((char*)&header.height, sizeof(header.height));
    stream.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    stream.read(&header.imageDescriptor, sizeof(header.imageDescriptor));

    //(17) Get the image size by multiplying the image height and width
    int imageSize = (int)(header.height * header.width);

    //(18) Create a for loop to read in all the pixels
    for (int i = 0; i < imageSize; i++) {
        Pixel pixel;

        stream.read((char*)&pixel.blue, sizeof(pixel.blue));
        stream.read((char*)&pixel.green, sizeof(pixel.green));
        stream.read((char*)&pixel.red, sizeof(pixel.red));

        //(21) Push in each pixel to the pixel vector

        pixelVec.push_back(pixel);
    }
}

void Image::read(const string& name){
    //(14) Read in the .tga file
    ifstream stream = ifstream(name, ios_base::binary);

    //(15) Check if the file is opening
    if (!stream.is_open()) {
        throw runtime_error("Could not open file.");
    }

    //(16) Read in each element of the .tga file
    stream.read(&header.idLength, sizeof(header.idLength));
    stream.read(&header.colorMapType, sizeof(header.colorMapType));
    stream.read((char*)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
    stream.read((char*)&header.colorMapLength, sizeof(header.colorMapLength));
    stream.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
    stream.read((char*)&header.xOrigin, sizeof(header.xOrigin));
    stream.read((char*)&header.yOrigin, sizeof(header.yOrigin));
    stream.read((char*)&header.width, sizeof(header.width));
    stream.read((char*)&header.height, sizeof(header.height));
    stream.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    stream.read(&header.imageDescriptor, sizeof(header.imageDescriptor));

    //(17) Get the image size by multiplying the image height and width
    int imageSize = (int)(header.height * header.width);

    //(18) Create a for loop to read in all the pixels
    for (int i = 0; i < imageSize; i++) {
        Pixel pixel;

        stream.read((char*)&pixel.blue, sizeof(pixel.blue));
        stream.read((char*)&pixel.green, sizeof(pixel.green));
        stream.read((char*)&pixel.red, sizeof(pixel.red));

        //(21) Push in each pixel to the pixel vector

        pixelVec.push_back(pixel);
    }
}

void Image::write() {
    //(22) Create a .tga file
    ofstream stream("output/out.tga", ios_base::binary);


    stream.write(&header.idLength, sizeof(header.idLength));
    stream.write(&header.colorMapType, sizeof(header.colorMapType));
    stream.write((char*)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
    stream.write((char*)&header.colorMapLength, sizeof(header.colorMapLength));
    stream.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
    stream.write((char*)&header.xOrigin, sizeof(header.xOrigin));
    stream.write((char*)&header.yOrigin, sizeof(header.yOrigin));
    stream.write((char*)&header.width, sizeof(header.width));
    stream.write((char*)&header.height, sizeof(header.height));
    stream.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    stream.write(&header.imageDescriptor, sizeof(header.imageDescriptor));

    //(24) Create a for loop to write out each pixel
    for (int i = 0; i < pixelVec.size(); i++) {
        Pixel pixel = pixelVec[i];
        stream.write((char*)&pixel.blue, sizeof(char));
        stream.write((char*)&pixel.green, sizeof(char));
        stream.write((char*)&pixel.red, sizeof(char));
    }
}

void Image::write(const string& name){
    ofstream stream(name, ios_base::binary);

    stream.write(&header.idLength, sizeof(header.idLength));
    stream.write(&header.colorMapType, sizeof(header.colorMapType));
    stream.write((char*)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
    stream.write((char*)&header.colorMapLength, sizeof(header.colorMapLength));
    stream.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
    stream.write((char*)&header.xOrigin, sizeof(header.xOrigin));
    stream.write((char*)&header.yOrigin, sizeof(header.yOrigin));
    stream.write((char*)&header.width, sizeof(header.width));
    stream.write((char*)&header.height, sizeof(header.height));
    stream.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    stream.write(&header.imageDescriptor, sizeof(header.imageDescriptor));

    //(24) Create a for loop to write out each pixel
    for (int i = 0; i < pixelVec.size(); i++) {
        Pixel pixel = pixelVec[i];
        stream.write((char*)&pixel.blue, sizeof(char));
        stream.write((char*)&pixel.green, sizeof(char));
        stream.write((char*)&pixel.red, sizeof(char));
    }
}

Image Image::operator*(const Image &img_2){
    // NP1 * NP2 to each place 
    
    // assumes both images have same height and width
    Image new_img;
    // set new image to the header 
    new_img.header = this->header;

    int i = 0;
    while (i < this->pixelVec.size()){
        // multiple ith pixel with other ith pixel
        Pixel p1 = this->pixelVec[i];
        Pixel p2 = img_2.pixelVec[i];

        // norm multiply pixel
        unsigned char blue = channel_mult(p1.blue, p2.blue); 
        unsigned char green = channel_mult(p1.green, p2.green);
        unsigned char red = channel_mult(p1.red, p2.red);

        Pixel new_pix(red, blue, green);
        new_img.pixelVec.push_back(new_pix);
        i += 1;
    }

    return new_img;
}

Image Image::screen(const Image &img_2){
    // 1 - [(1-NP1)*(1-NP2)]
    // assumes both images have same height and width
    Image new_img;
    // set new image to the header 
    new_img.header = this->header;

    int i = 0;
    while (i < this->pixelVec.size()){
        // multiple ith pixel with other ith pixel
        Pixel p1 = this->pixelVec[i];
        Pixel p2 = img_2.pixelVec[i];

        // norm multiply pixel
        unsigned char blue = channel_mult(p1.blue, p2.blue); 
        unsigned char green = channel_mult(p1.green, p2.green);
        unsigned char red = channel_mult(p1.red, p2.red);

        Pixel new_pix(red, blue, green);
        new_img.pixelVec.push_back(new_pix);
        i += 1;
    }

    return new_img;

}

unsigned char channel_screen(unsigned char ch1, unsigned char ch2){
    
}

Image Image::operator-(const Image &img_2){
    // P1-P2
    // assumes both images have same height and width
    Image new_img;
    // set new image to the header 
    new_img.header = this->header;

    int i = 0;
    while (i < this->pixelVec.size()){
        // multiple ith pixel with other ith pixel
        Pixel p1 = this->pixelVec[i];
        Pixel p2 = img_2.pixelVec[i];

        // norm multiply pixel
        unsigned char blue = channel_sub(p1.blue, p2.blue); 
        unsigned char green = channel_sub(p1.green, p2.green);
        unsigned char red = channel_sub(p1.red, p2.red);

        Pixel new_pix(red, blue, green);
        new_img.pixelVec.push_back(new_pix);
        i += 1;
    }

    return new_img;

}

Image Image::operator+(const Image &img_2){
    // P1 + P2
    // assumes both images have same height and width
    Image new_img;
    // set new image to the header 
    new_img.header = this->header;

    int i = 0;
    while (i < this->pixelVec.size()){
        // multiple ith pixel with other ith pixel
        Pixel p1 = this->pixelVec[i];
        Pixel p2 = img_2.pixelVec[i];

        // norm multiply pixel
        unsigned char blue = channel_add(p1.blue, p2.blue); 
        unsigned char green = channel_add(p1.green, p2.green);
        unsigned char red = channel_add(p1.red, p2.red);

        Pixel new_pix(red, blue, green);
        new_img.pixelVec.push_back(new_pix);
        i += 1;
    }

    return new_img;    
}

Image Image::overlay(const Image &img_2){
    // if NP2 <= 0.5: 2*NP1*NP2
    // NP2 > 0.5: 1 - [2*(1-NP1)*(1-NP2)]

}


Pixel::Pixel(){
    // set everything to 0 white
    red = 0;
    green = 0;
    blue = 0;
}

Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b){
    red = r;
    green = g;
    blue = b; 
}



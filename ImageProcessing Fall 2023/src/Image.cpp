#include "Image.h"

using namespace std;

// for general programs that any class can use

unsigned char channel_add(unsigned char ch_1, unsigned char ch_2);
unsigned char channel_screen(unsigned char ch_1, unsigned char ch_2);
unsigned char channel_sub(unsigned char ch_1, unsigned char ch_2);
unsigned char channel_mult(unsigned char ch_1, unsigned char ch_2);
unsigned char channel_overlay(unsigned char ch_1, unsigned char ch_2);

Image::Image(){
    this->name = "unnamed";
}

Image::Image(const string& name) {
    this->name = name;
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

void Image::read(const string& new_name){
    //(14) Read in the .tga file
    ifstream stream = ifstream(new_name, ios_base::binary);

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
    ofstream stream(this->name, ios_base::binary);

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

void Image::write(const string& new_name){
    ofstream stream(new_name, ios_base::binary);

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
        unsigned char blue = channel_overlay(p1.blue, p2.blue); 
        unsigned char green = channel_overlay(p1.green, p2.green);
        unsigned char red = channel_overlay(p1.red, p2.red);

        Pixel new_pix(red, blue, green);
        new_img.pixelVec.push_back(new_pix);
        i += 1;
    }

    return new_img; 

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


unsigned char one_sub(unsigned char ch_1);
float norm(unsigned char ch);

unsigned char channel_add(unsigned char ch_1, unsigned char ch_2){
    // ch_1 + ch_2 with clamping
    int val = ((int)ch_1) + ((int)ch_2);
    if (val > 255){
        val = 255;
    }else if (val < 0){
        val = 0;
    }
    
    return ((unsigned char)val);

}

unsigned char channel_screen(unsigned char ch_1, unsigned char ch_2){
    // 1 - [(1-NP1)*(1-NP2)]

    float norm_c1 = norm(ch_1);
    unsigned char v1 = one_sub(norm_c1); // (1-NP1)
    
    float norm_c2 = norm(ch_2);
    unsigned char v2 = one_sub(norm_c2);
    unsigned char v3 = channel_mult(v1,v2);
    unsigned char return_val = one_sub(v3); 
    
    return return_val;
}

unsigned char channel_sub(unsigned char ch_1, unsigned char ch_2){
    // ch_1 - ch_2 with clamping
    int val = ((int)ch_1) + ((int)ch_2);
    if (val > 255){
        val = 255;
    }else if (val < 0){
        val = 0;
    }
    
    return ((unsigned char)val);
 
}

unsigned char one_sub(unsigned char ch_1){
    // 1 - Normed(ch_1)
    float norm_c1 = norm(ch_1);
    float val = 1.0 - norm_c1;
    unsigned char return_val = val*255 + 0.5f;
    return return_val;
}

float norm(unsigned char ch){
    float val_1 = ((float)ch)/255; 
    return val_1;
}

unsigned char channel_mult(unsigned char ch_1, unsigned char ch_2){
    // multiply 2 channels by normalization
    float val_1 = norm(ch_1);
    float val_2 = norm(ch_2);

    float val_3 = val_1 * val_2;
    int ch_3 = val_3*255 + 0.5f;

    return ((unsigned char)ch_3);
}

unsigned char channel_overlay(unsigned char ch_1, unsigned char ch_2){
    // if NP2 <= 0.5: 2*NP1*NP2 (multiply channel)
    // if NP2 > 0.5: 1 - 2*(1-NP1)*(1-NP2) (screen channel)

    float norm_c2 = norm(ch_2);

    if (norm_c2 <= 0.5){
        // multiply
        return channel_mult(ch_1, ch_2);

    }else{
        // norm_c2 > 0.5
        return channel_screen(ch_1, ch_2);
    }

}
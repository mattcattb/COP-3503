#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include "Image.h"

using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void task10();

//! move this outside of src directory!
int main(int argc, char** argv) {

    task1();
    task2();
    task3();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();

    return 0;
}


void task1(){
    // use mult blend to combine layer1 w pattern1
    Image layer1("input/layer1.tga");
    layer1.read();
    Image pattern1("input/pattern1.tga");
    pattern1.read();
    Image result = layer1*pattern1; // top*bot layer
    result.write("output/part1.tga");
}

void task2(){
    // Use the Subtract blending mode to combine layer2.tga (bottom layer) with car.tga (top layer)
    Image layer2_bottom("input/layer2.tga");
    Image car_top("input/car.tga");

    layer2_bottom.read();
    car_top.read();
    
    Image result = car_top - layer2_bottom;
    result.write("output/part2.tga");

}

void task3(){
    /*
    3. Use the Multiply blending mode to combine layer1.tga with pattern2.tga, and store the
    results temporarily, in memory. Load the image text.tga as bottom
    layer, combine with the previous result using the Screen blending mode.
    */
    Image layer1("input/layer1.tga");
    Image layer2("input/pattern2.tga");
    layer1.read();
    layer2.read();
    Image temp_img = layer1*layer2;

    Image text("input/text.tga");
    text.read();
    Image result = temp_img.screen(text); // temp_img top, text bottom
    result.write("output/part3.tga");
}

void task4(){
    /*
    4. Multiply layer2.tga with circles.tga, and store it. Load pattern2.tga and, using that
    as the bottom layer, combine it with the previous result using the Subtract blending mode.
    */
    Image layer2("input/layer2.tga");
    layer2.read();
    Image circles("input/circles.tga");
    circles.read();
    Image temp = layer2*circles;
    Image pattern2("input/pattern2.tga");   
    pattern2.read();
    Image result = temp - pattern2;
    result.write("output/part4.tga");
}

void task5(){
    // Combine layer1.tga as top with pattern1.tga using Overlay
    Image top_layer1("input/layer1.tga");
    Image bottom_pattern1("input/pattern1.tga");
    top_layer1.read();
    bottom_pattern1.read();

    Image result = top_layer1.overlay(bottom_pattern1);
    result.write("output/part5.tga");

}

void task6(){
    // Load car.tga and add 200 to the green channel.
    Image car("input/car.tga");
    car.read();
    Pixel g(0,200,0); // add this green pixel to each pixel in image
    Image result = car + g;
    result.write("output/part6.tga");

}

void task7(){
    
    // Load car.tga and scale (multiply) the red by 4, and blue channel by 0. 

    Image car("input/car.tga");
    car.read();

    float scale[] = {4,1,0}; // scale red by 4, green by 1 (none), blue by 0

    Image result = car*scale;
    result.write("output/part7.tga");

}

void task8(){
    /*
    8. Load car.tga and write each channel to a separate file: the red channel should be part8_r.tga,
    the green channel should be part8_g.tga, and the blue channel should be part8_b.tga. 
    If your red channel image appears all red, try writing [Red, Red, Red] instead of [Red, 0, 0] to the
    file—ditto for green and blue!) 
    */

    Image car("input/car.tga");
    car.read();

    Image red = car.get_red_channel();
    Image blue = car.get_blue_channel();
    Image green = car.get_green_channel();

    red.write("output/part8_r.tga");
    blue.write("output/part8_b.tga");
    green.write("output/part8_g.tga");

}

void task9(){
    /*    
    Load layer_red.tga, layer_green.tga and layer_blue.tga, combine into one file. 
    The data from layer_red.tga is the red channel of the new image, layer_green is green, 
    and layer_blue is blue.
    */

    Image red("input/layer_red.tga");
    Image green("input/layer_green.tga");
    Image blue("input/layer_blue.tga");

    red.read();
    green.read();
    blue.read();    

    Image entwined(red,green,blue);

    entwined.write("output/part9.tga");
}

void task10(){
    // Load text2.tga, and rotate it 180 degrees, flipping it upside down.
    
    Image text2("input/text2.tga");
    text2.read();
    Image result = text2.rotate_180();
    result.write("output/part10.tga");

}

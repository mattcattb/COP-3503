#pragma once

unsigned char channel_add(unsigned char ch_1, unsigned char ch_2);
unsigned char channel_sub(unsigned char ch_1, unsigned char ch_2);
unsigned char channel_mult(unsigned char ch_1, unsigned char ch_2);

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

unsigned char channel_screen(unsigned char ch1, unsigned char ch2){
    // 1 - [(1-NP1)*(1-NP2)]

    float norm_c1 = norm(ch1);
    unsigned char v1 = channel_sub(1.0, norm_c1); // (1-NP1)
    
    float norm_c2 = norm(ch2);
    unsigned char v2 = channel_sub(1.0, norm_c2);

    unsigned char v3 = channel_mult(v1,v2);
    
    unsigned char return_val = one_sub(1.0, v3); 

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

unsigned char channel_sub(float a, float b){

}

float norm(unsigned char ch){
    float val_1 = ((float)ch)/255; 
}

unsigned char channel_mult(unsigned char ch_1, unsigned char ch_2){
    // multiply 2 channels by normalization
    float val_1 = norm(ch_1);
    float val_2 = norm(ch_2);

    float val_3 = val_1 * val_2;
    int ch_3 = val_3*255 + 0.5f;

    return ((unsigned char)ch_3);
}

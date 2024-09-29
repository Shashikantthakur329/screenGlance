#include "Image.h"

Image::Image(unsigned char* arr, int width, int height){
    this -> arr = arr;
    this -> width = width;
    this -> height = height;
}


Image::Image(){
    //pass
}
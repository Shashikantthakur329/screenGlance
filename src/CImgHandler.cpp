#ifndef INCLUDE_STDLIB
#define INCLUDE_STDLIB
#include <iostream>
#include <string.h>
#include <cassert>
#endif

#define ASSERT(condition, message) \
   do { \
      assert(condition && #message); \
   } while (0)


#include "CImgHandler.h"

CImgHandler::CImgHandler(Image img, int x, int y):ImageHandler(img)
{
    this -> pic = cimg_library::CImg<unsigned char>(img.arr, img.width, img.height, x, y);
    this -> arr = arr;
    this -> img = img;
    this -> x = x;
    this -> y = y;
    this -> width = img.width;
    this -> height = img.height;
    this -> lengthOfArr = img.width * img.height;
}

void CImgHandler :: captureImage(Image img){
    int len = img.width * img.height;

    ASSERT(this -> lengthOfArr == len , \
    "Length of provided array(arr) is not equal to initialized image array");

    this -> pic = cimg_library::CImg<unsigned char>(img.arr, img.width, img.height, this -> x, this -> y);
    this -> registerPixel(img.arr, x, y);
}

void CImgHandler::saveImage(const char* filepath)
{
        this -> pic.save_png(filepath);
}

void CImgHandler::registerPixel(unsigned char* arr, int x, int y){
    int i = 0;
    for (int x = 0; x < this -> width; x++)
    {
        for (int y = 0; y < this -> height ; y++)
        {
            this -> pic(x,y,0) = arr[i * 3 + 0];
            this -> pic(x,y,1) = arr[i * 3 + 1];
            this -> pic(x,y,2) = arr[i * 3 + 2];
            i += 1;
        }
    }
    // this -> pic(x,y,0) = ((pixel >> 16) & (255));
    // this -> pic(x,y,1) = ((pixel >> 8) & (255));
    // this -> pic(x,y,2) = ((pixel) & (255));
}


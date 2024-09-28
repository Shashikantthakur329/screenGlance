#include "CImgHandler.h"

CImgHandler::CImgHandler(unsigned char *arr, int height, int width, int x, int y):ImageHandler(arr)
{
    this -> pic = cimg_library::CImg<unsigned char>(arr, width, height, x, y);
    this -> x = x;
    this -> y = y;
}

void CImgHandler :: captureImage(unsigned char* arr, int width, int height){
    this -> pic = cimg_library::CImg<unsigned char>(arr, width, height, this -> x, this -> y);
}

void CImgHandler::saveImage(const char* filepath)
{
        this -> pic.save_png(filepath);
}

void CImgHandler::registerPixel(unsigned long pixel, int x, int y){
        this -> pic(x,y,0) = ((pixel >> 16) & (255));
        this -> pic(x,y,1) = ((pixel >> 8) & (255));
        this -> pic(x,y,2) = ((pixel) & (255));
}
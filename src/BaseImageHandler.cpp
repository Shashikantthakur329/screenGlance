#ifndef BASE_HANDLER
#define BASE_HANDLER
#include "BaseImageHandler.h"
#endif

ImageHandler::ImageHandler(unsigned char* arr)
{
    this -> arr = arr;
}

void ImageHandler::captureImage(unsigned char* arr, int width, int height) {
    // Default or empty implementation
}

void ImageHandler::saveImage(const char* filepath) {
    // Default or empty implementation
}
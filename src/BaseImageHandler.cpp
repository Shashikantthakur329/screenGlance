#ifndef BASE_HANDLER
#define BASE_HANDLER
#include "BaseImageHandler.h"
#endif

#ifndef INCLUDE_IMAGE
#define INCLUDE_IMAGE
#include "Image.h"
#endif

ImageHandler::ImageHandler(Image img)
{
    this -> img = img;
}

void ImageHandler::captureImage(Image img) {
    // Default or empty implementation
}

void ImageHandler::saveImage(const char* filepath) {
    // Default or empty implementation
}

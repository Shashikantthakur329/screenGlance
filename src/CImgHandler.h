#ifndef BASE_HANDLER
#define BASE_HANDLER
#include "BaseImageHandler.h"
#endif

#ifndef CIMG_HANDLER
#define CIMG_HANDLER
#include "/home/toor/screenshot/CImg/CImg.h"

class CImgHandler : public ImageHandler{
    public:
    cimg_library::CImg<unsigned char> pic;
    int x, y;
    unsigned char* arr;

    /**
    * Initializes a Cimg<unsigned char>.
    *
    * @param arr Container whose values are summed.
    * @param height Container whose values are summed.
    * @param width Container whose values are summed.
    * @param x Container whose values are summed.
    * @param y Container whose values are summed.
    * @return sum of `values`, or 0.0 if `values` is empty.
    */

    CImgHandler(unsigned char *arr, int height, int width, int x, int y);
    void captureImage (unsigned char* arr, int height, int width) override;
    void registerPixel(unsigned long pixel, int x, int y);
    void saveImage(const char* filepath) override;
};

#endif
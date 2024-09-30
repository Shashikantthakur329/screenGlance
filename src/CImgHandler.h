#ifndef BASE_HANDLER
#define BASE_HANDLER
#include "BaseImageHandler.h"
#endif

#ifndef INCLUDE_IMAGE
#define INCLUDE_IMAGE
#include "Image.h"
#endif

#ifndef CIMG_HANDLER
#define CIMG_HANDLER
#include "/home/toor/screenshot/CImg/CImg.h"

class CImgHandler : public ImageHandler{
    public:
    cimg_library::CImg<unsigned char> pic;
    Image img;
    int x, y, width, height, lengthOfArr;
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

    CImgHandler(Image img, int x = 1, int y = 3);
    void captureImage (Image img) override;
    void registerPixel(unsigned char* arr, int x, int y);
    void saveImage(const char* filepath) override;
};

#endif
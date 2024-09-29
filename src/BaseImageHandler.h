#ifndef INCLUDE_IMAGE
#define INCLUDE_IMAGE
#include "Image.h"
#endif

#ifndef IMG_HANDLER
#define IMG_HANDLER

class ImageHandler{

    public:
    Image img;
    ImageHandler(Image img);
    virtual void captureImage (Image img);
    virtual void saveImage(const char* filepath);
};

#endif //#IMG_HANDLER
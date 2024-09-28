
#ifndef IMG_HANDLER
#define IMG_HANDLER

class ImageHandler{

    public:
    unsigned char* arr;
    ImageHandler(unsigned char* arr);
    virtual void captureImage(unsigned char* arr, int width, int height);
    virtual void saveImage(const char* filepath);
};

#endif //#IMG_HANDLER
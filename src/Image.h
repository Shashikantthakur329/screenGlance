/**
    @param arr image in one-dimensional array [{r,g,b}, ....] format
    @param width width of image
    @param height height of image
*/

class Image{
    public:
    unsigned char* arr;
    int width;
    int height;
    Image();
    Image(unsigned char* arr, int width, int height);
};
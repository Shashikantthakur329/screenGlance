#include "X11ImageGrabber.h"
#include "/home/toor/screenshot/CImg/CImg.h"
#include "CImgHandler.h"
#include "BaseImageHandler.h"

using namespace cimg_library;
void X11ImageGrabber::capture(double x1, double y1, double x2, double y2)    
{
    Display *display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);
    // std::cout<<"capture from X11";

    XWindowAttributes gwa;
    XGetWindowAttributes(display, root, &gwa);
    int width = gwa.width;
    int height = gwa.height;

    XImage *image = XGetImage(display, root, 0,0,width, height, AllPlanes, ZPixmap);

    unsigned char *array = new unsigned char[width * height * 3];
    // CImg<unsigned char> pic(array,width,height,1,3);
    CImgHandler pic(array,width,height,1,3);
    pic.captureImage(array,width,height);
    // CImgHandler a = CImgHandler(array, )
    int t = 0;
    for (int x = 0; x < width; x++)
    {
      for (int y = 0; y < height ; y++)
      {
        unsigned long pixel = XGetPixel(image,x,y);
        // array[(x + width * y) * 3] = ((pixel >> 16) & (255));
        // array[(x + width * y) * 3 + 1] = ((pixel >> 8) & (255));
        // array[(x + width * y) * 3 + 2] = ((pixel) & (255));
        pic.registerPixel(pixel, x, y);
        // pic(x,y,0) = ((pixel >> 16) & (255));
        // pic(x,y,1) = ((pixel >> 8) & (255));
        // pic(x,y,2) = ((pixel) & (255));
        // // array[(t)] = ((pixel >> 16) & (255));
        // array[(height * width  + t)] = ((pixel >> 8) & (255));
        // array[(height * width * 2  + t)] = ((pixel) & (255));
        // t++;
      }
    }

    // CImg<unsigned char> pic(array,width,height,1,3);
    pic.saveImage("blah.png");
}


// └─$ g++ main.cpp BaseGrabber.cpp X11ImageGrabber.cpp -lX11 -I/home/toor/screenshot/CImg -o main
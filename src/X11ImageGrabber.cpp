#include "X11ImageGrabber.h"
#include "/home/toor/screenshot/CImg/CImg.h"
// #include "CImgHandler.h"
#include "BaseImageHandler.h"
#include <math.h>

using namespace cimg_library;
Image X11ImageGrabber::capture(double x1, double y1, double x2, double y2)    
{
    Display *display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);

    XWindowAttributes gwa;
    XGetWindowAttributes(display, root, &gwa);
    int width = gwa.width;
    int height = gwa.height;
    XImage *image = XGetImage(display, root, 0, 0,width, height, AllPlanes, ZPixmap);

    width = abs(x2 - x1); height = abs(y2 - y1);
    unsigned char *array = new unsigned char[width * height * 3];

    x1 = std::min(x1, x2); x2 = std::max(x1, x2);
    y1 = std::min(y1, y2); y2 = std::max(y1, y2);
    
    int i = 0;
    for (int x = x1; x < x2; x++)
    {
      for (int y = y1; y < y2 ; y++)
      {
        unsigned long pixel = XGetPixel(image,x,y);

        array[i * 3 + 0] = ((pixel >> 16) & (255));
        array[i * 3 + 1] = ((pixel >> 8) & (255));
        array[i * 3 + 2] = ((pixel) & (255));
        i += 1;
        // pic(x,y,0) = ((pixel >> 16) & (255));
        // pic(x,y,1) = ((pixel >> 8) & (255));
        // pic(x,y,2) = ((pixel) & (255));
      }
    }

    Image img = Image(array, width, height);
    return img;
}


// └─$ g++ main.cpp BaseGrabber.cpp X11ImageGrabber.cpp -lX11 -I/home/toor/screenshot/CImg -o main

// g++ main.cpp X11ImageGrabber.cpp CImgHandler.cpp BaseGrabber.cpp BaseImageHandler.cpp -lX11 -I/home/toor/screenshot/CImg -o main
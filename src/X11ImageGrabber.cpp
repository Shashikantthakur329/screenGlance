#include "X11ImageGrabber.h"
#include "/home/toor/screenshot/CImg/CImg.h"
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
    CImg<unsigned char> pic(array,width,height,1,3);
    int t = 1;
    for (int x = 0; x < width; x++)
    {
      for (int y = 0; y < height ; y++)
      {
        unsigned long pixel = XGetPixel(image,x,y);
        array[(x + width * y) * 3] = ((pixel >> 16) & (255));
        array[(x + width * y) * 3 + 1] = ((pixel >> 8) & (255));
        array[(x + width * y) * 3 + 2] = ((pixel) & (255));
        pic(x,y,0) = array[(x + width * y) * 3];
        pic(x,y,1) = array[(x + width * y) * 3 + 1];
        pic(x,y,2) = array[(x + width * y) * 3 + 2];
      }
    }
    pic.save_png("blah.png");
}



#include "screenGlance.h"
#include <iostream>
#include <string.h>
#include <cassert>
#include "X11ImageGrabber.h"
#include "CImgHandler.h"
#include "./helper/SelectArea.h"

screenGlance::screenGlance(const char* str){
    this -> filename = str;
}
int screenGlance::takeScreenshot()
{
    SelectArea a; 
    Rectangle r = a.getArea();
    int x1 = r.x1;
    int y1 = r.y1;
    int x2 = r.x2;
    int y2 = r.y2;

    X11ImageGrabber x = X11ImageGrabber();
    Image image = x.capture(x1,y1,x2,y2); // need to capture provided region

    CImgHandler pic(image);
    pic.captureImage(image);
    pic.saveImage(this->filename);
    return 0;
}
// g++ drawRectangle.cpp -lX11 -o drawRectangle $(pkg-config --libs --cflags cairo)

// g++ main.cpp X11ImageGrabber.cpp CImgHandler.cpp BaseGrabber.cpp BaseImageHandler.cpp Image.cpp Rectangle.cpp ./helper/SelectArea.cpp -lX11 -I/home/toor/screenshot/CImg -o main

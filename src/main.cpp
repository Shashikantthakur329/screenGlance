// An app to take screenshot in linux
//
//
#ifndef INCLUDE_STDLIB
#define INCLUDE_STDLIB
#include <iostream>
#include <string.h>
#include <cassert>
#endif

#include "X11ImageGrabber.h"
#include "CImgHandler.h"

int main()
{
    X11ImageGrabber x = X11ImageGrabber();
    Image image = x.capture(0,0,0,0);
    CImgHandler pic(image,1,3);
    pic.captureImage(image);
    pic.saveImage("asd.png");
}


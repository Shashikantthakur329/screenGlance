#ifndef _BASEGRABBER
#define _BASEGRABBER
#include "BaseGrabber.h"
#endif

#ifndef INCLUDE_IMAGE
#define INCLUDE_IMAGE
#include "Image.h"
#endif

#include <iostream>

Image BaseGrabber::capture(double x1, double y1, double x2, double y2){
    std::cout<<"Capture called\n";
    Image imt = Image();
    return imt;
}

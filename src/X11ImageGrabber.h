
#ifndef INCLUDE_STDLIB
#define INCLUDE_STDLIB
#include <iostream>
#endif

#ifndef _BASEGRABBER
#define _BASEGRABBER
#include "BaseGrabber.h"
#endif

#ifndef INCLUDE_IMAGE
#define INCLUDE_IMAGE
#include "Image.h"
#endif

#ifndef X11_GRABBER
#define X11_GRABBER
#include <X11/Xlib.h>
#include <X11/Xutil.h>

class X11ImageGrabber : public BaseGrabber{
public:
   //need to handle x1, x2, x3, x4 in X11ImageGrabber.cpp
   Image capture(double x1, double y1, double x2, double y2) override;
};

#endif
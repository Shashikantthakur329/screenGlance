#ifndef INCLUDE_STDLIB
#define INCLUDE_STDLIB
#include <iostream>
#endif

#ifndef _BASEGRABBER
#define _BASEGRABBER
#include "BaseGrabber.h"
#endif

#ifndef X11_GRABBER
#define X11_GRABBER
#include <X11/Xlib.h>
#include <X11/Xutil.h>

class X11ImageGrabber : public BaseGrabber{
public:
    void capture(double x1, double y1, double x2, double y2) override;
};

#endif
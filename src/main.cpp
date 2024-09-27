// An app to take screenshot in linux
//
//
#ifndef INCLUDE_STDLIB
#define INCLUDE_STDLIB
#include <iostream>
#endif

#include "X11ImageGrabber.h"
int main()
{
    // ScreenGlance s = ScreenGlance();
    // s.capture(0,0,0,0);
    X11ImageGrabber x = X11ImageGrabber();
    x.capture(0,0,0,0);
}

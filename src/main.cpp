// An app to take screenshot in linux
//
//
#ifndef INCLUDE_STDLIB
#define INCLUDE_STDLIB
#include <iostream>
#include <string.h>
#endif

#include "X11ImageGrabber.h"
int main()
{
    X11ImageGrabber x = X11ImageGrabber();
    x.capture(0,0,0,0);
}


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
#include "./helper/SelectArea.h"
#include "screenGlance.h"

int main()
{
    const char* output = "../screenCap.png";
    screenGlance s(output);
    s.takeScreenshot();
}

// g++ drawRectangle.cpp -lX11 -o drawRectangle $(pkg-config --libs --cflags cairo)

// g++ main.cpp X11ImageGrabber.cpp CImgHandler.cpp BaseGrabber.cpp BaseImageHandler.cpp Image.cpp Rectangle.cpp ./helper/SelectArea.cpp -lX11 -I/home/toor/screenshot/CImg -o main
// g++ main.cpp X11ImageGrabber.cpp CImgHandler.cpp BaseGrabber.cpp BaseImageHandler.cpp Image.cpp Rectangle.cpp ./helper/SelectArea.cpp screenGlance.cpp $(pkg-config --libs --cflags cairo) -lX11 -I/home/toor/screenshot/CImg -o main


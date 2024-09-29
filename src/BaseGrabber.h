#ifndef INCLUDE_IMAGE
#define INCLUDE_IMAGE
#include "Image.h"
#endif

#ifndef SCREENGRAB_H
#define SCREENGRAB_H

class BaseGrabber{
public:
    virtual Image capture(double x1, double y1, double x2, double y2);
};

#endif // SCREENGRAB_H

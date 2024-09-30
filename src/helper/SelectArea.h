#ifndef SELECTED_AREA_H
#define SELECTED_AREA_H
#include "../Rectangle.h"

class SelectArea{
public:
    int x1, y1, x2, y2;
    Rectangle getArea();
};

#endif //SELECTED_AREA_H

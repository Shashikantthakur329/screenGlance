#include "Rectangle.h"
Rectangle::Rectangle(){
    this -> x1 = 0;
    this -> y1 = 0;
    this -> x2 = 0;
    this -> y2 = 0;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2){
    this -> x1 = x1;
    this -> y1 = y1;
    this -> x2 = x2;
    this -> y2 = y2;
}

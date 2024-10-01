#ifndef SCREENGLANCE_H
#define SCREENGLANCE_H
class screenGlance{
    const char* filename;
public:
    screenGlance(const char* str);
    int takeScreenshot();
};

#endif

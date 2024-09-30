#include <assert.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/X.h>
#include <X11/Xutil.h>
#include <cstdlib>
#include <cairo.h>
#include <cairo-xlib.h>

#include <chrono>
#include <thread>


void draw(cairo_t *cr, int x1, int y1, int x2, int y2) {
    cairo_set_source_rgba(cr, 1.0, 0.0, 0.0, 0.5);
    // printf("%d %d %d %d",x1, y1, x2, y2);
    cairo_rectangle(cr, x1, y1, x2, y2);
    cairo_fill(cr);
}

int abs(int x){
    return (x < 0 ? -1 * x : x);
}
int drawRect(int x1, int x2, int x3, int x4) {
    Display *d = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(d);
    int default_screen = XDefaultScreen(d);

    XWindowAttributes gwa;
    XGetWindowAttributes(d, root, &gwa);
    int width = gwa.width;
    int height = gwa.height;

    // these two lines are really all you need
    XSetWindowAttributes attrs;
    attrs.override_redirect = true;

    XVisualInfo vinfo;
    if (!XMatchVisualInfo(d, DefaultScreen(d), 32, TrueColor, &vinfo)) {
        printf("No visual found supporting 32 bit color, terminating\n");
        exit(EXIT_FAILURE);
    }
    // these next three lines add 32 bit depth, remove if you dont need and change the flags below
    attrs.colormap = XCreateColormap(d, root, vinfo.visual, AllocNone);
    attrs.background_pixel = 0;
    attrs.border_pixel = 0;

    // Window XCreateWindow(
    //     Display *display, Window parent,
    //     int x, int y, unsigned int width, unsigned int height, unsigned int border_width,
    //     int depth, unsigned int class, 
    //     Visual *visual,
    //     unsigned long valuemask, XSetWindowAttributes *attributes
    // );

    // while(true){
    // x1 += 10; x2 += 10;
    Window overlay = XCreateWindow(
        d, root,
        x1, x2, x3, x4, 0,
        vinfo.depth, InputOutput, 
        vinfo.visual,
        CWOverrideRedirect | CWColormap | CWBackPixel | CWBorderPixel, &attrs
    );

    XMapWindow(d, overlay);

    cairo_surface_t* surf = cairo_xlib_surface_create(d, overlay,
                                  vinfo.visual,
                                  width, height);
    cairo_t* cr = cairo_create(surf);

    draw(cr, 0, 0, (x3 - x1), (x4 - x2));
    XFlush(d);

    // show the window for 10 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(15));

    cairo_destroy(cr);
    cairo_surface_destroy(surf);
    XUnmapWindow(d, overlay);
    // }
    XCloseDisplay(d);

    return 0;
}


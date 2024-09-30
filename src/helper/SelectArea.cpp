#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../Rectangle.h"
#include "SelectArea.h"
#include "drawRectangle.cpp"
// #include <thread>
// #include <chrono>

Rectangle SelectArea::getArea(){
    int x=-1,y=-1;
    int xp=-1,yp=-1;
    int xr=-1,yr=-1;
    XEvent event;
    int button;
    int buttonP = -11;
    int buttonR;
    
    // Open the connection to the X server
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot connect to X server!\n");
        exit (EXIT_FAILURE);
    }

    Window root = XDefaultRootWindow(display);

    // Grab both ButtonPress and ButtonRelease events
    XGrabPointer(display, root, False, ButtonPressMask | ButtonReleaseMask, 
                 GrabModeAsync, GrabModeAsync, None, None, CurrentTime);

    // printf("before loop \n");

while (1) {
        // Query the current pointer position
        Window root_return, child_return;
        int root_x, root_y, win_x, win_y;
        unsigned int mask_return;

        if(xp != -1 or yp != -1){
            // Query pointer position before handling events
            if (XQueryPointer(display, root, &root_return, &child_return,
                            &root_x, &root_y, &win_x, &win_y, &mask_return)) {
                // printf("Current cursor position: (%d, %d)\n", root_x, root_y);
                drawRect(xp, yp, root_x, root_y);
            }

        }

        // std::this_thread::sleep_for(std::chrono::milliseconds(1));
        // Check if there are any pending events
        if (XPending(display)) {
            XNextEvent(display, &event);

            switch (event.type) {
                case ButtonPress:
                    // Handle different mouse buttons
                    switch (event.xbutton.button) {
                        case Button1: // Left click
                            // printf("Left click at %d %d \n", event.xbutton.x, event.xbutton.y);
                            if (buttonP == -11) {
                                xp = event.xbutton.x;
                                yp = event.xbutton.y;
                                buttonP = Button1;
                            }
                            break;

                        case Button3: // Right click
                            x = event.xbutton.x;
                            y = event.xbutton.y;
                            button = Button3;
                            break;

                        default:
                            break;
                    }
                    break;

                case ButtonRelease:
                    // Handle button release
                    switch (event.xbutton.button) {
                        case Button1: // Left click release
                            xr = event.xbutton.x;
                            yr = event.xbutton.y;
                            printf("Released at %d %d \n", xr, yr);
                            buttonR = Button1;
                            break;

                        case Button3: // Right click release
                            x = event.xbutton.x;
                            y = event.xbutton.y;
                            button = Button3;
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }

            // Break loop when both press and release coordinates are recorded
            if (xp >= 0 && yp >= 0 && xr >= 0 && yr >= 0) break;
        }
    }
    Rectangle r(xp, yp, xr, yr);
    // printf("Left click at %d %d \n", xp, yp);
    // printf("Released at %d %d \n", xr, yr);

    // Close the X display connection
    XCloseDisplay(display);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return r;    
}

/*                                   /$$                              
                                    | $$                              
  /$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$ 
 /$$__  $$ /$$__  $$| $$__  $$ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$
| $$  \__/| $$$$$$$$| $$  \ $$| $$  | $$| $$$$$$$$| $$  \__/| $$  \__/
| $$      | $$_____/| $$  | $$| $$  | $$| $$_____/| $$      | $$      
| $$      |  $$$$$$$| $$  | $$|  $$$$$$$|  $$$$$$$| $$      | $$      
|__/       \_______/|__/  |__/ \_______/ \_______/|__/      |__/      
                                                                     */ 



/*      COPYRIGHT enumer8 2023        */
/* ---------------------------------- */

// Standard headers + Xlib
#include <stdio.h>      // file writing and general I/O
#include <stdlib.h>     // memory allocation  
#include <errno.h>      // errors 
#include <string.h>     // string manipulation
#include <X11/Xlib.h>   // drawing a window and other UI
#include <stdbool.h>    // true/false checking

// Raymath and custom headers
#include "raymath.h"    // math functions
#include "camera.h"     // custom camera implementation
#include "obj.h"        // defined 3D primitives
#include "bmp.h"        // bitmap structures

// initialize dimensions 
#define SCR_W 800
#define SCR_H 600

// define what file path is to save resulting image - IN PROGRESS
const char *path_to_file = "output.bmp";
int width  = SCR_W;
int height = SCR_H;

// file write function goes here

int save_bitmap_output();

		       
// ====== MAIN LOOP =========================== //
int main()
{
    // Initialize the rendering window
    // Opens a connection to the X server, returns a Display pointer to the display being used
    Display* dpy = XOpenDisplay(NULL);  

    // Checks if the display was successfully opened
    // Returns an error code if the display could not be opened
    if (!dpy) { return -1; }

    // Gets the default screen number of the display
    int screen_num = DefaultScreen(dpy);  

    // Gets the root window of the default screen
    Window root = RootWindow(dpy, screen_num);  

    // Creates a simple window with the specified dimensions and properties
    Window win = XCreateSimpleWindow(dpy, root, 0, 0, SCR_W, SCR_H, 255, 255, 255);  

    // Selects the events to which the window should listen
    XSelectInput(dpy, win, ExposureMask | KeyPressMask);  

    // Maps the window to the screen
    XMapWindow(dpy, win);  

    XEvent ev;  // Declares an XEvent variable to store incoming events

    
    while (1) // Enters an infinite loop to wait for events
    {  
        // Gets the next event from the queue
        XNextEvent(dpy, &ev);  

        // Checks if the event is an Expose event (the window needs to be redrawn)
        if (ev.type == Expose) 
        {  
          
          // real-time rendering of objects goes HERE 	  

        } 
        else if (ev.type == KeyPress) // Checks if the event is a KeyPress event
        {  
            break;  // Breaks out of the event loop if a key is pressed
        }
    }

    // Closes the connection to the X server
    XCloseDisplay(dpy);  

   return 0;    
}
 

/*                                   /$$                              
                                    | $$                              
  /$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$ 
 /$$__  $$ /$$__  $$| $$__  $$ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$
| $$  \__/| $$$$$$$$| $$  \ $$| $$  | $$| $$$$$$$$| $$  \__/| $$  \__/
| $$      | $$_____/| $$  | $$| $$  | $$| $$_____/| $$      | $$      
| $$      |  $$$$$$$| $$  | $$|  $$$$$$$|  $$$$$$$| $$      | $$      
|__/       \_______/|__/  |__/ \_______/ \_______/|__/      |__/      
                                                                     */ 



//      COPYRIGHT enumer8 2023        //
// ---------------------------------- //
                                                                      
#include "raymath.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <X11/Xlib.h>


/* preprocessor macros to initialize dimensions */
#define SCR_W 800
#define SCR_H 600



int main() {


	// Initialize the rendering window
	
	Display* dpy = XOpenDisplay(NULL);  // Opens a connection to the X server, returning a Display pointer to the display being used

    if (!dpy) {  // Checks if the display was successfully opened
        return -1;  // Returns an error code if the display could not be opened
    }

    int screen_num = DefaultScreen(dpy);  // Gets the default screen number of the display
    Window root = RootWindow(dpy, screen_num);  // Gets the root window of the default screen

    Window win = XCreateSimpleWindow(dpy, root, 0, 0, SCR_W, SCR_H, 255, 255, 255);  // Creates a simple window with the specified dimensions and properties

    XSelectInput(dpy, win, ExposureMask | KeyPressMask);  // Selects the events to which the window should listen
    XMapWindow(dpy, win);  // Maps the window to the screen

    XEvent ev;  // Declares an XEvent variable to store incoming events
    while (1) {  // Enters an infinite loop to wait for events

        XNextEvent(dpy, &ev);  // Gets the next event from the queue
        if (ev.type == Expose) {  // Checks if the event is an Expose event (the window needs to be redrawn)
            
		// TODO Drawing code goes here

        } else if (ev.type == KeyPress) {  // Checks if the event is a KeyPress event
            break;  // Breaks out of the event loop if a key is pressed
        }
    }

    XCloseDisplay(dpy);  // Closes the connection to the X server


	// TODO Set up the camera
	
	// TODO Create 3D models
	
	// TODO Apply transformations and lighting
	
	// TODO Clean up resources
	
	// TODO Close the window 

   return 0;    
}
 

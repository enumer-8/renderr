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
           Display* dpy = XOpenDisplay(NULL);  // returns Display pointer to the display currently being used

        if (!dpy) {
                
                return -1;
        
        }




        int screen_num = DefaultScreen(dpy); // 
        Window root = RootWindow(dpy, screen_num);

        Window win = XCreateSimpleWindow(dpy, root, 0,0,1920,1080,0,0,0);

        XSelectInput(dpy, win, ExposureMask | KeyPressMask);
        XMapWindow(dpy, win);

        XEvent ev;
        while (1) {

                XNextEvent(dpy, &ev);
                if (ev.type == Expose){

                        // Draw here
                } else if (ev.type == KeyPress) {

                        break;
                }

        
        }

        XCloseDisplay(dpy);
        return 0;

}
 
    // Set up the camera
    
    // Create 3D models
    
    // Apply transformations and lighting
    
    // Call the rendering loop function
    
    // Clean up resources
    // Close the rendering window
    
    return 0;
}


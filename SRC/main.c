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
                                                                      
#include <X11/Xlib.h>

/* preprocessor macros to initialize dimensions */
#define SCR_W 800
#define SCR_H 600


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
            
		    // TODO Drawing code goes here

        } 
        else if (ev.type == KeyPress) // Checks if the event is a KeyPress event
        {  
            break;  // Breaks out of the event loop if a key is pressed
        }
    }

    // Closes the connection to the X server
    XCloseDisplay(dpy);  


	// TODO Set up the camera
	
	// TODO Create 3D models
	
	// TODO Apply transformations and lighting
	
	// TODO Clean up resources
	
	// TODO Close the window 

   return 0;    
}
 

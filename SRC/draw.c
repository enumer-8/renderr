#include <stdio.h>
#include "draw.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
void draw_line(Display* dpy, Window win, GC gc, Line* line){

  int x1 = (int) line.p1.x;
  int y1 = (int) line.p1.y;
  int x2 = (int) line.p2.x;
  int y2 = (int) line.p2.y;

  XSetForeground(dpy, gc, line.color);x

    XDrawLine(dpy, win, gc, x1, y1, x2, y2);

}

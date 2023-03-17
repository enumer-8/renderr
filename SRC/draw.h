#ifndef DRAW_H
#define DRAW_H

#include "obj.h"


void draw_line(Display* dpy, Window win, GC gc, Line* line);
void draw_tri(Display* dpy, Window win, GC gc, Tri* tri);
void draw_quad(Display* dpy, Window win, GC gc, Quad* quad);

#endif 

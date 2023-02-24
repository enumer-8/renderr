# renderr

Toy software renderer experiment using only standard headers, raymath.h and X11/Xlib. Updates may be sporadic as I work on this in my free time between
other projects. Subject to sudden and dramatic changes as events warrant.

## Objectives

- [x] Initialize a window
- [ ] Set up a camera
- [ ] Render and output primitives (cube, sphere)
- [ ] Apply transformations to the primitives
- [ ] Apply lighting
- [ ] Output results to image format (BMP, PPM)
--------------------------------------------------------------------
## Summary

renderr is a toy software renderer written in C99, using the “raymath.h” header from Raylib’s ‘rcore’ module, as well as X11/Xlib to initialize a window. I was originally exploring the possibility of creating windows using direct memory calls but that's a headache, and I want to avoid them for now. 
The purpose of this project is to experiment with the basics of graphics programming at a low-level, or at least low enough without having to resort 
to plain memory access, like Mode 13 in DOS. The scope of this project is simple - be able to generate and render primitives within a window using purely 
vector and matrix mathematics, and then output the resulting images to an image file such as BMP or PPM.




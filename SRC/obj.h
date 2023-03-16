#ifndef OBJ_H
#define OBJ_H

#include <stdio.h>
#include <stdint.h>
#include "raymath.h"

typedef struct Line {

  Vector2 x;
  Vector2 y;
  uint32_t color;

} Line;

typedef struct Tri {

  Vector3 v1;
  Vector3 v2;
  Vector3 v3;

} Tri;

typedef struct Quad {

  Vector4 v1;
  Vector4 v2;
  Vector4 v3;
  Vector4 v4;

} Quad; 

#endif

#ifndef OBJ_H
#define OBJ_H

#include <stdio.h>
#include <stdint.h>
#include "ray math.h"

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


extern Quad rect;
extern Tri tri;

#endif

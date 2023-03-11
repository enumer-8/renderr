#ifndef CAMERA_H
#define CAMERA_H

//this define is needed in only one file
//instead you can use the include everywhere
#define RAYMATH_IMPLEMENTATION
#include "raymath.h"

#define N_PLANE 0.1f;
#define F_PLANE 1000.0f;

typedef struct Camera {

	Vector3 pos;
	Vector3 target;
	Vector3 up;
	Matrix proj;
	Matrix view;
	int SCR_W;
	int SCR_H;

} Camera;

Camera* camera_create(Vector3 pos, Vector3 target, Vector3 up, float fov, int SCR_W, int SCR_H);

void camera_destroy(Camera* camera);

void camera_update_proj(Camera* camera, float fov, int SCR_W, int SCR_H, N_PLANE, F_PLANE);

void camera_pan(Camera* camera, Vector2 delta);

void camera_rotate(Camera* camera, Vector2 delta);

void camera_zoom(Camera* camera, float delta);

void camera_update_view(Camera* camera, Vector3 pos, Vector3 target, Vector3 up);

#endif

#ifndef CAMERA_H
#define CAMERA_H

#include "raymath.h"

typedef struct Camera {

	Vector3 pos;
	Vector3 target;
	Vector3 up;
	Matrix proj;
	Matrix view;

} Camera;

Camera* camera_create(Vector3 pos, Vector3 target, Vector3 up, float fov, int SCR_W, int SCR_H);
	void camera_destroy(Camera* camera);
	void camera_update_proj(Camera* camera, float fov, int SCR_W, int SCR_H);
	void camera_update_view(Camera* camera);
	void camera_pan(Camera* camera, Vector2 delta);
	void camera_rotate(Camera* camera, Vector2 delta);
	void camera_zoom(Camera* camera, float delta);


#endif

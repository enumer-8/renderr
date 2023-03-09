#include "camera.h"
#include <stdlib.h>

Camera* camera_create(Vector3 pos, Vector3 target, Vector3 up, float fov, int SCR_W, int SCR_H)
{
	Camera* camera = malloc(sizeof(Camera));
	camera->pos = pos;
	camera->target = target;
	camera->up = up;
	camera->proj = MatrixPerspective(fov * DEG2RAD, (float)SCR_W/ (float)SCR_H, 0.1f, 100.0f);
	camera->view = MatrixLookAt(camera->pos, camera->target, camera->up);

    return camera;
}	

void camera_destroy(Camera* camera) 
{
	free(camera);
}

void camera_update_proj(Camera* camera, float fov, int SCR_W, int SCR_H)
{
  float fov = 45.0f;
  float asp_ratio = (float)SCR_W / (float)SCR_H;

  float top = tan(fov * 0.5f * (PI / 180.0f));
  float bottom = -top;
  float right =  asp_ratio * top;
  float left = -right;

  float n_plane = 0.1f;
  float f_plane = 100.0f;
}

void camera_pan(Camera* camera, Vector2 delta)
{
    //TODO
}

void camera_rotate(Camera* camera, Vector2 delta)
{
    //TODO
}

void camera_zoom(Camera* camera, float delta)
{
    //TODO
}

void camera_update_view(Camera* camera, Vector3 pos, Vector3 target, Vector3 up) 
{
    camera->view = MatrixLookAt(pos, target, up);
}

#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include "camera.h"
#include "raymath.h"


// function that initializes camera
Camera* camera_create(Vector3 pos, Vector3 target, Vector3 up, float fov, int SCR_W, int SCR_H){

  Camera* camera = malloc(sizeof(Camera));     // allocate a memory region of size Camera
  if(camera  == NULL){                        // error handling
    if (errno == ENOMEM){
      printf("Error: failed to allocate memory.\n");
          }
    return -1;
	}
 
camera->pos = pos;
camera->target = target;
camera->up = up;
camera->proj = MatrixPerspective(fov * DEG2RAD, (float)SCR_W/ (float)SCR_H, N_PLANE, F_PLANE);
camera->view = MatrixLookAt(camera->pos, camera->target, camera->up);
camera->N_PLANE = N_PLANE;
camera->F_PLANE = F_PLANE;

 return camera;
}	

// function that frees camera memory
void camera_destroy(Camera* camera) 
{
	free(camera);
}

// function to update the projection matrix
void camera_update_proj(Camera* camera, float fov, int SCR_W, int SCR_H, N_PLANE, F_PLANE)
{
  camera->proj = (Matrix){0};                        // initialize matrix to 0
  
  float asp_ratio = (float)SCR_W / (float)SCR_H;     // setting aspect ratio -> divide screen width by height

  float top      = tan(fov * 0.5 * DEG2RAD);         // vertical field of view
  float bottom   = -top;
  float right    = top * asp_ratio;
  float left     = -right; 

  // MatrixFrustum
  float rl       = (float)(right - left);
  float tb       = (float)(top - bottom);
  float fn       = (float)(far - near);

  camera->proj.m0      = ((float)N_PLANE * 2.0f) / rl;          // scaling factor for x dimension of frustum
  camera->proj.m5      = ((float)N_PLANE * 2.0f) / tb;          // scaling factor for y dimension of frustum
  camera->proj.m8      = ((float)right + (float)left)/rl;       // translation factor for x dimension
  camera->proj.m9      = ((float)top + (float)bottom/tb);        // translation factor for y dimension
  camera->proj.m10     = -((float)F_PLANE + (float)N_PLANE)/fn; // scaling factor for z dimension      
  camera->proj.m11     = -1.0f;                                 // scaling factor for 'w' homogenous coordinate
  camera->proj.m14     = ((float)F_PLANE * (float)N_PLANE       // translation factor for z dimension of frustum

  return camera->proj;
}		     

void camera_pan(Camera* camera, Vector2 delta)
{
  Vector3 forward = (Vector3){
                     camera->target.x - camera->pos.x,
                     camera->target.y - camera->pos.y,
		     camera->target.z - camera->pos.z
                     };

  forward = Vector3Normalize(forward);

  Vector3 right = Vector3CrossProduct(forward, (Vector3)
				     {0.0f, 1.0f, 0.0f});
  right = Vector3Normalize(right);

  Vector3 up = Vector3CrossProduct(right, forward);
  up = Vector3Normalize(up);

  camera->pos.x += right.x * delta.x + up.x * delta.y;
  camera->pos.y += right.y * delta.x + up.y * delta.y;
  camera->pos.z += right.z * delta.x + up.z * delta.y;

  camera->target.x = camera->pos.x + forward.x;
  camera->target.y = camera->pos.y + forward.y;
  camera->target.z = camera->pos.z + forward.z;
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

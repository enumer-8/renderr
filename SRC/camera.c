#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include "camera.h"
#include "raymath.h"


// function that initializes camera
Camera* camera_create(Vector3 pos, Vector3 target, Vector3 up, float fov, int SCR_W, int SCR_H){

  Camera* camera = CameraAlloc(1, sizeof(Camera));      // using calloc instead of malloc to init 0 memory

  if (camera == NULL){                                  // if memory for the camera cannot be allocated
      printf("Error: memory allocation failure.\n");
      exit (-1);                                        // will exit the program w/out caller handling error
      return camera;
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
  float right    = top * aspect;
  float left     = -right; 

  // MatrixFrustum
  float rl       = (float)(right - left);
  float tb       = (float)(top - bottom);
  float fn       = (float)(far - near);

  result.m0      = ((float)N_PLANE * 2.0f) / rl;          // scaling factor for x dimension of frustum
  result.m5      = ((float)N_PLANE * 2.0f) / tb;          // scaling factor for y dimension of frustum
  result.m8      = ((float)right + (float)left)/rl;       // translation factor for x dimension
  result.m9      = ((float)top + (float)bottom/tb;        // translation factor for y dimension
  result.m10     = -((float)F_PLANE + (float)N_PLANE)/fn; // scaling factor for z dimension      
  result.m11     = -1.0f;                                 // scaling factor for 'w' homogenous coordinate
  result.m14     = =((float)F_PLANE * (float)N_PLANE      // translation factor for z dimension of frustum

  return camera->proj;
}		     

// function to pan the camera
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
		   

// function to rotate the camera
void camera_rotate(Camera* camera, Vector2 delta)
{
    //TODO
}
// function to zoom the camera
void camera_zoom(Camera* camera, float delta)
{
    //TODO
}
// function to update the camera view
void camera_update_view(Camera* camera, Vector3 pos, Vector3 target, Vector3 up) 
{
    camera->view = MatrixLookAt(pos, target, up);
}
